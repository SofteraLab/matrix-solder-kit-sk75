/*
  Softera Lab · Matrix Solder Kit · SK-75
  Demo firmware for on-board ATtiny85 / 45 / 25 + MAX7219 (8×8)

  Arduino IDE:
    Board ………… ATtiny85 (ATTinyCore or similar)
    Clock ……… Internal 8 MHz
    Programmer … USBasp / Arduino as ISP → ISP/RST header
    Upload ……… Upload Using Programmer

  SoftSPI pins (Arduino numbers → ATtiny Port B):
    DIN = D0 (PB0) · CS = D3 (PB3) · CLK = D2 (PB2)

  If the matrix stays blank after a correct flash, swap DIN/CS in the
  defines below to match your PCB routing, then reflash.
*/

#include "SoftteraMax7219.h"

static const uint8_t PIN_DIN = 0;  // PB0
static const uint8_t PIN_CS  = 3;  // PB3
static const uint8_t PIN_CLK = 2;  // PB2
static const uint8_t NUM_DEVICES = 1; // set >1 for daisy-chained modules

SoftteraMax7219 matrix(PIN_DIN, PIN_CS, PIN_CLK, NUM_DEVICES);

const uint8_t HEART[] PROGMEM = {
  0b00000000,
  0b01100110,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000,
  0b00000000
};

const uint8_t SMILE[] PROGMEM = {
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100
};

void showBitmap(const uint8_t *bmp) {
  for (uint8_t r = 0; r < 8; r++) {
    matrix.setRow(0, r, pgm_read_byte(&bmp[r]));
  }
  matrix.show();
}

void effectRain(uint16_t ms) {
  uint8_t y[8];
  for (uint8_t i = 0; i < 8; i++) y[i] = i % 8;
  uint32_t t0 = millis();
  while (millis() - t0 < ms) {
    matrix.clear();
    for (uint8_t x = 0; x < 8 * NUM_DEVICES; x++) {
      matrix.setPixel(x, y[x % 8], true);
      y[x % 8] = (uint8_t)((y[x % 8] + 1) % 8);
    }
    matrix.show();
    delay(80);
  }
}

void effectSparkle(uint16_t ms) {
  uint32_t t0 = millis();
  while (millis() - t0 < ms) {
    matrix.setPixel(random(0, 8 * NUM_DEVICES), random(0, 8), true);
    matrix.show();
    delay(35);
    matrix.setPixel(random(0, 8 * NUM_DEVICES), random(0, 8), false);
    matrix.show();
    delay(25);
  }
  matrix.clear();
}

void effectSnake(uint16_t ms) {
  int8_t x = 0, y = 0, dx = 1, dy = 0;
  uint8_t trail[10][2];
  uint8_t len = 4;
  for (uint8_t i = 0; i < len; i++) { trail[i][0] = 0; trail[i][1] = 0; }
  uint32_t t0 = millis();
  while (millis() - t0 < ms) {
    x = (int8_t)(x + dx);
    y = (int8_t)(y + dy);
    if (x >= 8 * NUM_DEVICES) { x = (int8_t)(8 * NUM_DEVICES - 1); dx = 0; dy = 1; }
    if (y >= 8) { y = 7; dx = -1; dy = 0; }
    if (x < 0) { x = 0; dx = 0; dy = -1; }
    if (y < 0) { y = 0; dx = 1; dy = 0; }
    for (int8_t i = (int8_t)len - 1; i > 0; i--) {
      trail[i][0] = trail[i - 1][0];
      trail[i][1] = trail[i - 1][1];
    }
    trail[0][0] = (uint8_t)x;
    trail[0][1] = (uint8_t)y;
    matrix.clear();
    for (uint8_t i = 0; i < len; i++) matrix.setPixel(trail[i][0], trail[i][1], true);
    matrix.show();
    delay(60);
  }
}

void effectScanner(uint16_t ms) {
  uint32_t t0 = millis();
  while (millis() - t0 < ms) {
    for (uint8_t col = 0; col < 8 * NUM_DEVICES; col++) {
      matrix.clear();
      for (uint8_t y = 0; y < 8; y++) matrix.setPixel(col, y, true);
      matrix.show();
      delay(45);
    }
  }
}

void effectExpand(uint16_t ms) {
  uint32_t t0 = millis();
  while (millis() - t0 < ms) {
    for (int8_t r = 0; r < 5; r++) {
      matrix.clear();
      for (uint8_t y = 0; y < 8; y++) {
        for (uint8_t x = 0; x < 8 * NUM_DEVICES; x++) {
          int8_t dx = abs((int8_t)x - 4);
          int8_t dy = abs((int8_t)y - 4);
          if (dx == r || dy == r) matrix.setPixel(x, y, true);
        }
      }
      matrix.show();
      delay(100);
    }
  }
}

void setup() {
  matrix.begin(6);
  randomSeed(micros());
}

void loop() {
  showBitmap(HEART);
  delay(900);
  showBitmap(SMILE);
  delay(900);
  effectRain(2200);
  effectSparkle(1800);
  effectSnake(2800);
  effectScanner(1600);
  effectExpand(2000);
  matrix.fill(true);
  delay(250);
  matrix.clear();
  delay(200);
}
