/*
  Softera Lab · Matrix Solder Kit · SK-75
  Static patterns + simple bounce — good first flash / soldering check.

  Same pin map as SK75_Demo:
    DIN = D0 (PB0) · CS = D3 (PB3) · CLK = D2 (PB2)
*/

#include "SoftteraMax7219.h"

static const uint8_t PIN_DIN = 0;
static const uint8_t PIN_CS  = 3;
static const uint8_t PIN_CLK = 2;

SoftteraMax7219 matrix(PIN_DIN, PIN_CS, PIN_CLK, 1);

const uint8_t PATTERNS[][8] PROGMEM = {
  { // checker
    0b10101010, 0b01010101, 0b10101010, 0b01010101,
    0b10101010, 0b01010101, 0b10101010, 0b01010101
  },
  { // cross
    0b00011000, 0b00011000, 0b00011000, 0b11111111,
    0b11111111, 0b00011000, 0b00011000, 0b00011000
  },
  { // border
    0b11111111, 0b10000001, 0b10000001, 0b10000001,
    0b10000001, 0b10000001, 0b10000001, 0b11111111
  },
  { // diagonal
    0b10000000, 0b01000000, 0b00100000, 0b00010000,
    0b00001000, 0b00000100, 0b00000010, 0b00000001
  }
};

void showPat(uint8_t idx) {
  for (uint8_t r = 0; r < 8; r++) {
    matrix.setRow(0, r, pgm_read_byte(&PATTERNS[idx][r]));
  }
  matrix.show();
}

void setup() {
  matrix.begin(5);
}

void loop() {
  for (uint8_t i = 0; i < 4; i++) {
    showPat(i);
    delay(700);
  }

  // bouncing pixel
  int8_t x = 0, y = 0, dx = 1, dy = 1;
  for (uint8_t n = 0; n < 64; n++) {
    matrix.clear();
    matrix.setPixel(x, y, true);
    matrix.show();
    x = (int8_t)(x + dx);
    y = (int8_t)(y + dy);
    if (x <= 0 || x >= 7) dx = (int8_t)-dx;
    if (y <= 0 || y >= 7) dy = (int8_t)-dy;
    delay(55);
  }
}
