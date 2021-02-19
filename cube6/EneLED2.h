#ifndef EneLED2_h
#define EneLED2_h
#include <Arduino.h>
#include <SPI.h>

class EneLED{
  public:
    EneLED();
    void init(int board);      //初期化
    void led_clear();
    void led_test();
    void led_xaxis();//0b001:red,0b010:green,0b100:blue
    void led_yaxis();
    void led_zaxis();
    void led_xaxis_rev();
    void led_yaxis_rev();
    void led_zaxis_rev();
    void led_default();
    void led_suwa();
    void led_suwa2();
    void led_full();
    void falldown();
    void text(int w);
    void led_BEt(int w);
    void led_boxes(int w);
    void led_jiwajiwa(int w);
    void output();    //出力
    void text(char string[], uint8_t len);
    uint16_t timer;
    int color;
    int led_red[5][5][5];
    int led_blu[5][5][5];
    int led_gre[5][5][5];
  private:
    uint8_t PATTERNS[15];//最終出力バッファ
    void led_swap(int stage);
    int board_no;
    int pattern_count;
};
#endif
