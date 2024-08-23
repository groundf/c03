/* ****************************************************************************
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:

   SD card attached to SPI bus as follows:

  - MOSI  pin 11
  - MISO  pin 12
  - SCK   pin 13
  - CS    pin 4
 **************************************************************************** */

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open.
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  myFile = SD.open("test.txt", FILE_WRITE);

  if (!myFile) {
    Serial.println("error opening test.txt");
  }
  
  Serial.print("Writing to test.txt...");
  myFile.println("testing 1, 2, 3.");
  myFile.close();
  Serial.println("done.");

  myFile = SD.open("test.txt");
  
  if (!myFile) {
    Serial.println("error opening test.txt");
  }
  Serial.println("test.txt:");
  while (myFile.available()) {
    Serial.write(myFile.read());
  }
  myFile.close();

}

void loop() {
  // ...
}
