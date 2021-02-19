#include <Arduino.h>
#include "EneLED2.h"

EneLED::EneLED(void) {
}

void EneLED::init(int board) {
  pattern_count = 0;
  color = 0;
  board_no = board;
  pinMode(13, OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(11, OUTPUT);
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

void EneLED::led_clear() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        led_red[i][j][k] = 0;
        led_gre[i][j][k] = 0;
        led_blu[i][j][k] = 0;
      }
    }
  }
}

void EneLED::led_default() {
  led_xaxis();
  led_xaxis_rev();
  led_xaxis();
  led_xaxis_rev();
  led_yaxis();
  led_yaxis_rev();
  led_yaxis();
  led_yaxis_rev();
  led_zaxis();
  led_zaxis_rev();
  led_zaxis();
  led_zaxis_rev();
}
void EneLED::led_suwa() {
  led_clear();
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if (color % 2) {
        led_red[i][j][3] = 1;
      }
      if ((color / 2) % 2) {
        led_gre[i][j][3] = 1;
      }
      if ((color / 4) % 2) {
        led_blu[i][j][3] = 1;
      }
      led_red[2][2][3] = 0;
      led_blu[2][2][3] = 0;
      led_gre[2][2][3] = 0;
    }
  }
}

void EneLED::led_suwa2() {
  led_clear();
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if (color % 2) {
        led_red[i][j][3] = 1;
      }
      if ((color / 2) % 2) {
        led_gre[i][j][3] = 1;
      }
      if ((color / 4) % 2) {
        led_blu[i][j][3] = 1;
      }
      led_red[2][2][3] = 0;
      led_blu[2][2][3] = 0;
      led_gre[2][2][3] = 0;
    }
  }
}

void EneLED::led_test() {
  for (int i = 0; i < 5; i++) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      led_red[abs(j - 4)][j][(j - i + 5) % 5] = 1;
      led_gre[j][j][(j - i + 5) % 5] = 1;
      led_blu[j][abs(j - 4)][(j - i + 5) % 5] = 1;
    }
    delay(200);
  }
}

void EneLED::led_xaxis() {
  for (int i = 0; i < 5; i++) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (color % 2) {
          led_red[i][j][k] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][j][k] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][j][k] = 1;
        }
      }
    }
    delay(100);
  }
}

void EneLED::led_yaxis() {
  for (int i = 0; i < 5; i++) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (color % 2) {
          led_red[j][i][k] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[j][i][k] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[j][i][k] = 1;
        }
      }
    }
    delay(100);
  }
}

void EneLED::led_zaxis() {
  for (int i = 0; i < 5; i++) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (color % 2) {
          led_red[j][k][i] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[j][k][i] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[j][k][i] = 1;
        }
      }
    }
    delay(100);
  }
}

void EneLED::led_xaxis_rev() {
  for (int i = 4; i > 0; i--) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (color % 2) {
          led_red[i][j][k] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][j][k] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][j][k] = 1;
        }
      }
    }
    delay(100);
  }
}

void EneLED::led_yaxis_rev() {
  for (int i = 4; i > 0; i--) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (color % 2) {
          led_red[j][i][k] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[j][i][k] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[j][i][k] = 1;
        }
      }
    }
    delay(100);
  }
}

void EneLED::led_zaxis_rev() {
  for (int i = 4; i > 0; i--) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (color % 2) {
          led_red[j][k][i] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[j][k][i] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[j][k][i] = 1;
        }
      }
    }
    delay(100);
  }
}

void EneLED::led_full() {
  for (int i = 0; i < 5; i++) {

    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        if (color % 2) {
          led_red[i][j][k] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][j][k] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][j][k] = 1;
        }
      }
    }
  }
}

