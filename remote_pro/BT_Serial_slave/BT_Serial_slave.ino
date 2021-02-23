/* BT_Serial_Slave
 * Ltikaテスト
 */
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int rx;

void setup() {
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    rx = int(SerialBT.read()-48);
    Serial.println(rx);
  }
  if(rx%2)digitalWrite(12,HIGH);
  else digitalWrite(12,LOW);
  if((rx/2)%2)digitalWrite(14,HIGH);
  else digitalWrite(14,LOW);
  if((rx/4)%2)digitalWrite(27,HIGH);
  else digitalWrite(27,LOW);
  delay(20);
}
