#include "lgfx.h"
#include <Adafruit_AHTX0.h>
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

#define PIN_I2C_SDA 1
#define PIN_I2C_SCL 2

using namespace std;

#define FONT16 &fonts::efontCN_16
#define FM_URL "http://lhttp.qtfm.cn/live/%d/64k.mp3"

typedef struct {
  u32_t id;
  String name;
} RadioItem;

static const char *WEEK_DAYS[] = {"日", "一", "二", "三", "四", "五", "六"};
long check1s = 0, check10ms = 0, check300ms = 0, check60s = 0;
char buf[128] = {0};
LGFX tft;
LGFX_Sprite sp(&tft);
Audio audio;
int curIndex = 0;
int curVolume = 6;
Adafruit_NeoPixel pixels(4, PIN_LED, NEO_GRB + NEO_KHZ800);
Adafruit_AHTX0 aht;
std::map<u32_t, OneButton *> buttons;
std::vector<RadioItem> radios = {
    {4915, "清晨音乐台"},
    {1223, "怀旧好声音"},
    {4866, "浙江音乐调频"},
    {20211686, "成都年代音乐怀旧好声音"},
    {1739, "厦门音乐广播"},
    {1271, "深圳飞扬971"},
    {20240, "山东经典音乐广播"},
    {20500066, "年代音乐1022"},
    {1296, "湖北经典音乐广播"},
    {267, "上海经典947"},
    {20212426, "崂山921"},
    {20003, "天津TIKI FM100.5"},
    {1111, "四川城市之音"},
    {4936, "江苏音乐广播PlayFM897"},
    {4237, "长沙FM101.7城市之声"},
    {1665, "山东音乐广播"},
    {1947, "安徽音乐广播"},
    {332, "北京音乐广播"},
    {4932, "山西音乐广播"},
    {20500149, "两广之声音乐台"},
    {4804, "怀集音乐之声"},
    {1649, "河北音乐广播"},
    {4938, "江苏经典流行音乐"},
    {1260, "广东音乐之声"},
    {273, "上海流行音乐LoveRadio"},
    {274, "上海动感101"},
    {2803, "苏州音乐广播"},
    {839, "哈尔滨音乐广播"},
    {5021381, "959年代音乐怀旧好声音"},
    {15318569, "AsiaFM 亚洲粤语台"},
    {5022308, "500首华语经典"},
    {20500150, "顺德音乐之声"},
    {4875, "FM950广西音乐台"},
    {1283, "江门旅游之声"},
    {1936, "FM954汽车音乐广播"},
    {20847, "FM88.6长沙音乐广播"},
    {1612, "西安音乐广播"},
    {20210755, "星河音乐"},
    {1886, "内蒙古音乐之声"},
    {1208, "河南音乐广播"},
    {4963, "南京音乐广播"},
    {1802, "江西音乐广播"},
    {15318146, "杭州FM90.7"},
    {647, "重庆音乐广播"},
    {15318703, "欧美音乐88.7"},
    {5021523, "惠州音乐广播"},
    {15318341, "AsiaFM HD音乐台"},
    {20769, "南宁经典1049"},
    {1289, "楚天音乐广播"},
    {4873, "陕西音乐广播"},
    {5022474, "武安融媒综合广播"},
    {21209, "东莞音乐广播"},
    {4969, "黑龙江音乐广播"},
    {1136, "嘉兴音乐广播"},
    {21275, "南通音乐广播"},
    {20211619, "怀旧音乐广播895"},
    {4981, "芒果时空音乐台"},
    {1297, "武汉经典音乐广播"},
    {20211638, "定州交通音乐广播"},
    {5022023, "上海KFM981"},
    {20207761, "80后音悦台"},
    {1654, "石家庄音乐广播"},
    {20212227, "经典FM1008"},
    {1149, "1003温州音乐之声"},
    {1671, "济南音乐广播FM88.7"},
    {5021912, "AsiaFM 亚洲经典台"},
    {1084, "大连1067"},
    {1892, "包头汽车音乐广播"},
    {1110, "四川岷江音乐广播"},
    {1831, "吉林音乐广播"},
    {5022405, "AsiaFM 亚洲音乐台"},
    {4581, "亚洲音乐成都FM96.5"},
    {20071, "AsiaFM 亚洲天空台"},
    {20033, "1047 Nice FM"},
    {4930, "FM102.2亲子智慧电台"},
    {4846, "893音乐广播"},
    {20026, "郁南音乐台"},
    {1608, "陕西故事广播·年代878"},
    {4923, "徐州音乐广播FM91.9"},
    {4878, "海南音乐广播"},
    {20211575, "经典983电台"},
    {4594, "潮州交通音乐广播"},
    {20500097, "经典音乐广播FM94.8"},
    {4885, "陕西青少广播·好听1055"},
    {4585, "福建音乐广播"},
    {2799, "常州音乐广播"},
    {1975, "MUSIC876"},
    {5022391, "Easy Fm"},
    {20500067, "FM95.9清远交通音乐广播"},
    {20211620, "流行音乐广播999正青春"},
    {20067, "贵州FM91.6音乐广播"},
    {5021902, "沧州音乐广播FM103.6"},
    {20207781, "眉山交通音乐广播"},
    {2811, "湖州交通文艺广播"},
    {5022050, "FM89.1吴江综合广播"},
    {20500053, "经典958"},
    {5022520, "盛京FM105.6"},
    {20091, "中国校园之声"},
    {4979, "89.3芒果音乐台"},
    {20835, "秦皇岛音乐广播"},
    {20211678, "廊坊飞扬105"},
    {1677, "青岛音乐体育广播"},
    {4029, "新疆MIXFM1039"},
    {5022338, "冰城1026哈尔滨古典音乐广播"},
    {20207762, "河南经典FM"},
    {4921, "郑州音乐广播"},
    {5022610, "察布查尔FM99.5"},
    {4871, "唐山音乐广播"},
    {1683, "烟台音乐广播FM105.9"},
    {5020, "滁州旅游交通广播"},
    {20440, "新疆昌吉 FM103.3综合广播"},
    {20212387, "凤凰音乐"},
    {20500187, "云梦音乐台"},
};

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
  sp.drawCentreString(buf, 120, 0);
  sp.pushSprite(0, 110);
  sp.deleteSprite();
  strftime(buf, 36, "%T", &info);
  sp.createSprite(240, 36);
  sp.drawCentreString(buf, 120, 0, &fonts::FreeSans24pt7b);
  sp.pushSprite(0, 140);
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