void EneLED::falldown() {
  int i = random(5);
  int j = random(5);
  int i2 = random(5);
  int j2 = random(5);
  int i3 = random(5);
  int j3 = random(5);
  int i4 = random(5);
  int j4 = random(5);
  int i5 = random(5);
  int j5 = random(5);
  int i6 = random(5);
  int j6 = random(5);
  if (color > 0) {
    led_red[i][j][4] =  1;
    led_blu[i][j][4] =  1;
    led_gre[i][j][4] =  1;
    led_red[i2][j2][4] =  1;
    led_blu[i2][j2][4] =  1;
    led_gre[i2][j2][4] =  1;
    led_red[i3][j3][4] =  1;
    led_blu[i3][j3][4] =  1;
    led_gre[i3][j3][4] =  1;
    led_red[i4][j4][4] =  1;
    led_blu[i4][j4][4] =  1;
    led_gre[i4][j4][4] =  1;
    led_red[i5][j5][4] =  1;
    led_blu[i5][j5][4] =  1;
    led_gre[i5][j5][4] =  1;
    led_red[i6][j6][4] =  1;
    led_blu[i6][j6][4] =  1;
    led_gre[i6][j6][4] =  1;
    for (int s = 4; s > 0; s--)
    {
      if (color % 2) {
        led_red[i][j][s - 1] = led_red[i][j][s];
        led_red[i2][j2][s - 1] = led_red[i2][j2][s];
        led_red[i3][j3][s - 1] = led_red[i3][j3][s];
        led_red[i4][j4][s - 1] = led_red[i4][j4][s];
        led_red[i5][j5][s - 1] = led_red[i5][j5][s];
        led_red[i6][j6][s - 1] = led_red[i6][j6][s];
        led_red[i][j][s] = 0;
        led_red[i2][j2][s] = 0;
        led_red[i3][j3][s] = 0;
        led_red[i4][j4][s] = 0;
        led_red[i5][j5][s] = 0;
        led_red[i6][j6][s] = 0;
      }
      if ((color / 2) % 2) {
        led_gre[i][j][s - 1] = led_gre[i][j][s];
        led_gre[i2][j2][s - 1] = led_gre[i2][j2][s];
        led_gre[i3][j3][s - 1] = led_gre[i3][j3][s];
        led_gre[i4][j4][s - 1] = led_gre[i4][j4][s];
        led_gre[i5][j5][s - 1] = led_gre[i5][j5][s];
        led_gre[i6][j6][s - 1] = led_gre[i6][j6][s];
        led_gre[i][j][s] = 0;
        led_gre[i2][j2][s] = 0;
        led_gre[i3][j3][s] = 0;
        led_gre[i4][j4][s] = 0;
        led_gre[i5][j5][s] = 0;
        led_gre[i6][j6][s] = 0;
      }
      if ((color / 4) % 2) {
        led_blu[i][j][s - 1] = led_blu[i][j][s];
        led_blu[i2][j2][s - 1] = led_blu[i2][j2][s];
        led_blu[i3][j3][s - 1] = led_blu[i3][j3][s];
        led_blu[i4][j4][s - 1] = led_blu[i4][j4][s];
        led_blu[i5][j5][s - 1] = led_blu[i5][j5][s];
        led_blu[i6][j6][s - 1] = led_blu[i6][j6][s];
        led_blu[i][j][s] = 0;
        led_blu[i2][j2][s] = 0;
        led_blu[i3][j3][s] = 0;
        led_blu[i4][j4][s] = 0;
        led_blu[i5][j5][s] = 0;
        led_blu[i6][j6][s] = 0;
      }
      delay(100);
    }
    //delay(100);
  }
  led_clear();
}

