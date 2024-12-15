#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Wire.setPins(1, 2);
  Serial.begin(115200);
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
  delay(2000);
}