void playNext(int offset) {
  int total = radios.size();
  curIndex += offset;
  if (curIndex >= total) {
    curIndex %= total;
  } else if (curIndex < 0) {
    curIndex += total;
  }
  auto radio = radios[curIndex];
  sprintf(buf, FM_URL, radio.id);
  audio.connecttohost(buf);
  sprintf(buf, "%d.%s", curIndex + 1, radio.name.c_str());
  sp.createSprite(240, 16);
  sp.drawCentreString(buf, 120, 0);
  sp.pushSprite(0, 20);
  sp.deleteSprite();
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

void inline initTFTDevice() {
  tft.init();
  tft.setBrightness(60);
  tft.setFont(FONT16);
  tft.setColorDepth(8);
  tft.fillScreen(TFT_BLACK);
  sp.setFont(FONT16);
  sp.setColorDepth(8);
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
  sprintf(buf, "气温: %.2f℃ 湿度: %.2f%%\n", temp.temperature,
          humidity.relative_humidity);
  sp.createSprite(240, 16);
  sp.drawCentreString(buf, 120, 0);
  sp.pushSprite(0, 60);
  sp.deleteSprite();
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello ESP-S3!!");
  initTFTDevice();
  initAHT20Wire();
  setupButtons();
  initPixels();
  initAudioDevice();
  autoConfigWifi();
  startConfigTime();
  setupOTAConfig();
  showClientIP();
  showCurrentTime();
  updateAHT20Data();
  nextVolume(0);
  playNext(0);
}

void loop() {
  audio.loop();
  auto ms = millis();
  if (ms - check60s > 60000) {
    check60s = ms;
    updateAHT20Data();
  }
  if (ms - check1s > 1000) {
    check1s = ms;
    ArduinoOTA.handle();
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