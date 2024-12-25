#ifndef __SD2_HPP__
#define __SD2_HPP__

#include "Animate/Animate.h"
#include "font/ZoloFont_20.h"
#include "font/timeClockFont.h" //字体库
#include "img/humidity.h"       //湿度图标
#include "img/temperature.h"    //温度图标
#include "weatherNum/weatherNum.h"
#include <Adafruit_AHTX0.h>
#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>
#include <Audio.h>
#include <HTTPClient.h>
#include <OneButton.h>
#include <TFT_eSPI.h>
#include <TJpg_Decoder.h>
#include <WiFiManager.h>
#include <map>

#define PIN_WS2812 48
#define PIN_I2C_SDA 1
#define PIN_I2C_SCL 2
#define PIN_RED_LED 47

#define PIN_I2S_SD 4
#define PIN_I2S_DOUT 5
#define PIN_I2S_BCLK 6
#define PIN_I2S_LRC 7

#define PIN_KEY_ADD 9
#define PIN_KEY_MINUS 21
#define PIN_KEY_MODE 14

#define NUM_LEDS 4

#define HTTP_UA                                                                \
  "Mozilla/5.0 (iPhone; CPU iPhone OS 11_0 like Mac OS X) "                    \
  "AppleWebKit/604.1.38 (KHTML, like Gecko) Version/11.0 Mobile/15A372 "       \
  "Safari/604.1"

#define TTS_LINK                                                               \
  "https://dds.dui.ai/runtime/v1/"                                             \
  "synthesize?text=%s&voiceId=%s&speed=1&volume=80&audioType=mp3"

#define FONT_COLOR_HOUR 0x6D9D
#define FONT_COLOR_MIN 0x7FC0
#define FONT_COLOR_SEC 0xEC1D

const String WEEK_DAYS[7] = {"日", "一", "二", "三", "四", "五", "六"};
String cityCode = "101280601";
Adafruit_NeoPixel pixels(NUM_LEDS, PIN_WS2812, NEO_GRB + NEO_KHZ800);
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite clk = TFT_eSprite(&tft);
uint16_t brightness = 8;
uint8_t rotation = 3;
WiFiManager wm;
char buf[512];
WiFiClient wificlient;
uint16_t bgColor = 0x0000;
int tempnum = 0;      // 温度百分比
int huminum = 0;      // 湿度百分比
int tempcol = 0xffff; // 温度显示颜色
int humicol = 0xffff; // 湿度显示颜色
String scrollText[8];
WeatherNum wrat;
int currentIndex = 0;
int Hour_sign = -1;
int Minute_sign = -1;
int Second_sign = -1;
int YDay_sign = -1;
struct tm timeNow;
const uint8_t *Animate_value;
uint32_t Animate_size;
Adafruit_AHTX0 aht;
std::map<u32_t, OneButton *> buttons;
Audio audio;
int curVolume = 8;

extern void onButtonClick(void *p);
extern void onButtonDoubleClick(void *p);

void inline startTextAudio(const char *txt) {
  sprintf(buf, TTS_LINK, txt, "xmamif");
  audio.connecttohost(buf);
}

void inline tellCurTime() {
  sprintf(buf, "现在是北京时间%02d:%02d", timeNow.tm_hour, timeNow.tm_min);
}

void inline initAudioDevice() {
  audio.setPinout(PIN_I2S_BCLK, PIN_I2S_LRC, PIN_I2S_DOUT);
  audio.setVolume(curVolume);
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

void inline initAHT20Wire() {
  Wire.setPins(PIN_I2C_SDA, PIN_I2C_SCL);
  if (!aht.begin()) {
    Serial.println("Could not find AHT20?");
  }
}

void inline updateAHT20Data() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  sprintf(buf, "AHT: %.2f℃", temp.temperature);
  scrollText[6] = buf;
  sprintf(buf, "AHT: %.2f%%", humidity.relative_humidity);
  scrollText[7] = buf;
}

void inline tempWin() {
  clk.setColorDepth(8);
  clk.createSprite(52, 6); // 创建窗口
  clk.fillSprite(0x0000);  // 填充率
  clk.drawRoundRect(0, 0, 52, 6, 3, 0xFFFF);
  clk.fillRoundRect(1, 1, tempnum, 4, 2, tempcol); // 实心圆角矩形
  clk.pushSprite(45, 192);                         // 窗口位置
  clk.deleteSprite();
}

