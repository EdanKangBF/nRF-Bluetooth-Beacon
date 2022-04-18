#include <bluefruit.h>

// Beacon uses the Manufacturer Specific Data field in the advertising
// packet, which means you must provide a valid Manufacturer ID. Update
// the field below to an appropriate value. For a list of valid IDs see:
// https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers

#define MANUFACTURER_ID 0xFFFF

//Set beacon's UUID. Uuid follows ASCII table of Hex codes.
uint8_t beaconUuid[16] = 
{ 
  0x7C, 0x31, 0x2E, 0x33, 0x34, 0x36, 0x7C, 0x31, 
  0x30, 0x33, 0x2E, 0x36, 0x38, 0x7C, 0x31, 0x7C,
}; //|1.346|103.368

//Create beacon with the following parameters [UUID, Major, Minor, Tx Power]
BLEBeacon beacon(beaconUuid);

void setup() {
  Serial.begin(115200);
  Bluefruit.begin();
  Bluefruit.setTxPower(4);
  Bluefruit.setName("nRFBeacon");
  beacon.setManufacturer(MANUFACTURER_ID);
  
  // Secondary Scan Response packet (optional)
  // Since there is no room for 'Name' in Advertising packet
  Bluefruit.ScanResponse.addName();
  Bluefruit.Advertising.setBeacon(beacon);
  Bluefruit.Advertising.start();

}

void loop() {
  digitalToggle(LED_BUILTIN);
  delay(1000);

}
