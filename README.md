# Bluetooth-Beacon Arduino IDE Initial Setup for Adafruit Feather nRF58240
## Initial Setup
Head to Arduino Website and download the latest IDE for your OS. https://www.arduino.cc/en/software

## Arduino IDE Installation for nRF Beacon
1. Head to File/Preference. Under "Additional Boards Manager URLs", add the URL https://www.adafruit.com/package_adafruit_index.json.
2. Head to Tools/Boards/Boards Manager. Search for Adafruit and install “Adafruit nRF52 by Adafruit”.
3. If the board is not found in Boards Manager, Restart IDE
4. Once installed, head to Tools/Board and select “nRF52840 Express”.
5. Plug Bluetooth Beacon into PC.
6. Head to Tools/Ports and select the NRF52840 board to program.

## Functions
### uint8_t beaconUuid[16]
This function allows the payload to be set using the ASCII table hexcodes. It currently allows 16 bytes of information to be broadcasted.

## API References
1. https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v15.0.0%2Fble_sdk_app_beacon.html
2. https://devzone.nordicsemi.com/f/nordic-q-a/49397/how-to-advertise-sensor-data-with-beacon-code
