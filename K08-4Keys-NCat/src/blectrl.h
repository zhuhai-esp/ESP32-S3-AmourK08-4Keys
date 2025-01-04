#ifndef __BLE_CTRL_H__
#define __BLE_CTRL_H__

#include <Arduino.h>
#include <BLEDevice.h>
#include <esp_task_wdt.h>
#include <esp_wifi.h>
#include <vector>
using namespace std;

uint16_t blueKey = 0x00;

class MyBLEManager : public BLEAdvertisedDeviceCallbacks,
                     public BLEClientCallbacks {
public:
  BLEAdvertisedDevice *myDevice;
  boolean connected;
  boolean doConnect;
  BLEUUID *serviceUUID;
  BLEUUID *charUUID;

  MyBLEManager() {
    connected = false;
    doConnect = false;
    serviceUUID = new BLEUUID("00001812-0000-1000-8000-00805f9b34fb");
    charUUID = new BLEUUID("00002a4d-0000-1000-8000-00805f9b34fb");
  }

  void onConnect(BLEClient *pClient) {
    Serial.println("onConnect(BLEClient *pClient)");
  }

  void onDisconnect(BLEClient *pClient) {
    connected = false;
    Serial.println("onDisconnect(BLEClient *pClient)");
  }

  void waitForConnect() {
    while (!doConnect) {
      delay(100);
    }
    if (!connected) {
      connectToServer();
    }
  }

  boolean connectToServer() {
    Serial.println("connectToServer!");
    BLEDevice::setEncryptionLevel(ESP_BLE_SEC_ENCRYPT);
    BLEClient *pClient = BLEDevice::createClient();
    pClient->setClientCallbacks(this);
    pClient->connect(myDevice);
    pClient->setMTU(517);
    auto rs = pClient->getService(*serviceUUID);
    if (rs == nullptr) {
      pClient->disconnect();
      return false;
    }
    auto ch = rs->getCharacteristic(*charUUID);
    if (ch != nullptr && ch->canNotify()) {
      ch->registerForNotify(
          [](BLERemoteCharacteristic *_, uint8_t *_d, size_t _s, bool _n) {
            uint16_t *pKey = (uint16_t *)_d;
            blueKey = *pKey;
          });
    }
    connected = true;
    return true;
  }

  void onResult(BLEAdvertisedDevice ad) {
    if (ad.haveServiceUUID() && ad.isAdvertisingService(*serviceUUID)) {
      BLEDevice::getScan()->stop();
      myDevice = new BLEAdvertisedDevice(ad);
      doConnect = true;
    }
  }

  void startScan() {
    BLEScan *pBLEScan = BLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(this);
    pBLEScan->setInterval(1349);
    pBLEScan->setWindow(449);
    pBLEScan->setActiveScan(true);
    pBLEScan->start(0, false);
  }
};

MyBLEManager *mbm;

void inline scanAndConnectServer() {
  BLEDevice::init("ESP-Client");
  mbm = new MyBLEManager();
  mbm->startScan();
  mbm->waitForConnect();
}

#endif