void inline humidityWin() {
  clk.setColorDepth(8);
  huminum = huminum / 2;
  clk.createSprite(52, 6); // 创建窗口
  clk.fillSprite(0x0000);  // 填充率
  clk.drawRoundRect(0, 0, 52, 6, 3, 0xFFFF);
  clk.fillRoundRect(1, 1, huminum, 4, 2, humicol); // 实心圆角矩形
  clk.pushSprite(45, 222);                         // 窗口位置
  clk.deleteSprite();
}

void inline parseWeatherData(String *cityDZ, String *dataSK, String *dataFC) {
  JsonDocument doc;
  deserializeJson(doc, *dataSK);
  JsonObject sk = doc.as<JsonObject>();
  clk.setColorDepth(8);
  clk.loadFont(ZoloFont_20);
  clk.createSprite(58, 24);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(sk["temp"].as<String>() + "℃", 28, 13);
  clk.pushSprite(100, 184);
  clk.deleteSprite();
  tempnum = sk["temp"].as<int>();
  tempnum = tempnum + 10;
  if (tempnum < 10)
    tempcol = 0x00FF;
  else if (tempnum < 28)
    tempcol = 0x0AFF;
  else if (tempnum < 34)
    tempcol = 0x0F0F;
  else if (tempnum < 41)
    tempcol = 0xFF0F;
  else if (tempnum < 49)
    tempcol = 0xF00F;
  else {
    tempcol = 0xF00F;
    tempnum = 50;
  }
  tempWin();
  clk.createSprite(58, 24);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(sk["SD"].as<String>(), 28, 13);
  clk.pushSprite(100, 214);
  clk.deleteSprite();
  huminum = atoi((sk["SD"].as<String>()).substring(0, 2).c_str());
  if (huminum > 90)
    humicol = 0x00FF;
  else if (huminum > 70)
    humicol = 0x0AFF;
  else if (huminum > 40)
    humicol = 0x0F0F;
  else if (huminum > 20)
    humicol = 0xFF0F;
  else
    humicol = 0xF00F;
  humidityWin();

  // 城市名称
  clk.createSprite(94, 30);
  clk.fillSprite(bgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_WHITE, bgColor);
  clk.drawString(sk["cityname"].as<String>(), 44, 16);
  clk.pushSprite(15, 15);
  clk.deleteSprite();

  // PM2.5空气指数
  uint16_t pm25BgColor = tft.color565(156, 202, 127); // 优
  String aqiTxt = "优";
  int pm25V = sk["aqi"];
  if (pm25V > 200) {
    pm25BgColor = tft.color565(136, 11, 32); // 重度
    aqiTxt = "重度";
  } else if (pm25V > 150) {
    pm25BgColor = tft.color565(186, 55, 121); // 中度
    aqiTxt = "中度";
  } else if (pm25V > 100) {
    pm25BgColor = tft.color565(242, 159, 57); // 轻
    aqiTxt = "轻度";
  } else if (pm25V > 50) {
    pm25BgColor = tft.color565(247, 219, 100); // 良
    aqiTxt = "良";
  }
  clk.createSprite(56, 24);
  clk.fillSprite(bgColor);
  clk.fillRoundRect(0, 0, 50, 24, 4, pm25BgColor);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(0x0000);
  clk.drawString(aqiTxt, 25, 13);
  clk.pushSprite(104, 18);
  clk.deleteSprite();
  clk.unloadFont();

  scrollText[0] = "天气 " + sk["weather"].as<String>();
  scrollText[1] = "空气 " + aqiTxt;
  scrollText[2] = "风向 " + sk["WD"].as<String>() + sk["WS"].as<String>();

  auto cond = atoi((sk["weathercode"].as<String>()).substring(1, 3).c_str());
  wrat.printfweather(170, 15, cond);

  deserializeJson(doc, *cityDZ);
  JsonObject dz = doc.as<JsonObject>();
  scrollText[3] = dz["weather"].as<String>();

  deserializeJson(doc, *dataFC);
  JsonObject fc = doc.as<JsonObject>();

  scrollText[4] = fc["fd"].as<String>() + "℃ - " + fc["fc"].as<String>() + "℃";
  scrollText[5] = WiFi.localIP().toString();
}