void EneLED::text(int w)
{
  for (int i = 4; i >= 0; i--) {
    led_clear();
    switch (w) {
      case 9:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 8:
        if (color % 2) {
          led_red[i][2][4] = 1;
          led_red[i][2][3] = 1; led_red[i][3][3] = 1;
          led_red[i][2][2] = 1;
          led_red[i][2][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][2][4] = 1;
          led_gre[i][2][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][2][2] = 1;
          led_gre[i][2][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][2][4] = 1;
          led_blu[i][2][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][2][2] = 1;
          led_blu[i][2][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 7:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 6:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 5:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1;
          led_red[i][1][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1;
          led_gre[i][1][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1;
          led_blu[i][1][0] = 1;
        }
        break;
      case 4:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 3:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 2:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1;
          led_red[i][1][1] = 1;
          led_red[i][1][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1;
          led_gre[i][1][1] = 1;
          led_gre[i][1][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1;
          led_blu[i][1][1] = 1;
          led_blu[i][1][0] = 1;
        }
        break;
      case 1:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 0:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1;
          led_red[i][1][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1;
          led_gre[i][1][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1;
          led_blu[i][1][0] = 1;
        }
        break;
    }
    delay(100);
    //delay(100);
  }
  //delay(100);
}
void EneLED::led_BEt(int w) {
  for (int i = 4; i >= 0; i--) {
    led_clear();
    switch (w) {
      case 25:
        if (color % 2) {
          led_red[i][2][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 24:
        if (color % 2) {
          led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 23:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][0][3] = 1; led_red[i][4][3] = 1;
          led_red[i][4][2] = 1;
          led_red[i][0][1] = 1; led_red[i][4][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][0][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][4][2] = 1;
          led_gre[i][0][1] = 1; led_gre[i][4][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][0][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][4][2] = 1;
          led_blu[i][0][1] = 1; led_blu[i][4][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 22:
        if (color % 2) {
          led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 21:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 20:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][3][1] = 1;
          led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][3][1] = 1;
          led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][3][1] = 1;
          led_blu[i][3][0] = 1;
        }
        break;
      case 19:
        if (color % 2) {
          led_red[i][2][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][2][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][2][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][2][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][2][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][2][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1;
        }
        break;
      case 18:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 17:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][2][3] = 1;
          led_red[i][2][2] = 1;
          led_red[i][2][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][2][3] = 1;
          led_gre[i][2][2] = 1;
          led_gre[i][2][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][2][3] = 1;
          led_blu[i][2][2] = 1;
          led_blu[i][2][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 16:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][1][4] = 1; led_red[i][2][4] = 1;
          led_red[i][1][3] = 1;
          led_red[i][1][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][4] = 1; led_gre[i][1][4] = 1; led_gre[i][2][4] = 1;
          led_gre[i][1][3] = 1;
          led_gre[i][1][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][4] = 1; led_blu[i][1][4] = 1; led_blu[i][2][4] = 1;
          led_blu[i][1][3] = 1;
          led_blu[i][1][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 15:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][3][4] = 1;
          led_red[i][2][3] = 1; led_red[i][3][3] = 1;
          led_red[i][3][2] = 1;
          led_red[i][2][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][2][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][3][2] = 1;
          led_gre[i][2][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][2][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][3][2] = 1;
          led_blu[i][2][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 14:
        if (color % 2) {
          led_red[i][3][4] = 1;
          led_red[i][3][3] = 1;
          led_red[i][3][2] = 1;
          led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][3][4] = 1;
          led_gre[i][3][3] = 1;
          led_gre[i][3][2] = 1;
          led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][3][4] = 1;
          led_blu[i][3][3] = 1;
          led_blu[i][3][2] = 1;
          led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 13:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][4][4] = 1;
          led_red[i][0][3] = 1; led_red[i][1][3] = 1; led_red[i][3][3] = 1; led_red[i][4][3] = 1;
          led_red[i][0][2] = 1; led_red[i][2][2] = 1; led_red[i][4][2] = 1;
          led_red[i][0][1] = 1; led_red[i][4][1] = 1;
          led_red[i][0][0] = 1; led_red[i][4][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][4] = 1; led_gre[i][4][4] = 1;
          led_gre[i][0][3] = 1; led_gre[i][1][3] = 1; led_gre[i][3][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][0][2] = 1; led_gre[i][2][2] = 1; led_gre[i][4][2] = 1;
          led_gre[i][0][1] = 1; led_gre[i][4][1] = 1;
          led_gre[i][0][0] = 1; led_gre[i][4][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][4] = 1; led_blu[i][4][4] = 1;
          led_blu[i][0][3] = 1; led_blu[i][1][3] = 1; led_blu[i][3][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][0][2] = 1; led_blu[i][2][2] = 1; led_blu[i][4][2] = 1;
          led_blu[i][0][1] = 1; led_blu[i][4][1] = 1;
          led_blu[i][0][0] = 1; led_blu[i][4][0] = 1;
        }
        break;
      case 12:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][4][4] = 1;
          led_red[i][0][3] = 1; led_red[i][3][3] = 1; led_red[i][4][3] = 1;
          led_red[i][0][2] = 1; led_red[i][2][2] = 1; led_red[i][4][2] = 1;
          led_red[i][0][1] = 1; led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][0][0] = 1; led_red[i][4][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][4] = 1; led_gre[i][4][4] = 1;
          led_gre[i][0][3] = 1; led_gre[i][3][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][0][2] = 1; led_gre[i][2][2] = 1; led_gre[i][4][2] = 1;
          led_gre[i][0][1] = 1; led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][0][0] = 1; led_gre[i][4][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][4] = 1; led_blu[i][4][4] = 1;
          led_blu[i][0][3] = 1; led_blu[i][3][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][0][2] = 1; led_blu[i][2][2] = 1; led_blu[i][4][2] = 1;
          led_blu[i][0][1] = 1; led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][0][0] = 1; led_blu[i][4][0] = 1;
        }
        break;
      case 11:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][0][3] = 1; led_red[i][4][3] = 1;
          led_red[i][0][3] = 1; led_red[i][4][3] = 1;
          led_red[i][0][3] = 1; led_red[i][4][3] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][0][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][0][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][0][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][0][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][0][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][0][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 10:
        if (color % 2) {
          led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][3][1] = 1;
          led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][3][1] = 1;
          led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][3][1] = 1;
          led_blu[i][3][0] = 1;
        }
        break;
      case 9:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][0][3] = 1; led_red[i][4][3] = 1;
          led_red[i][0][2] = 1; led_red[i][2][2] = 1; led_red[i][4][2] = 1;
          led_red[i][0][1] = 1; led_red[i][1][1] = 1; led_red[i][4][1] = 1;
          led_red[i][0][0] = 1; led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][0][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][0][2] = 1; led_gre[i][2][2] = 1; led_gre[i][4][2] = 1;
          led_gre[i][0][1] = 1; led_gre[i][1][1] = 1; led_gre[i][4][1] = 1;
          led_gre[i][0][0] = 1; led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][0][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][0][2] = 1; led_blu[i][2][2] = 1; led_blu[i][4][2] = 1;
          led_blu[i][0][1] = 1; led_blu[i][1][1] = 1; led_blu[i][4][1] = 1;
          led_blu[i][0][0] = 1; led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 8:
        if (color % 2) {
          led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][0][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][0][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][0][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 7:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1;
          led_red[i][4][3] = 1;
          led_red[i][1][2] = 1; led_red[i][2][2] = 1; led_red[i][3][2] = 1;
          led_red[i][0][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][4][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][2][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][0][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][4][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][2][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][0][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 6:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1; led_red[i][4][4] = 1;
          led_red[i][2][3] = 1;
          led_red[i][2][2] = 1;
          led_red[i][2][1] = 1;
          led_red[i][2][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][3] = 1; led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1; led_gre[i][4][3] = 1;
          led_gre[i][2][3] = 1;
          led_gre[i][2][2] = 1;
          led_gre[i][2][1] = 1;
          led_gre[i][2][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][3] = 1; led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1; led_blu[i][4][3] = 1;
          led_blu[i][2][3] = 1;
          led_blu[i][2][2] = 1;
          led_blu[i][2][1] = 1;
          led_blu[i][2][0] = 1;
        }
        break;
      case 5:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1; led_red[i][3][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1;  led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1; led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1;  led_gre[i][3][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 4:
        if (color % 2) {
          led_red[i][1][4] = 1; led_red[i][3][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][1][2] = 1;  led_red[i][3][2] = 1;
          led_red[i][1][1] = 1;  led_red[i][3][1] = 1;
          led_red[i][2][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][1][4] = 1; led_gre[i][3][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][1][2] = 1;  led_gre[i][3][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][2][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][1][4] = 1; led_blu[i][3][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][1][2] = 1; led_blu[i][3][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][2][0] = 1;
        }
        break;
      case 3:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][2][4] = 1; led_red[i][4][4] = 1;
          led_red[i][0][3] = 1; led_red[i][2][3] = 1; led_red[i][4][3] = 1;
          led_red[i][0][2] = 1; led_red[i][2][2] = 1; led_red[i][4][2] = 1;
          led_red[i][0][1] = 1; led_red[i][2][1] = 1; led_red[i][4][1] = 1;
          led_red[i][1][0] = 1; led_red[i][3][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][4] = 1; led_gre[i][2][4] = 1; led_gre[i][4][4] = 1;
          led_gre[i][0][3] = 1; led_gre[i][2][3] = 1; led_gre[i][4][3] = 1;
          led_gre[i][0][2] = 1; led_gre[i][2][2] = 1; led_gre[i][4][2] = 1;
          led_gre[i][0][1] = 1; led_gre[i][2][1] = 1; led_gre[i][4][1] = 1;
          led_gre[i][1][0] = 1; led_gre[i][3][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][4] = 1; led_blu[i][2][4] = 1; led_blu[i][4][4] = 1;
          led_blu[i][0][3] = 1; led_blu[i][2][3] = 1; led_blu[i][4][3] = 1;
          led_blu[i][0][2] = 1; led_blu[i][2][2] = 1; led_blu[i][4][2] = 1;
          led_blu[i][0][1] = 1; led_blu[i][2][1] = 1; led_blu[i][4][1] = 1;
          led_blu[i][1][0] = 1; led_blu[i][3][0] = 1;
        }
        break;
      case 2:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][4][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][2][2] = 1;
          led_red[i][1][1] = 1; led_red[i][3][1] = 1;
          led_red[i][0][0] = 1; led_red[i][4][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][4] = 1; led_gre[i][4][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][2][2] = 1;
          led_gre[i][1][1] = 1; led_gre[i][3][1] = 1;
          led_gre[i][0][0] = 1; led_gre[i][4][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][4] = 1; led_blu[i][4][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][2][2] = 1;
          led_blu[i][1][1] = 1; led_blu[i][3][1] = 1;
          led_blu[i][0][0] = 1; led_blu[i][4][0] = 1;
        }
        break;
      case 1:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][4][4] = 1;
          led_red[i][1][3] = 1; led_red[i][3][3] = 1;
          led_red[i][2][2] = 1;
          led_red[i][2][1] = 1;
          led_red[i][2][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][4] = 1; led_gre[i][4][4] = 1;
          led_gre[i][1][3] = 1; led_gre[i][3][3] = 1;
          led_gre[i][2][2] = 1;
          led_gre[i][2][1] = 1;
          led_gre[i][2][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][4] = 1; led_blu[i][4][4] = 1;
          led_blu[i][1][3] = 1; led_blu[i][3][3] = 1;
          led_blu[i][2][2] = 1;
          led_blu[i][2][1] = 1;
          led_blu[i][2][0] = 1;
        }
        break;
      case 0:
        if (color % 2) {
          led_red[i][0][4] = 1; led_red[i][1][4] = 1; led_red[i][2][4] = 1; led_red[i][3][4] = 1; led_red[i][4][4] = 1;
          led_red[i][1][3] = 1;
          led_red[i][2][2] = 1;
          led_red[i][3][1] = 1;
          led_red[i][0][0] = 1; led_red[i][1][0] = 1; led_red[i][2][0] = 1; led_red[i][3][0] = 1; led_red[i][4][0] = 1;
        }
        if ((color / 2) % 2) {
          led_gre[i][0][4] = 1; led_gre[i][1][4] = 1; led_gre[i][2][4] = 1; led_gre[i][3][4] = 1; led_gre[i][4][4] = 1;
          led_gre[i][1][3] = 1;
          led_gre[i][2][2] = 1;
          led_gre[i][3][1] = 1;
          led_gre[i][0][0] = 1; led_gre[i][1][0] = 1; led_gre[i][2][0] = 1; led_gre[i][3][0] = 1; led_gre[i][4][0] = 1;
        }
        if ((color / 4) % 2) {
          led_blu[i][0][4] = 1; led_blu[i][1][4] = 1; led_blu[i][2][4] = 1; led_blu[i][3][4] = 1; led_blu[i][4][4] = 1;
          led_blu[i][1][3] = 1;
          led_blu[i][2][2] = 1;
          led_blu[i][3][1] = 1;
          led_blu[i][0][0] = 1; led_blu[i][1][0] = 1; led_blu[i][2][0] = 1; led_blu[i][3][0] = 1; led_blu[i][4][0] = 1;
        }
        break;
    }
    delay(100);
    //delay(100);
  }
  //delay(100);
}

