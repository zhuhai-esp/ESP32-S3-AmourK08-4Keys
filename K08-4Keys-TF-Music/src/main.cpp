#include "lgfx.h"
#include <Adafruit_NeoPixel.h>
#include <ArduinoOTA.h>
#include <Audio.h>
#include <HTTPClient.h>
#include <OneButton.h>
#include <map>

#define PIN_LED 48
#define PIN_RED_LED 47

#define PIN_I2S_SD 4
#define PIN_I2S_DOUT 5
#define PIN_I2S_BCLK 6
#define PIN_I2S_LRC 7

#define PIN_KEY_ADD 9
#define PIN_KEY_MINUS 21
#define PIN_KEY_MODE 14

#define PIN_SD_CS 10
#define PIN_SD_MOSI 11
#define PIN_SD_MISO 13
#define PIN_SD_SCK 12

using namespace std;

#define FONT16 &fonts::efontCN_16

typedef struct {
  String name;
  String path;
} SongItem;

static const char *WEEK_DAYS[] = {"日", "一", "二", "三", "四", "五", "六"};
Adafruit_NeoPixel pixels(4, PIN_LED, NEO_GRB + NEO_KHZ800);
LGFX tft;
LGFX_Sprite sp(&tft);
long check1s = 0, check10ms = 0, check300ms = 0;
long checkSaveMode = 0;
char buf[128] = {0};
Audio audio;
int curIndex = 0;
int curVolume = 6;
vector<SongItem *> songs;
std::map<u32_t, OneButton *> buttons;

void inline initTFTDevice() {
  tft.init();
  tft.setBrightness(60);
  tft.setFont(FONT16);
  tft.setColorDepth(8);
  tft.fillScreen(TFT_BLACK);
  sp.setFont(FONT16);
  sp.setColorDepth(8);
}

void inline showPlayProgress() {
  uint32_t act = audio.getAudioCurrentTime();
  uint32_t afd = audio.getAudioFileDuration();
  sp.createSprite(240, 32);
  sp.drawRoundRect(18, 0, 204, 10, 3, TFT_ORANGE);
  if (act > 0 && afd > 0) {
    int prog = act * 200 / afd;
    sp.fillRoundRect(20, 2, prog, 6, 2, TFT_GREEN);
    sprintf(buf, "%02i:%02d", (act / 60), (act % 60));
    sp.drawString(buf, 20, 16);
    sprintf(buf, "%02i:%02d", (afd / 60), (afd % 60));
    sp.drawRightString(buf, 220, 16);
  }
  sp.pushSprite(0, 50);
  sp.deleteSprite();
}

void playNext(int offset) {
  audio.stopSong();
  int total = songs.size();
  if (total > 0) {
    curIndex += offset;
    if (curIndex >= total) {
      curIndex %= total;
    } else if (curIndex < 0) {
      curIndex += total;
    }
    auto *song = songs[curIndex];
    auto *name = song->name.c_str();
    sprintf(buf, "%d.%s", curIndex + 1, name);
    sp.createSprite(240, 16);
    sp.drawCentreString(buf, 120, 0);
    sp.pushSprite(0, 20);
    sp.deleteSprite();
    audio.connecttoFS(SD, song->path.c_str());
  }
}

void nextVolume(int offset) {
  int vol = curVolume + offset;
  if (vol >= 0 && vol <= 21) {
    curVolume = vol;
    audio.setVolume(curVolume);
    sprintf(buf, "音量: %d", curVolume);
    sp.createSprite(120, 16);
    sp.drawString(buf, 8, 0);
    sp.pushSprite(0, 220);
    sp.deleteSprite();
  }
}

void inline initAudioDevice() {
  audio.setPinout(PIN_I2S_BCLK, PIN_I2S_LRC, PIN_I2S_DOUT);
  audio.setVolume(curVolume);
}

void inline initPixels() {
  pinMode(PIN_RED_LED, OUTPUT);
  digitalWrite(PIN_RED_LED, LOW);
  pixels.begin();
  pixels.setBrightness(40);
  pixels.clear();
  pixels.show();
}

void inline autoConfigWifi() {
  tft.println("Start WiFi Connect!");
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin();
  for (int i = 0; WiFi.status() != WL_CONNECTED && i < 100; i++) {
    delay(100);
  }
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.mode(WIFI_MODE_APSTA);
    WiFi.beginSmartConfig();
    tft.println("Use ESPTouch App!");
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
    }
    WiFi.stopSmartConfig();
    WiFi.mode(WIFI_MODE_STA);
  }
  tft.println("WiFi Connected, Please Wait...");
}

inline void showCurrentTime() {
  struct tm info;
  getLocalTime(&info);
  sprintf(buf, "%d年%d月%d日 星期%s", 1900 + info.tm_year, info.tm_mon + 1,
          info.tm_mday, WEEK_DAYS[info.tm_wday]);
  sp.createSprite(240, 16);
  sp.drawCentreString(buf, 116, 0);
  sp.pushSprite(0, 140);
  sp.deleteSprite();
  strftime(buf, 36, "%T", &info);
  sp.createSprite(240, 36);
  sp.drawCentreString(buf, 120, 0, &fonts::FreeSans24pt7b);
  sp.pushSprite(0, 160);
  sp.deleteSprite();
}