void inline getCityWeater() {
  String URL = "http://d1.weather.com.cn/weather_index/" + cityCode +
               ".html?_=" + String(millis());
  HTTPClient httpClient;
  httpClient.begin(wificlient, URL);
  httpClient.setUserAgent(HTTP_UA);
  httpClient.addHeader("Referer", "http://www.weather.com.cn/");
  int httpCode = httpClient.GET();
  if (httpCode == HTTP_CODE_OK) {
    String str = httpClient.getString();
    int indexStart = str.indexOf("weatherinfo\":");
    int indexEnd = str.indexOf("};var alarmDZ");
    String jsonCityDZ = str.substring(indexStart + 13, indexEnd);
    indexStart = str.indexOf("dataSK =");
    indexEnd = str.indexOf(";var dataZS");
    String jsonDataSK = str.substring(indexStart + 8, indexEnd);
    indexStart = str.indexOf("\"f\":[");
    indexEnd = str.indexOf(",{\"fa");
    String jsonFC = str.substring(indexStart + 5, indexEnd);
    parseWeatherData(&jsonCityDZ, &jsonDataSK, &jsonFC);
  } else {
    Serial.println("请求城市天气错误：");
    Serial.print(httpCode);
  }
  httpClient.end();
}

void inline getCityCode() {
  String URL = "http://wgeo.weather.com.cn/ip/?_=" + String(millis());
  HTTPClient httpClient;
  httpClient.begin(wificlient, URL);
  httpClient.setUserAgent(HTTP_UA);
  httpClient.addHeader("Referer", "http://www.weather.com.cn/");
  int httpCode = httpClient.GET();
  if (httpCode == HTTP_CODE_OK) {
    String str = httpClient.getString();
    int aa = str.indexOf("id=");
    if (aa > -1) {
      cityCode = str.substring(aa + 4, aa + 4 + 9);
      Serial.println(cityCode);
      getCityWeater();
    } else {
      Serial.println("获取城市代码失败");
    }
  } else {
    Serial.println("请求城市代码错误：");
    Serial.println(httpCode);
  }
  httpClient.end();
}

bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bpm) {
  if (y >= tft.height())
    return 0;
  tft.pushImage(x, y, w, h, bpm);
  return 1;
}

void inline initTJpeg() {
  TJpgDec.setJpgScale(1);
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);
}

void inline autoConfigWifi() {
  wm.setAPCallback([](WiFiManager *_wm) {
    tft.loadFont(ZoloFont_20);
    tft.println("WiFi Failed!");
    tft.println("Please Connect AP:");
    tft.setTextColor(TFT_GREEN);
    tft.println(_wm->getConfigPortalSSID().c_str());
    tft.setTextColor(TFT_WHITE);
    tft.println("\nThen Open Link:");
    tft.setTextColor(TFT_GREEN);
    tft.printf("http://%s\n", WiFi.softAPIP().toString().c_str());
    tft.setTextColor(TFT_WHITE);
    tft.unloadFont();
  });
  wm.setConfigPortalTimeout(180);
  wm.setConfigPortalTimeoutCallback([]() { ESP.restart(); });
  auto res = wm.autoConnect();
  if (!res) {
    ESP.restart();
  }
  tft.loadFont(ZoloFont_20);
  tft.println("WiFi Connected!");
  sprintf(buf, "IP: %s", WiFi.localIP().toString().c_str());
  tft.println(buf);
  tft.unloadFont();
}

void inline startConfigTime() {
  tft.loadFont(ZoloFont_20);
  tft.println("Start Config Time!");
  tft.unloadFont();
  const int timeZone = 8 * 3600;
  configTime(timeZone, 0, "ntp6.aliyun.com", "cn.ntp.org.cn", "ntp.ntsc.ac.cn");
  while (time(nullptr) < 8 * 3600 * 2) {
    delay(300);
  }
  delay(1000);
}

void inline initPixels() {
  pixels.begin();
  pixels.setBrightness(80);
  pixels.clear();
  pixels.show();
}

void inline initDisplay() {
  tft.begin();
  tft.invertDisplay(1);
  tft.setRotation(rotation);
  tft.fillScreen(0x0000);
  pinMode(TFT_BL, OUTPUT);
  analogWriteResolution(10);
  analogWriteFrequency(25000);
  analogWrite(TFT_BL, 1023 - (brightness * 10));
  tft.setCursor(0, 4);
  tft.setTextColor(TFT_WHITE);
}

void inline loadInitWeather() {
  tft.fillScreen(TFT_BLACK);
  TJpgDec.drawJpg(15, 183, temperature, sizeof(temperature));
  TJpgDec.drawJpg(15, 213, humidity, sizeof(humidity));
  if (cityCode.isEmpty()) {
    getCityCode();
  } else {
    getCityWeater();
  }
}