void EneLED::led_boxes(int w) {
  led_clear();
  switch (w) {
    case 0:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
    case 1:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
    case 2:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
    case 3:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 0; k < p; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
    case 4:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
    case 5:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 0; i < p; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
    case 6:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 5 - p; j < 5; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
    case 7:
      for (int p = 5; p > 0; p--) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      for (int p = 0; p < 5; p++) {
        if (color % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_red[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 2) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_blu[i][j][k] = 1;
              }
            }
          }
        }
        if ((color / 4) % 2) {
          for (int i = 5 - p; i < 5; i++) {
            for (int j = 0; j < p; j++) {
              for (int k = 5 - p; k < 5; k++) {
                led_gre[i][j][k] = 1;
              }
            }
          }
        }
        delay(100);
        led_clear();
      }
      break;
  }
}

void EneLED::led_jiwajiwa(int w) {
  switch (w % 2) {
    case 0:
      for (int u = 0; u < 123; u++) {
        int o = 0;
        while (o == 0) {
          int i = random(5);
          int j = random(5);
          int k = random(5);
          if (led_red[i][j][k] == 0) {
            led_red[i][j][k] = 1;
            o = 1;
          }
        }
        o = 0;
        while (o == 0) {
          int i1 = random(5);
          int j1 = random(5);
          int k1 = random(5);
          if (led_blu[i1][j1][k1] == 0) {
            led_blu[i1][j1][k1] = 1;
            o = 1;
          }
        }
        o = 0;
        while (o == 0) {
          int i2 = random(5);
          int j2 = random(5);
          int k2 = random(5);
          if (led_gre[i2][j2][k2] == 0) {
            led_gre[i2][j2][k2] = 1;
            o = 1;
          }
        }
        o = 0;
        delay(10);
      }
      delay(200);
      break;
    case 1:
      for (int u = 0; u < 123; u++) {
        int o = 0;
        while (o == 0) {
          int i = random(5);
          int j = random(5);
          int k = random(5);
          if (led_red[i][j][k] == 1) {
            led_red[i][j][k] = 0;
            o = 1;
          }
        }
        o = 0;
        while (o == 0) {
          int i1 = random(5);
          int j1 = random(5);
          int k1 = random(5);
          if (led_blu[i1][j1][k1] == 1) {
            led_blu[i1][j1][k1] = 0;
            o = 1;
          }
        }
        o = 0;
        while (o == 0) {
          int i2 = random(5);
          int j2 = random(5);
          int k2 = random(5);
          if (led_gre[i2][j2][k2] == 1) {
            led_gre[i2][j2][k2] = 0;
            o = 1;
          }
        }
        o = 0;
        delay(10);
      }
      delay(200);
      break;
  }
}


