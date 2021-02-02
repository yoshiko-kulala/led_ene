#include "EneLED2.h"
#include <MsTimer2.h>
int c = 0;

EneLED ene;

void interrupt() {
  ene.output();
}

void setup() {
  MsTimer2::set(2, interrupt);
  MsTimer2::start();
  ene.init(2);
}

void loop() {
  c++;
  //ene.led_test2(0b001);
  ene.led_rotate(c);
  if (c > 7)c = 1;
  ene.led_full(c);
  delay(1000);
  ene.led_xaxis(c);
  ene.led_xaxis_rev(c);
  ene.led_xaxis(c);
  ene.led_xaxis_rev(c);
  ene.led_yaxis(c);
  ene.led_yaxis_rev(c);
  ene.led_yaxis(c);
  ene.led_yaxis_rev(c);
  ene.led_zaxis(c);
  ene.led_zaxis_rev(c);
  ene.led_zaxis(c);
  ene.led_zaxis_rev(c);
  ene.led_test();
  ene.led_test();
}