void scrollBanner() {
  if (scrollText[currentIndex]) {
    clk.setColorDepth(8);
    clk.loadFont(ZoloFont_20);
    clk.createSprite(150, 30);
    clk.fillSprite(bgColor);
    clk.setTextWrap(false);
    clk.setTextDatum(CC_DATUM);
    clk.setTextColor(TFT_WHITE, bgColor);
    clk.drawString(scrollText[currentIndex], 74, 16);
    clk.pushSprite(10, 45);
    clk.deleteSprite();
    clk.unloadFont();
    auto len = (sizeof(scrollText) / sizeof(scrollText[0]));
    currentIndex = (currentIndex + 1) % len;
  }
}

void drawLineFont(uint32_t _x, uint32_t _y, uint32_t _num, uint32_t _size,
                  uint32_t c) {
  uint32_t fontSize;
  const LineAtom *fontOne;
  if (_size == 1) {
    fontOne = smallLineFont[_num];
    fontSize = smallLineFont_size[_num];
    tft.fillRect(_x, _y, 9, 14, TFT_BLACK);
  } else if (_size == 2) {
    fontOne = middleLineFont[_num];
    fontSize = middleLineFont_size[_num];
    tft.fillRect(_x, _y, 18, 30, TFT_BLACK);
  } else if (_size == 3) {
    fontOne = largeLineFont[_num];
    fontSize = largeLineFont_size[_num];
    tft.fillRect(_x, _y, 36, 60, TFT_BLACK);
  } else
    return;
  for (uint32_t i = 0; i < fontSize; i++) {
    tft.drawFastHLine(fontOne[i].xValue + _x, fontOne[i].yValue + _y,
                      fontOne[i].lValue, c);
  }
}

void showTimeDate(uint8_t force = 0) {
  time_t now = time(nullptr);
  localtime_r(&now, &timeNow);
  auto now_hour = timeNow.tm_hour;  // 获取小时
  auto now_minute = timeNow.tm_min; // 获取分钟
  auto now_second = timeNow.tm_sec; // 获取秒针
  auto yDay = timeNow.tm_yday;
  uint32_t timeY = 82;
  if (now_hour / 10 != Hour_sign / 10 || (force == 1)) {
    drawLineFont(20, timeY, now_hour / 10, 3, FONT_COLOR_HOUR);
  }
  if (now_hour % 10 != Hour_sign % 10 || (force == 1)) {
    drawLineFont(60, timeY, now_hour % 10, 3, FONT_COLOR_HOUR);
  }
  Hour_sign = now_hour;
  if ((now_minute / 10 != Minute_sign / 10) || (force == 1)) {
    drawLineFont(101, timeY, now_minute / 10, 3, FONT_COLOR_MIN);
  }
  if ((now_minute % 10 != Minute_sign % 10) || (force == 1)) {
    drawLineFont(141, timeY, now_minute % 10, 3, FONT_COLOR_MIN);
  }
  Minute_sign = now_minute;
  if ((now_second / 10 != Second_sign / 10) || (force == 1)) {
    drawLineFont(182, timeY + 30, now_second / 10, 2, FONT_COLOR_SEC);
  }
  if ((now_second % 10 != Second_sign % 10) || (force == 1)) {
    drawLineFont(202, timeY + 30, now_second % 10, 2, FONT_COLOR_SEC);
  }
  Second_sign = now_second;
  if (yDay != YDay_sign || (force == 1)) {
    YDay_sign = yDay;
    clk.setColorDepth(8);
    clk.loadFont(ZoloFont_20);
    clk.createSprite(160, 30);
    clk.fillSprite(bgColor);
    clk.setTextDatum(CC_DATUM);
    clk.setTextColor(TFT_WHITE, bgColor);
    auto *we = WEEK_DAYS[timeNow.tm_wday].c_str();
    sprintf(buf, "%02d月%02d日 周%s", timeNow.tm_mon + 1, timeNow.tm_mday, we);
    clk.drawString(buf, 80, 15);
    clk.pushSprite(0, 150);
    clk.deleteSprite();
    clk.unloadFont();
  }
}

inline void animationOneFrame() {
  imgAnim(&Animate_value, &Animate_size);
  TJpgDec.drawJpg(160, 160, Animate_value, Animate_size);
}

#endif