#include <Adafruit_MPU6050.h>
#include "lgfx.h"

#define FONT16 &fonts::efontCN_16

Adafruit_MPU6050 mpu;
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
  Serial.println("Adafruit MPU6050 test!");
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);
}

void loop() {
  if (mpu.getMotionInterruptStatus()) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    Serial.printf("Accel: [%.2f,%.2f,%.2f], gyro:[%.2f,%.2f,%.2f]\n",
                  a.acceleration.x, a.acceleration.y, a.acceleration.z,
                  g.gyro.x, g.gyro.y, g.gyro.z);
    tft.clear();
    tft.setCursor(0, 0);
    tft.printf("Accel: [%.2f,%.2f,%.2f]\ngyro:[%.2f,%.2f,%.2f]\n",
                  a.acceleration.x, a.acceleration.y, a.acceleration.z,
                  g.gyro.x, g.gyro.y, g.gyro.z);
  }
  delay(10);
}