void EneLED::output() {////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  pattern_count++;
  if (pattern_count > 10)pattern_count = 0;
  led_swap(pattern_count % 5);
  switch (pattern_count % 5) {
    case 0:
      switch (board_no) {
        case 1:
          SPI.transfer(0x01);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x09);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 2:
          SPI.transfer(0x00);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x01);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 3:
          SPI.transfer(0x01);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x09);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
      }
      break;
    case 1:
      switch (board_no) {
        case 1:
          SPI.transfer(0x28);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x80);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 2:
          SPI.transfer(0x00);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x02);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 3:
          SPI.transfer(0x02);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x02);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
      }
      break;
    case 2:
      switch (board_no) {
        case 1:
          SPI.transfer(0x50);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x40);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 2:
          SPI.transfer(0x00);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x04);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 3:
          SPI.transfer(0x08);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x80);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
      }
      break;
    case 3:
      switch (board_no) {
        case 1:
          SPI.transfer(0x84);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x24);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 2:
          SPI.transfer(0x00);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x40);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 3:
          SPI.transfer(0xa0);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x40);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
      }
      break;
    case 4:
      switch (board_no) {
        case 1:
          SPI.transfer(0x02);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x12);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 2:
          SPI.transfer(0x00);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x80);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 3:
          SPI.transfer(0x04);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          SPI.transfer(0x24);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
      }
      break;
  }
  for (int i = 0; i < 15; i++) {
    SPI.transfer(PATTERNS[i]);
    digitalWrite(6,  LOW);
    digitalWrite(6,  HIGH);
  }
}

