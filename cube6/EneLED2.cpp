#include <Arduino.h>
#include "EneLED2.h"

EneLED::EneLED(void) {
}

void EneLED::init(int board) {
  pattern_count = 0;
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

void EneLED::led_test() {
  for (int i = 0; i < 5; i++) {
    led_clear();
    for (int j = 0; j < 5; j++) {
      led_red[abs(j - 4)][j][(j - i + 5) % 5] = 1;
      led_gre[j][j][(j - i + 5) % 5] = 1;
      led_blu[j][abs(j - 4)][(j - i + 5) % 5] = 1;
    }
    delay(300);
  }
}

void EneLED::led_test2(int color) {//ガチのテスト用
  led_clear();
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      led_red[i][3][j] = 1;
    }
  }
  delay(300);
}

void EneLED::led_xaxis(int color) {
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

void EneLED::led_yaxis(int color) {
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

void EneLED::led_zaxis(int color) {
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

void EneLED::led_xaxis_rev(int color) {
  for (int i = 4; i > -1; i--) {
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

void EneLED::led_yaxis_rev(int color) {
  for (int i = 4; i > -1; i--) {
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

void EneLED::led_zaxis_rev(int color) {
  for (int i = 4; i > -1; i--) {
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

void EneLED::led_full(int color) {
  led_clear();
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

void EneLED::led_rotate(int color) {//くるくる回る(予定)の奴
  for (int k = 4; k > -1; k--) {
    int i = 0, j = 0;
    for (i = 0; i < 4; i++) {
      led_clear();
      if (color % 2) {
        led_red[i][j][k] = 1;
      }
      if ((color / 2) % 2) {
        led_gre[i][j][k] = 1;
      }
      if ((color / 4) % 2) {
        led_blu[i][j][k] = 1;
      }
      delay(50);
    }
    i = 4;
    for (j = 0; j < 4; j++) {
      led_clear();
      if (color % 2) {
        led_red[i][j][k] = 1;
      }
      if ((color / 2) % 2) {
        led_gre[i][j][k] = 1;
      }
      if ((color / 4) % 2) {
        led_blu[i][j][k] = 1;
      }
      delay(50);
    }
    j = 4;
    for (i = 4; i > 0; i--) {
      led_clear();
      if (color % 2) {
        led_red[i][j][k] = 1;
      }
      if ((color / 2) % 2) {
        led_gre[i][j][k] = 1;
      }
      if ((color / 4) % 2) {
        led_blu[i][j][k] = 1;
      }
      delay(50);
    }
    for (j = 4; j > 0; j--) {
      led_clear();
      if (color % 2) {
        led_red[i][j][k] = 1;
      }
      if ((color / 2) % 2) {
        led_gre[i][j][k] = 1;
      }
      if ((color / 4) % 2) {
        led_blu[i][j][k] = 1;
      }
      delay(50);
    }
  }
}

void EneLED::output() {
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
          SPI.transfer(0x20);
          digitalWrite(6,  LOW);
          digitalWrite(6,  HIGH);
          break;
        case 3:
          SPI.transfer(0x48);
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
          SPI.transfer(0xA0);
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
