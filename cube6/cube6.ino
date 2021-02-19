#include "EneLED2.h"
#include <MsTimer2.h>

#define red_Button 5
#define green_Button 7
#define blue_Button 8
EneLED ene;

int tim = 0;

void interrupt()
{
  ene.color = digitalRead(5) + digitalRead(7) * 2 + digitalRead(8) * 4;
  if (digitalRead(5) + digitalRead(7) + digitalRead(8)) {
    tim++;
    if (tim < 400) {
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          for (int k = 0; k < 5; k++) {
            if (ene.color % 2) {
              ene.led_red[i][j][k] = 1;
            }
            if ((ene.color / 2) % 2) {
              ene.led_gre[i][j][k] = 1;
            }
            if ((ene.color / 4) % 2) {
              ene.led_blu[i][j][k] = 1;
            }
          }
        }
      }
    }
  }
  else tim=0;
  ene.output();
  //Serial.print(c);
}

int u = 0;

void setup() {
  Serial.begin(9600);
  MsTimer2::set(2, interrupt);
  MsTimer2::start();
  ene.init(1);
}

void loop() {//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //ene.led_suwa();
  //delay(2000);
  while (1) {
    if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
      break;
    }
    int y = random(5);
    switch (y) {
      case 0:
        for (int t = 3; t > 0; t--)
        {
          ene.led_default();
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;
      case 1:
        for (int t = 20; t > 0; t--)
        {
          ene.falldown();
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;
      case 2:
        for (int t = 10; t > 0; t--)
        {
          ene.text(t);
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;
      case 3:
        for (int t = 26; t > 0; t--)
        {
          ene.led_BEt(t);
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;
      case 4:
        for (int t = 10; t > 0; t--)
        {
          u = random(8);
          ene.led_boxes(u);
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;
    }
  }
  int x = random(2);
  switch (x) {
    case 0:
      for (int t = 10; t > 0; t--) {
        //ene.led_jiwajiwa(t);
        ene.led_suwa();
        if ( (digitalRead(5) == 1) || ( digitalRead(7) == 1) || ( digitalRead(8) == 1)) {
          t = 0;
        }
      }
      break;
    case 1:
      for (int t = 10; t > 0; t--) {
        ene.led_test();
        if ( (digitalRead(5) == 1) || ( digitalRead(7) == 1) || ( digitalRead(8) == 1)) {
          t = 0;
        }
      }
      break;
  }
}