void EneLED::led_swap(int stage) {
  switch (board_no) {
    case 1:
      PATTERNS[0] = {2 * led_red[1][4][stage] + 4 * led_red[0][4][stage] + 8 * led_red[2][4][stage]
                     + 16 * led_red[3][4][stage] + 32 * led_red[4][4][stage]
                  };
      PATTERNS[1] = {2 * led_red[1][3][stage] + 4 * led_red[0][3][stage] + 8 * led_red[2][3][stage]
                     + 16 * led_red[3][3][stage] + 32 * led_red[4][3][stage]
                  };
      PATTERNS[2] = {2 * led_red[1][2][stage] + 4 * led_red[0][2][stage] + 8 * led_red[2][2][stage]
                     + 16 * led_red[3][2][stage] + 32 * led_red[4][2][stage]
                  };
      PATTERNS[3] = {2 * led_red[1][1][stage] + 4 * led_red[0][1][stage] + 8 * led_red[2][1][stage]
                     + 16 * led_red[3][1][stage] + 32 * led_red[4][1][stage]
                  };
      PATTERNS[4] = {2 * led_red[1][0][stage] + 4 * led_red[0][0][stage] + 8 * led_red[2][0][stage]
                     + 16 * led_red[3][0][stage] + 32 * led_red[4][0][stage]
                  };

      PATTERNS[5] = {2 * led_blu[1][4][stage] + 4 * led_blu[0][4][stage] + 8 * led_blu[2][4][stage]
                     + 16 * led_blu[3][4][stage] + 32 * led_blu[4][4][stage]
                  };
      PATTERNS[6] = {2 * led_blu[1][3][stage] + 4 * led_blu[0][3][stage] + 8 * led_blu[2][3][stage]
                     + 16 * led_blu[3][3][stage] + 32 * led_blu[4][3][stage]
                  };
      PATTERNS[7] = {2 * led_blu[1][2][stage] + 4 * led_blu[0][2][stage] + 8 * led_blu[2][2][stage]
                     + 16 * led_blu[3][2][stage] + 32 * led_blu[4][2][stage]
                  };
      PATTERNS[8] = {2 * led_blu[1][1][stage] + 4 * led_blu[0][1][stage] + 8 * led_blu[2][1][stage]
                     + 16 * led_blu[3][1][stage] + 32 * led_blu[4][1][stage]
                  };
      PATTERNS[9] = {2 * led_blu[1][0][stage] + 4 * led_blu[0][0][stage] + 8 * led_blu[2][0][stage]
                     + 16 * led_blu[3][0][stage] + 32 * led_blu[4][0][stage]
                  };

      PATTERNS[10] = {2 * led_gre[1][4][stage] + 4 * led_gre[0][4][stage] + 8 * led_gre[4][4][stage]
                      + 16 * led_gre[3][4][stage] + 32 * led_gre[2][4][stage]
                   };
      PATTERNS[11] = {2 * led_gre[1][3][stage] + 4 * led_gre[0][3][stage] + 8 * led_gre[4][3][stage]
                      + 16 * led_gre[3][3][stage] + 32 * led_gre[2][3][stage]
                   };
      PATTERNS[12] = {2 * led_gre[1][2][stage] + 4 * led_gre[0][2][stage] + 8 * led_gre[4][2][stage]
                      + 16 * led_gre[3][2][stage] + 32 * led_gre[2][2][stage]
                   };
      PATTERNS[13] = {2 * led_gre[1][1][stage] + 4 * led_gre[0][1][stage] + 8 * led_gre[4][1][stage]
                      + 16 * led_gre[3][1][stage] + 32 * led_gre[2][1][stage]
                   };
      PATTERNS[14] = {2 * led_gre[1][0][stage] + 4 * led_gre[0][0][stage] + 8 * led_gre[4][0][stage]
                      + 16 * led_gre[3][0][stage] + 32 * led_gre[2][0][stage]
                   };
      break;
    case 2:
      PATTERNS[0] = {2 * led_red[1][4][stage] + 4 * led_red[0][4][stage] + 8 * led_red[2][4][stage]
                     + 16 * led_red[3][4][stage] + 32 * led_red[4][4][stage]
                  };
      PATTERNS[1] = {2 * led_red[1][3][stage] + 4 * led_red[0][3][stage] + 8 * led_red[2][3][stage]
                     + 16 * led_red[3][3][stage] + 32 * led_red[4][3][stage]
                  };
      PATTERNS[2] = {2 * led_red[1][2][stage] + 4 * led_red[0][2][stage] + 8 * led_red[2][2][stage]
                     + 16 * led_red[3][2][stage] + 32 * led_red[4][2][stage]
                  };
      PATTERNS[3] = {2 * led_red[1][1][stage] + 4 * led_red[0][1][stage] + 8 * led_red[2][1][stage]
                     + 16 * led_red[3][1][stage] + 32 * led_red[4][1][stage]
                  };
      PATTERNS[4] = {2 * led_red[1][0][stage] + 4 * led_red[0][0][stage] + 8 * led_red[2][0][stage]
                     + 16 * led_red[3][0][stage] + 32 * led_red[4][0][stage]
                  };

      PATTERNS[5] = {2 * led_blu[1][4][stage] + 4 * led_blu[0][4][stage] + 8 * led_blu[4][4][stage]
                     + 16 * led_blu[3][4][stage] + 32 * led_blu[2][4][stage]
                  };
      PATTERNS[6] = {2 * led_blu[1][3][stage] + 4 * led_blu[0][3][stage] + 8 * led_blu[4][3][stage]
                     + 16 * led_blu[3][3][stage] + 32 * led_blu[2][3][stage]
                  };
      PATTERNS[7] = {2 * led_blu[1][2][stage] + 4 * led_blu[0][2][stage] + 8 * led_blu[4][2][stage]
                     + 16 * led_blu[3][2][stage] + 32 * led_blu[2][2][stage]
                  };
      PATTERNS[8] = {2 * led_blu[1][1][stage] + 4 * led_blu[0][1][stage] + 8 * led_blu[4][1][stage]
                     + 16 * led_blu[3][1][stage] + 32 * led_blu[2][1][stage]
                  };
      PATTERNS[9] = {2 * led_blu[1][0][stage] + 4 * led_blu[0][0][stage] + 8 * led_blu[4][0][stage]
                     + 16 * led_blu[3][0][stage] + 32 * led_blu[2][0][stage]
                  };

      PATTERNS[10] = {2 * led_gre[1][4][stage] + 4 * led_gre[0][4][stage] + 8 * led_gre[2][4][stage]
                      + 16 * led_gre[3][4][stage] + 32 * led_gre[4][4][stage]
                   };
      PATTERNS[11] = {2 * led_gre[1][3][stage] + 4 * led_gre[0][3][stage] + 8 * led_gre[2][3][stage]
                      + 16 * led_gre[3][3][stage] + 32 * led_gre[4][3][stage]
                   };
      PATTERNS[12] = {2 * led_gre[1][2][stage] + 4 * led_gre[0][2][stage] + 8 * led_gre[2][2][stage]
                      + 16 * led_gre[3][2][stage] + 32 * led_gre[4][2][stage]
                   };
      PATTERNS[13] = {2 * led_gre[1][1][stage] + 4 * led_gre[0][1][stage] + 8 * led_gre[2][1][stage]
                      + 16 * led_gre[3][1][stage] + 32 * led_gre[4][1][stage]
                   };
      PATTERNS[14] = {2 * led_gre[1][0][stage] + 4 * led_gre[0][0][stage] + 8 * led_gre[2][0][stage]
                      + 16 * led_gre[3][0][stage] + 32 * led_gre[4][0][stage]
                   };
      break;
    case 3:
      PATTERNS[0] = {2 * led_red[3][4][stage] + 4 * led_red[4][4][stage] + 8 * led_red[2][4][stage]
                     + 16 * led_red[1][4][stage] + 32 * led_red[0][4][stage]
                  };
      PATTERNS[1] = {2 * led_red[3][3][stage] + 4 * led_red[4][3][stage] + 8 * led_red[2][3][stage]
                     + 16 * led_red[1][3][stage] + 32 * led_red[0][3][stage]
                  };
      PATTERNS[2] = {2 * led_red[3][2][stage] + 4 * led_red[4][2][stage] + 8 * led_red[2][2][stage]
                     + 16 * led_red[1][2][stage] + 32 * led_red[0][2][stage]
                  };
      PATTERNS[3] = {2 * led_red[3][1][stage] + 4 * led_red[4][1][stage] + 8 * led_red[2][1][stage]
                     + 16 * led_red[1][1][stage] + 32 * led_red[0][1][stage]
                  };
      PATTERNS[4] = {2 * led_red[3][0][stage] + 4 * led_red[4][0][stage] + 8 * led_red[2][0][stage]
                     + 16 * led_red[1][0][stage] + 32 * led_red[0][0][stage]
                  };

      PATTERNS[5] = {2 * led_blu[3][4][stage] + 4 * led_blu[4][4][stage] + 8 * led_blu[2][4][stage]
                     + 16 * led_blu[1][4][stage] + 32 * led_blu[0][4][stage]
                  };
      PATTERNS[6] = {2 * led_blu[3][3][stage] + 4 * led_blu[4][3][stage] + 8 * led_blu[2][3][stage]
                     + 16 * led_blu[1][3][stage] + 32 * led_blu[0][3][stage]
                  };
      PATTERNS[7] = {2 * led_blu[3][2][stage] + 4 * led_blu[4][2][stage] + 8 * led_blu[2][2][stage]
                     + 16 * led_blu[1][2][stage] + 32 * led_blu[0][2][stage]
                  };
      PATTERNS[8] = {2 * led_blu[3][1][stage] + 4 * led_blu[4][1][stage] + 8 * led_blu[2][1][stage]
                     + 16 * led_blu[1][1][stage] + 32 * led_blu[0][1][stage]
                  };
      PATTERNS[9] = {2 * led_blu[3][0][stage] + 4 * led_blu[4][0][stage] + 8 * led_blu[2][0][stage]
                     + 16 * led_blu[1][0][stage] + 32 * led_blu[0][0][stage]
                  };

      PATTERNS[10] = {2 * led_gre[3][4][stage] + 4 * led_gre[4][4][stage] + 8 * led_gre[2][4][stage]
                      + 16 * led_gre[1][4][stage] + 32 * led_gre[0][4][stage]
                   };
      PATTERNS[11] = {2 * led_gre[3][3][stage] + 4 * led_gre[4][3][stage] + 8 * led_gre[2][3][stage]
                      + 16 * led_gre[1][3][stage] + 32 * led_gre[0][3][stage]
                   };
      PATTERNS[12] = {2 * led_gre[3][2][stage] + 4 * led_gre[4][2][stage] + 8 * led_gre[2][2][stage]
                      + 16 * led_gre[1][2][stage] + 32 * led_gre[0][2][stage]
                   };
      PATTERNS[13] = {2 * led_gre[3][1][stage] + 4 * led_gre[4][1][stage] + 8 * led_gre[2][1][stage]
                      + 16 * led_gre[1][1][stage] + 32 * led_gre[0][1][stage]
                   };
      PATTERNS[14] = {2 * led_gre[3][0][stage] + 4 * led_gre[4][0][stage] + 8 * led_gre[2][0][stage]
                      + 16 * led_gre[1][0][stage] + 32 * led_gre[0][0][stage]
                   };
      break;
  }
}
