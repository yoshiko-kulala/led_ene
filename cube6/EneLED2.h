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
    void led_test2(int color);
    void led_xaxis(int color);//0b001:red,0b010:green,0b100:blue
    void led_yaxis(int color);
    void led_zaxis(int color);
    void led_xaxis_rev(int color);
    void led_yaxis_rev(int color);
    void led_zaxis_rev(int color);
    void led_full(int color);
    void led_rotate(int color);
    void output();    //出力
  private:
    uint8_t PATTERNS[15];//最終出力バッファ
    void led_swap(int stage);
    int board_no;
    int led_red[5][5][5];
    int led_blu[5][5][5];
    int led_gre[5][5][5];
    int pattern_count;
};
#endif
