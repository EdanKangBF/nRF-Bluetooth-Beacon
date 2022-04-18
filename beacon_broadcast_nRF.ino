#include <bluefruit.h>


#define MANUFACTURER_ID 0xFFFF

uint8_t beaconUuid[16] = 
{ 
  0x7C, 0x31, 0x2E, 0x33, 0x34, 0x36, 0x7C, 0x31, 
  0x30, 0x33, 0x2E, 0x36, 0x38, 0x7C, 0x31, 0x7C,
}; //|1.346|103.368

BLEBeacon beacon(beaconUuid);

void setup() {
  Serial.begin(115200);
  Bluefruit.begin();
  Bluefruit.setTxPower(4);
  Bluefruit.setName("nRFBeacon");
  beacon.setManufacturer(MANUFACTURER_ID);
  Bluefruit.ScanResponse.addName();
  Bluefruit.Advertising.setBeacon(beacon);
  Bluefruit.Advertising.start();

}

void loop() {
  digitalToggle(LED_BUILTIN);
  delay(1000);

}
