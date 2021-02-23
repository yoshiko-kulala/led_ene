/* BT_Serial_2
 */

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

uint8_t tx=0;
String str="0\n";

String MACadd = "24:62:AB:E2:4F:1E";
uint8_t address[6]  = {0x24, 0x62, 0xAB, 0xE2, 0x4F, 0x1E};
//uint8_t address[6]  = {0x00, 0x1D, 0xA5, 0x02, 0xC3, 0x22};
String name = "OBDII";
char *pin = "1234"; //<- standard pin would be provided by default
bool connected;

void setup() {
  pinMode(12,INPUT);
  pinMode(14,INPUT);
  pinMode(27,INPUT);
  Serial.begin(115200);
  //SerialBT.setPin(pin);
  SerialBT.begin("ESP32test", true); 
  Serial.println("The device started in master mode, make sure remote BT device is on!");
  connected = SerialBT.connect(address);
  
  if(connected) {
    Serial.println("Connected Succesfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); 
    }
  }
  if (SerialBT.disconnect()) {
    Serial.println("Disconnected Succesfully!");
  }
  SerialBT.connect();
}

void loop() {
  tx=digitalRead(12)+digitalRead(14)*2+digitalRead(27)*4;
  str= String(tx)/*+"\n"*/;
  Serial.println(str);
  SerialBT.print(str);
  delay(20);
}
