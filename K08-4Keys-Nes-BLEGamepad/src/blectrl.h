#ifndef __BLE_CTRL_H__
#define __BLE_CTRL_H__

#include <Arduino.h>
#include <NimBLEDevice.h>
#include <esp_task_wdt.h>
#include <esp_wifi.h>
#include <vector>
using namespace std;

static NimBLEUUID uuidServiceHid("1812");
static NimBLEUUID uuidCharaReport("2a4d");
static const NimBLEAdvertisedDevice *advDevice;

uint32_t blueKey = 0xFF;

static void onNotifyGet(NimBLERemoteCharacteristic *pRemoteCharacteristic,
                        uint8_t *pData, size_t length, bool isNotify) {
  if (pRemoteCharacteristic->getUUID() == uuidCharaReport) {
    blueKey = *(uint32_t *)(pData + 4);
    Serial.printf("KEY [%08X]\n", blueKey);
  }
}

class MyBLEManager : public NimBLEScanCallbacks, public NimBLEClientCallbacks {
private:
  bool connectOk;

  void onResult(const NimBLEAdvertisedDevice *advertisedDevice) override {
    Serial.printf("Fond: [%s]\n", advertisedDevice->toString().c_str());
    if (advertisedDevice->isAdvertisingService(uuidServiceHid) &&
        advertisedDevice->getAppearance() == 963) {
      advDevice = advertisedDevice;
      NimBLEDevice::getScan()->stop();
      connectOk = true;
    }
  }

  void onConnect(NimBLEClient *pClient) override {
    auto pService = pClient->getService(uuidServiceHid);
    if (!pService) {
      return;
    }
    for (auto pChara : pService->getCharacteristics(true)) {
      if (pChara->canNotify()) {
        pChara->subscribe(true, onNotifyGet, true);
      }
      if (pChara->canRead()) {
        auto str = pChara->readValue();
        if (str.size() == 0) {
          str = pChara->readValue();
        }
      }
    }
  }

  void onDisconnect(NimBLEClient *pClient, int reason) override {
    Serial.println("onDisconnect()");
    ESP.restart();
  }

  bool connectToServer() {
    NimBLEClient *pClient = nullptr;
    if (NimBLEDevice::getCreatedClientCount()) {
      pClient = NimBLEDevice::getClientByPeerAddress(advDevice->getAddress());
      if (pClient) {
        if (!pClient->connect(advDevice, false)) {
          return false;
        }
      } else {
        pClient = NimBLEDevice::getDisconnectedClient();
      }
    }
    if (!pClient) {
      if (NimBLEDevice::getCreatedClientCount() >= NIMBLE_MAX_CONNECTIONS) {
        return false;
      }
      pClient = NimBLEDevice::createClient();
      pClient->setClientCallbacks(this, false);
      pClient->setConnectionParams(12, 12, 0, 150);
      pClient->setConnectTimeout(5 * 1000);
      if (!pClient->connect(advDevice)) {
        NimBLEDevice::deleteClient(pClient);
        return false;
      }
    }
    if (!pClient->isConnected()) {
      if (!pClient->connect(advDevice)) {
        return false;
      }
    }
    return true;
  }

public:
  MyBLEManager() {
    advDevice = nullptr;
    connectOk = false;
  }

  void scanAndConnect() {
    Serial.println("Start Scan!!");
    auto pScan = NimBLEDevice::getScan();
    pScan->setDuplicateFilter(false);
    pScan->setScanCallbacks(this);
    pScan->setInterval(97);
    pScan->setWindow(97);
    pScan->start(30000);
    while (!connectOk) {
      delay(500);
    }
    connectToServer();
  }
};

static MyBLEManager *mbm;

void inline scanAndConnectServer() {
  NimBLEDevice::init("");
  NimBLEDevice::setOwnAddrType(BLE_OWN_ADDR_PUBLIC);
  NimBLEDevice::setSecurityAuth(true, false, false);
  NimBLEDevice::setPower(ESP_PWR_LVL_P9);
  mbm = new MyBLEManager();
  mbm->scanAndConnect();
}

#endif