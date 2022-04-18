#include <bluefruit.h>

// Beacon uses the Manufacturer Specific Data field in the advertising
// packet, which means you must provide a valid Manufacturer ID. Update
// the field below to an appropriate value. For a list of valid IDs see:
// https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers

#define MANUFACTURER_ID   0x004C

//Set beacon's UUID
uint8_t beaconUuid[16] =
{
  0x01, 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78,
  0x89, 0x9a, 0xab, 0xbc, 0xcd, 0xde, 0xef, 0xf0
};

//Create beacon with the following parameters [UUID, Major, Minor, Tx Power]
BLEBeacon beacon(beaconUuid, 0x01, 0x08, -54);

void setup() 
{
  Serial.begin(115200);

  // Uncomment to blocking wait for Serial connection
  // while ( !Serial ) delay(10);

  Serial.println("Bluefruit52 Beacon Example");
  Serial.println("--------------------------\n");

  Bluefruit.begin();
  
  // Turn on blue LED on board
  Bluefruit.autoConnLed(true);  
  Bluefruit.setTxPower(0);
  beacon.setManufacturer(MANUFACTURER_ID);

  startAdv();

  Serial.println("Broadcasting beacon, open your beacon app to test");

  suspendLoop();
}

void startAdv(void)
{  
  Bluefruit.Advertising.setBeacon(beacon);

  // Secondary Scan Response packet (optional)
  // Since there is no room for 'Name' in Advertising packet
  Bluefruit.ScanResponse.addName();
  
  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   * 
   * Apple Beacon specs
   * - Type: Non connectable, undirected
   * - Fixed interval: 100 ms -> fast = slow = 100 ms
   */
  //Bluefruit.Advertising.setType(BLE_GAP_ADV_TYPE_ADV_NONCONN_IND);
  
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(160, 160);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds  
}

void loop() 
{
  // loop is already suspended, CPU will not run loop() at all
}
