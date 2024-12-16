#include "lgfx.h"
#include <Adafruit_NeoPixel.h>
#include <ArduinoOTA.h>
#include <Audio.h>
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

long check1s = 0, check10ms = 0, check300ms = 0;
char buf[128] = {0};
Audio audio;

void inline initTFCard() {
  pinMode(PIN_SD_CS, OUTPUT);
  digitalWrite(PIN_SD_CS, HIGH);
  SPI.begin(PIN_SD_SCK, PIN_SD_MISO, PIN_SD_MOSI);
  SPI.setFrequency(1000000);
  Serial.begin(115200);
  SD.begin(PIN_SD_CS);
}

void inline initAudioDevice() {
  pinMode(PIN_I2S_SD, OUTPUT);
  digitalWrite(PIN_I2S_SD, HIGH);
  audio.setPinout(PIN_I2S_BCLK, PIN_I2S_LRC, PIN_I2S_DOUT);
  audio.setVolume(10);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello ESP32-S3!!");
  initTFCard();
  initAudioDevice();
  audio.connecttoFS(SD, "/music/1.mp3");
}

void loop() {
  audio.loop();
  auto ms = millis();
  if (ms - check1s > 1000) {
    check1s = ms;
  }
  if (ms - check300ms > 300) {
    check300ms = ms;
  }
  if (ms - check10ms >= 10) {
    check10ms = ms;
  }
}

// optional
void audio_info(const char *info) {
  Serial.print("info        ");
  Serial.println(info);
}
void audio_id3data(const char *info) { // id3 metadata
  Serial.print("id3data     ");
  Serial.println(info);
}
void audio_eof_mp3(const char *info) { // end of file
  Serial.print("eof_mp3     ");
  Serial.println(info);
}
void audio_showstation(const char *info) {
  Serial.print("station     ");
  Serial.println(info);
}
void audio_showstreamtitle(const char *info) {
  Serial.print("streamtitle ");
  Serial.println(info);
}
void audio_bitrate(const char *info) {
  Serial.print("bitrate     ");
  Serial.println(info);
}
void audio_commercial(const char *info) { // duration in sec
  Serial.print("commercial  ");
  Serial.println(info);
}
void audio_icyurl(const char *info) { // homepage
  Serial.print("icyurl      ");
  Serial.println(info);
}
void audio_lasthost(const char *info) { // stream URL played
  Serial.print("lasthost    ");
  Serial.println(info);
}