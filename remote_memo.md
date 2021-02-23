# ESPで遠隔化メモ

いくつか方法あるっぽい  

## ESP-NOW  
実質Wi-Fiに見える  
[M5StickCでESP-NOW その1 | Lang-ship](https://lang-ship.com/blog/work/m5stickc-esp-now-1/)  
[ESP-NowでESP32同士の通信とESP8266からESP32への通信も出来ました！](https://qiita.com/yoroyasu/items/05aa1135c2c830708e20)  
[ESP8266とESP32 温度測定にESP-NOWを使ってみる](https://okiraku-camera.tokyo/blog/?p=7167)  

## BluetoothSerial  
Bluetoothでの通信  
[ロボオプションズ ESP32同士をBluetoothシリアルでつないでみる](http://robooptions.blog.fc2.com/blog-entry-9.html)  

単純にWi-Fiは(確か2.4なので)電子レンジとかで接続切れそうな希ガス  

ということでまずはMacアドレス調べる  
![](https://i.imgur.com/hiFbJSO.jpg)  
番号振った  

プログラム書き込む  
```
void setup(void) {
  Serial.begin(115200);
  Serial.println("-----------------");
  uint8_t macBT[6];
  esp_read_mac(macBT, ESP_MAC_BT);
  Serial.printf("%02X:%02X:%02X:%02X:%02X:%02X\r\n", macBT[0], macBT[1], macBT[2], macBT[3], macBT[4], macBT[5]);
}

void loop() {
  delay(1000);
}
```

| 番号 | Macアドレス |
| -------- | -------- |
| 0 | FC:F5:C4:1A:41:46 |
| 1 | FC:F5:C4:1A:2D:92 |
| 2 | FC:F5:C4:1A:37:46 |
| 3 | FC:F5:C4:1A:3A:72 |
| 4 | 24:62:AB:E2:4F:1E |
| 5 | 24:62:AB:E2:5D:46 |

セキュリティガバガバで草(まぁいいのである)  

3で割った余りで組にして数字の小さい方をマスタにする  

とりあえずシリアルでの通信は出来た  
![](https://i.imgur.com/IMdXubF.png)  
これでスイッチの状態を送りたい  

パターンについて考える  
どうやら通信途切れても-1とか返さないっぽい(あくまでBTserialなので非同期なんですね、きっと)  

ボタン(順不同)を考える  
アサインはよくわからんので、+の下から0,1,2と数振って  
![](https://i.imgur.com/DeBo7GG.png)  
写真でいう左から0,1,2  
そのまんま二進数にする  

まずそもそも、ESPさん3.3Vなので適当に帳尻合わせないと壊れそうで草  
2/3なので分圧するか、そもそも信号反転してるのでFETでスイッチングするか  

後は通信の話し  
信号の送信間隔をどうするかと、どれくらい通信が途切れたらOFFと判断するか  
デバッグできないのでノリと勘で決める  

ついでに混線するかも試さないといけないなぁ  

まぁまずは回路考えよ  
GPIOは25,26,27を使う  
よくよく見たらこれ、双方向通信出来るサンプルだわ  
分かりにくいのでマスタをボタンにする  
![](https://i.imgur.com/oRKAcPu.png)  
左がいわゆるメスで右がオス  
コネクタ形状としてはマスターがメスでスレーブがオスになる  
図は線側からみた図  

| ピン | マスター | スレーブ |
| -------- | -------- | -------- |
| 1 | GND | GND |
| 2 | NC | NC |
| 3 | 5V | 5V |
| 4 | ? | ? |
| 5 | ? | ? |
| 6 | ? | ? |

当たり前だけどピンアサインはおんなじか  

とりあえず回路組んでみる  
![](https://i.imgur.com/IRH2DPR.png)  
でプログラム(ここに書くのもなんだけど記録には残らない気がするので)  

マスター
```
/* BT_Serial_0
 * ある意味完成版
 */

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

uint8_t tx=0;
String str="0\n";

String MACadd = "FC:F5:C4:1A:3A:72";
uint8_t address[6]  = {0xFC, 0xF5, 0xC4, 0x1A, 0x3A, 0x72};
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
```
スレーブ
```
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
```

これでとりあえずLチカの確認は出来た  
あとは電圧の問題さえ解決すれば完成ちゃうかな  