void inline startConfigTime() {
  const int timeZone = 8 * 3600;
  configTime(timeZone, 0, "ntp6.aliyun.com", "cn.ntp.org.cn", "ntp.ntsc.ac.cn");
  while (time(nullptr) < 8 * 3600 * 2) {
    delay(300);
  }
}

void inline setupOTAConfig() {
  ArduinoOTA.onStart([] {
    audio.stopSong();
    tft.setBrightness(200);
    tft.clear();
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawCentreString("软件升级", 120, 8, FONT16);
    tft.drawRoundRect(18, 158, 204, 10, 3, TFT_ORANGE);
    tft.drawCentreString("正在升级中，请勿断电...", 120, 190, FONT16);
  });
  ArduinoOTA.onProgress([](u32_t pro, u32_t total) {
    sprintf(buf, "升级进度: %d / %d", pro, total);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.drawCentreString(buf, 120, 120, FONT16);
    if (pro > 0 && total > 0) {
      int pros = pro * 200 / total;
      tft.fillRoundRect(20, 160, pros, 6, 2, TFT_WHITE);
    }
  });
  ArduinoOTA.onEnd([] {
    tft.clear();
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawCentreString("升级成功", 120, 60, FONT16);
    tft.drawCentreString("升级已完成，正在重启...", 120, 140, FONT16);
  });
  ArduinoOTA.onError([](ota_error_t e) {
    tft.clear();
    ESP.restart();
  });
  ArduinoOTA.begin();
  sprintf(buf, "%s", WiFi.localIP().toString().c_str());
  tft.println(buf);
  struct tm info;
  getLocalTime(&info);
  strftime(buf, 64, "%c", &info);
  tft.println(buf);
}

inline void showClientIP() {
  tft.clear();
  sprintf(buf, "%s", WiFi.localIP().toString().c_str());
  sp.createSprite(120, 16);
  sp.drawRightString(buf, 112, 0);
  sp.pushSprite(120, 220);
  sp.deleteSprite();
}

void onButtonClick(void *p) {
  checkSaveMode = 0;
  u32_t pin = (u32_t)p;
  switch (pin) {
  case PIN_KEY_MODE:
    audio.pauseResume();
    break;
  case PIN_KEY_ADD:
    playNext(1);
    break;
  case PIN_KEY_MINUS:
    playNext(-1);
    break;
  default:
    break;
  }
}

void onButtonDoubleClick(void *p) {
  u32_t pin = (u32_t)p;
  switch (pin) {
  case PIN_KEY_ADD:
    nextVolume(1);
    break;
  case PIN_KEY_MINUS:
    nextVolume(-1);
    break;
  default:
    break;
  }
}

void inline setupButtons() {
  u32_t btnPins[] = {PIN_KEY_ADD, PIN_KEY_MINUS, PIN_KEY_MODE};
  for (auto pin : btnPins) {
    auto *btn = new OneButton(pin);
    btn->attachClick(onButtonClick, (void *)pin);
    btn->attachDoubleClick(onButtonDoubleClick, (void *)pin);
    buttons.insert({pin, btn});
  }
}

void inline initSDCard() {
  pinMode(PIN_SD_CS, OUTPUT);
  digitalWrite(PIN_SD_CS, HIGH);
  SPI.begin(PIN_SD_SCK, PIN_SD_MISO, PIN_SD_MOSI);
  SD.begin(PIN_SD_CS);
}

void inline scanAllMusic() {
  auto allMb = SD.totalBytes() / (1024 * 1024);
  auto usedMb = SD.usedBytes() / (1024 * 1024);
  sprintf(buf, "TF卡已使用: %lluMB/%lluMB", usedMb, allMb);
  sp.createSprite(240, 16);
  sp.drawCentreString(buf, 110, 0);
  sp.pushSprite(0, 100);
  sp.deleteSprite();
  File root = SD.open("/", 0);
  if (root) {
    File mp3 = root.openNextFile();
    while (mp3) {
      String path = mp3.path();
      if (path.endsWith(".mp3")) {
        SongItem *song = new SongItem();
        song->name = mp3.name();
        song->path = path;
        songs.push_back(song);
      }
      mp3 = root.openNextFile();
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello ESP-S3!!");
  initTFTDevice();
  setupButtons();
  initPixels();
  initSDCard();
  initAudioDevice();
  autoConfigWifi();
  startConfigTime();
  setupOTAConfig();
  showClientIP();
  scanAllMusic();
  nextVolume(0);
  playNext(0);
}

void loop() {
  audio.loop();
  auto ms = millis();
  if (ms - check1s > 1000) {
    check1s = ms;
    ArduinoOTA.handle();
    showPlayProgress();
    digitalWrite(PIN_RED_LED, check1s % 2 ? LOW : HIGH);
  }
  if (ms - check300ms > 300) {
    check300ms = ms;
    showCurrentTime();
    uint16_t rc = rand() % 65536;
    pixels.fill(rc);
    pixels.show();
  }
  if (ms - check10ms >= 10) {
    check10ms = ms;
    for (auto it : buttons) {
      it.second->tick();
    }
  }
}

void audio_info(const char *info) { Serial.println(info); }

void audio_eof_stream(const char *info) { playNext(1); }