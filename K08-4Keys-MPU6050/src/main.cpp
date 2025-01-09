#include "TFTDebugDraw.h"
#include "lgfx.h"
#include <Adafruit_MPU6050.h>
#include <box2d/box2d.h>

Adafruit_MPU6050 mpu;
LGFX tft;
LGFX_Sprite sprite(&tft);
b2World *myWorld = nullptr;
unsigned long lastMs = 0;

void inline initTFTDevice() {
  tft.init();
  tft.setBrightness(60);
  tft.fillScreen(TFT_BLACK);
  tft.setColorDepth(8);
  sprite.setColorDepth(8);
  sprite.createSprite(tft.width(), tft.height());
}

void createSomeBall() {
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.allowSleep = true;
  auto r = (random() % 12) / 60.01;
  bodyDef.position.Set(9 + r * 5, 4 + r);
  auto *body = myWorld->CreateBody(&bodyDef);
  b2CircleShape shape;
  shape.m_radius = 0.4 + r;
  b2FixtureDef f;
  f.shape = &shape;
  f.density = 0.1;
  f.friction = 0.001;
  f.restitution = 0.01;
  body->CreateFixture(&f);
  body->ApplyForce(b2Vec2(r * 2, r), b2Vec2(0, 0), true);
}

void createSomeWorld() {
  b2Vec2 gravity(0, 10);
  myWorld = new b2World(gravity);
  b2Draw *draw = new TFTDebugDraw();
  draw->SetFlags(1);
  myWorld->SetAllowSleeping(false);
  myWorld->SetDebugDraw(draw);
  b2BodyDef groundBodyDef;
  b2Body *groundBody = myWorld->CreateBody(&groundBodyDef);
  b2PolygonShape groundBox;
  groundBox.SetAsBox(6, .025, b2Vec2(12, 0), 0);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(6, .025, b2Vec2(12, 24), 0);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.025, 4.6, b2Vec2(6, 4.3), 0);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.025, 4.6, b2Vec2(18, 4.3), 0);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.025, 4.6, b2Vec2(6, 19.7), 0);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.025, 4.6, b2Vec2(18, 19.7), 0);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.05, 3.1, b2Vec2(8.5, 10.5), 2 * PI / 3);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.05, 3.1, b2Vec2(15.5, 10.5), PI / 3);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.05, 3.1, b2Vec2(8.5, 13.5), PI / 3);
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBox.SetAsBox(.05, 3.1, b2Vec2(15.5, 13.5), 2 * PI / 3);
  groundBody->CreateFixture(&groundBox, 0.0f);
  for (int i = 0; i < 66; i++) {
    createSomeBall();
  }
}

void setup() {
  Wire.setPins(1, 2);
  Serial.begin(115200);
  initTFTDevice();
  createSomeWorld();
  Serial.println("Adafruit MPU6050 test!");
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("MPU6050 Found!");
}

void loop() {
  myWorld->Step(0.1, 6, 2);
  sprite.clear();
  myWorld->DebugDraw();
  sprite.pushSprite(0, 0);
  if (millis() - lastMs >= 1000) {
    lastMs = millis();
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    auto acc = a.acceleration;
    myWorld->SetGravity(b2Vec2(-acc.y, -acc.x));
  }
}