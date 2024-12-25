#include "SD2.hpp"

uint64_t ms100ms = 0, ms300ms = 0, ms2s = 0, ms10min = 0;

void onButtonClick(void *p) {
  u32_t pin = (u32_t)p;
  switch (pin) {
  case PIN_KEY_MODE:
    tellCurTime();
    break;
  case PIN_KEY_ADD:
    break;
  case PIN_KEY_MINUS:
    break;
  default:
    break;
  }
}

void onButtonDoubleClick(void *p) {
  u32_t pin = (u32_t)p;
  switch (pin) {
  case PIN_KEY_ADD:
    break;
  case PIN_KEY_MINUS:
    break;
  default:
    break;
  }
}

void run10minTask() { getCityWeater(); }

void run2sTask() {
  scrollBanner();
  updateAHT20Data();
}

void run300msTask() {
  showTimeDate();
  uint32_t c = random();
  pixels.rainbow(c % 0xFFFF);
  pixels.show();
}

void run100msTask() { animationOneFrame(); }

void setup() {
  Serial.begin(115200);
  initDisplay();
  initPixels();
  autoConfigWifi();
  startConfigTime();
  initTJpeg();
  animationOneFrame();
  loadInitWeather();
  initAHT20Wire();
  showTimeDate(1);
  setupButtons();
  initAudioDevice();
}

void loop() {
  audio.loop();
  auto cur = millis();
  if (cur - ms100ms > 100) {
    ms100ms = cur;
    run100msTask();
  }
  if (cur - ms300ms > 300) {
    ms300ms = cur;
    run300msTask();
  }
  if (cur - ms2s > 2000) {
    ms2s = cur;
    run2sTask();
  }
  if (cur - ms10min > 600000) {
    ms10min = cur;
    run10minTask();
  }
}