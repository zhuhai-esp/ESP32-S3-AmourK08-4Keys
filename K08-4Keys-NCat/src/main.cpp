#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include <FFat.h>
#include <SD.h>
#include <SD_MMC.h>
#include <SPIFFS.h>
#include <esp_task_wdt.h>
#include <esp_wifi.h>

#include "hw_config.h"
#include <blectrl.h>

#define PIN_LED 48
#define PIN_RED_LED 47

extern "C" {
#include <nofrendo.h>
}

int16_t bg_color;
extern Arduino_TFT *gfx;
Adafruit_NeoPixel pixels(4, PIN_LED, NEO_GRB + NEO_KHZ800);
extern void display_begin();

void inline initPixels() {
  pinMode(PIN_RED_LED, OUTPUT);
  digitalWrite(PIN_RED_LED, LOW);
  pixels.begin();
  pixels.setBrightness(40);
  pixels.clear();
  pixels.show();
}

void inline loadNesGame() {
  FILESYSTEM_BEGIN
  delay(500);
  auto root = filesystem.open("/");
  char *argv[1];
  if (!root) {
    gfx->println("File system error!");
  } else {
    bool foundRom = false;
    File file = root.openNextFile();
    while (file) {
      if (file.isDirectory()) {
      } else {
        char *filename = (char *)file.name();
        int8_t len = strlen(filename);
        if (strstr(strlwr(filename + (len - 4)), ".nes")) {
          foundRom = true;
          char fullFilename[256];
          sprintf(fullFilename, "%s/%s", FSROOT, filename);
          Serial.println(fullFilename);
          argv[0] = fullFilename;
          break;
        }
      }
      file = root.openNextFile();
    }
    if (foundRom) {
      nofrendo_main(1, argv);
    } else {
      gfx->println("No nes found!");
    }
  }
}

void setup() {
  Serial.begin(115200);
  esp_wifi_deinit();
  TaskHandle_t idle_0 = xTaskGetIdleTaskHandleForCPU(0);
  esp_task_wdt_delete(idle_0);
  initPixels();
  display_begin();
  gfx->println("Wait for BLE Gamepad...");
  scanAndConnectServer();
  gfx->println("Loading ROM...");
  loadNesGame();
}

void loop() {}
