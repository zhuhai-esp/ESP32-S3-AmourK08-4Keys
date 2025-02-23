#include <TFT_eSPI.h>
#include <driver/i2s.h>
#include <esp_system.h>

TFT_eSPI tft = TFT_eSPI();

// 定义麦克风和扬声器的I2S引脚
#define I2S_BCLK_MIC 39
#define I2S_LRC_MIC 41
#define I2S_DIN_MIC 40

#define I2S_BCLK_SPK 6
#define I2S_LRC_SPK 7
#define I2S_DOUT_SPK 5
#define I2S_SD_SPK 4

// 定义音频参数
#define SAMPLE_RATE 16000
#define BUFFER_SIZE (1024 * 1024 * 2) // 缓冲区总大小，单位为字节
#define FRAME_SIZE 1024 * 2           // 每帧的采样点数
#define VAD_THRESHOLD 40              // 语音活动检测阈值
#define SILENCE_FRAME_COUNT 10        // 连续静默帧数阈值（160帧 * 10ms ≈ 1秒）
#define PITCH_FACTOR 1.5              // 音调提高因子

// 音频缓冲区
void *audioBuffer;
void *processedBuffer;
char buf[256] = {0};

void displayInit() {
  tft.begin();
  tft.setRotation(3);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(&FreeMonoOblique9pt7b);
}

void setup() {
  Serial.begin(115200);
  displayInit();
  audioBuffer = ps_malloc(BUFFER_SIZE);
  processedBuffer = ps_malloc(BUFFER_SIZE);

  pinMode(I2S_SD_SPK, OUTPUT);
  digitalWrite(I2S_SD_SPK, LOW);
  // 配置麦克风的I2S
  i2s_config_t micConfig = {.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
                            .sample_rate = SAMPLE_RATE,
                            .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
                            .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
                            .communication_format = I2S_COMM_FORMAT_STAND_I2S,
                            .intr_alloc_flags = 0,
                            .dma_buf_count = 8,
                            .dma_buf_len = 64,
                            .use_apll = false};
  i2s_pin_config_t micPinConfig = {.bck_io_num = I2S_BCLK_MIC,
                                   .ws_io_num = I2S_LRC_MIC,
                                   .data_out_num = I2S_PIN_NO_CHANGE,
                                   .data_in_num = I2S_DIN_MIC};
  i2s_driver_install(I2S_NUM_0, &micConfig, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &micPinConfig);

  // 配置扬声器的I2S
  i2s_config_t spkConfig = {.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
                            .sample_rate = SAMPLE_RATE,
                            .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
                            .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
                            .communication_format = I2S_COMM_FORMAT_STAND_I2S,
                            .intr_alloc_flags = 0,
                            .dma_buf_count = 8,
                            .dma_buf_len = 64,
                            .use_apll = false};
  i2s_pin_config_t spkPinConfig = {.bck_io_num = I2S_BCLK_SPK,
                                   .ws_io_num = I2S_LRC_SPK,
                                   .data_out_num = I2S_DOUT_SPK,
                                   .data_in_num = I2S_PIN_NO_CHANGE};
  i2s_driver_install(I2S_NUM_1, &spkConfig, 0, NULL);
  i2s_set_pin(I2S_NUM_1, &spkPinConfig);
}

bool isVoiceActive(int16_t *data, size_t sampleCount, int threshold) {
  uint32_t energy = 0;
  for (size_t i = 0; i < sampleCount; i++) {
    energy += abs(data[i]);
  }
  sprintf(buf, "[%u] [%d]", energy, threshold * sampleCount);
  tft.drawString(buf, 0, 20, 1);
  return energy > threshold * sampleCount;
}

void pitchShift(int16_t *input, int16_t *output, size_t sampleCount,
                float pitchFactor) {
  size_t newSampleCount = (size_t)(sampleCount / pitchFactor);
  if (newSampleCount > BUFFER_SIZE / sizeof(int16_t)) {
    newSampleCount = BUFFER_SIZE / sizeof(int16_t);
  }

  for (size_t i = 0; i < newSampleCount; i++) {
    float index = i * pitchFactor;
    size_t lowerIndex = (size_t)index;
    float frac = index - lowerIndex;
    if (lowerIndex + 1 < sampleCount) {
      output[i] = (int16_t)(input[lowerIndex] * (1 - frac) +
                            input[lowerIndex + 1] * frac);
    } else {
      output[i] = input[lowerIndex];
    }
  }

  for (size_t i = newSampleCount; i < sampleCount; i++) {
    output[i] = 0;
  }
}

void loop() {
  size_t totalBytesRead = 0;
  bool recording = true;
  uint32_t silenceFrameCount = 0;
  uint32_t validFrameCount = 0;
  uint32_t lastVoiceTime = 0;

  tft.drawString("Recording...", 0, 0, 1);
  while (recording) {
    size_t bytesRead;
    i2s_read(I2S_NUM_0, audioBuffer + totalBytesRead,
             FRAME_SIZE * sizeof(int16_t), &bytesRead, portMAX_DELAY);
    int16_t *audioData = (int16_t *)(audioBuffer + totalBytesRead);
    size_t sampleCount = bytesRead / sizeof(int16_t);

    if (isVoiceActive(audioData, sampleCount, VAD_THRESHOLD)) {
      silenceFrameCount = 0;
      lastVoiceTime = millis();
      totalBytesRead += bytesRead;
      validFrameCount += 1;
    } else {
      if (validFrameCount > 0) {
        totalBytesRead += bytesRead;
        if (silenceFrameCount >= SILENCE_FRAME_COUNT) {
          recording = false;
        }
      }
      silenceFrameCount++;
    }
    if (totalBytesRead >= BUFFER_SIZE) {
      recording = false;
    }
    delay(10);
  }

  size_t processedSampleCount =
      (size_t)(totalBytesRead / sizeof(int16_t) / PITCH_FACTOR);
  pitchShift((int16_t *)audioBuffer, (int16_t *)processedBuffer,
             totalBytesRead / sizeof(int16_t), PITCH_FACTOR);

  tft.drawString("Playing...", 0, 0, 1);
  size_t bytesWritten;
  digitalWrite(I2S_SD_SPK, HIGH);
  i2s_write(I2S_NUM_1, processedBuffer, processedSampleCount * sizeof(int16_t),
            &bytesWritten, portMAX_DELAY);
  digitalWrite(I2S_SD_SPK, LOW);
  delay(100);
}
