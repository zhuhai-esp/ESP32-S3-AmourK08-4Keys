#include "lgfx.h"
#include <Adafruit_AHTX0.h>

#define FONT16 &fonts::efontCN_16

Adafruit_AHTX0 aht;
LGFX tft;

void inline initTFTDevice() {
  tft.init();
  tft.setBrightness(60);
  tft.fillScreen(TFT_BLACK);
  tft.setFont(FONT16);
  tft.setColorDepth(8);
}

void setup() {
  Wire.setPins(1, 2);
  Serial.begin(115200);
  initTFTDevice();
  Serial.println("Adafruit AHT10/AHT20 demo!");
  if (!aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1)
      delay(10);
  }
  Serial.println("AHT10 or AHT20 found");
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  Serial.printf("AHT20传感器测量温度: %.2f摄氏度, 湿度: %.2f%%\n",
                temp.temperature, humidity.relative_humidity);
  tft.clear();
  tft.setCursor(0, 0);
  tft.printf("AHT20传感器测量温度: %.2f摄氏度, 湿度: %.2f%%\n",
             temp.temperature, humidity.relative_humidity);
  delay(2000);
}