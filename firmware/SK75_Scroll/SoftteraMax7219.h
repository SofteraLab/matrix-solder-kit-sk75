/*
  Softtera Lab · Matrix Solder Kit SK-75
  Bit-bang MAX7219 driver for ATtiny85 / 45 / 25 (Arduino pin numbers).

  Default SoftSPI (change in the sketch if your PCB revision differs):
    DIN → PB0  (Arduino D0, physical pin 5 / MOSI)
    CS  → PB3  (Arduino D3, physical pin 2)
    CLK → PB2  (Arduino D2, physical pin 7 / SCK)

  Expansion silkscreen: GND · OUT · 5V · CS · IN · SCK
  Daisy-chain: OUT of this board → IN of the next (share 5V, GND, CS, SCK).
*/

#pragma once
#include <Arduino.h>

class SoftteraMax7219 {
public:
  SoftteraMax7219(uint8_t dinPin, uint8_t csPin, uint8_t clkPin, uint8_t deviceCount = 1)
    : _din(dinPin), _cs(csPin), _clk(clkPin), _devices(deviceCount) {}

  void begin(uint8_t intensity = 5) {
    pinMode(_din, OUTPUT);
    pinMode(_cs, OUTPUT);
    pinMode(_clk, OUTPUT);
    digitalWrite(_cs, HIGH);
    digitalWrite(_clk, LOW);
    digitalWrite(_din, LOW);

    writeAll(0x0C, 0x00); // shutdown while init
    writeAll(0x0F, 0x00); // test off
    writeAll(0x09, 0x00); // no BCD decode
    writeAll(0x0B, 0x07); // scan digits 0..7
    setIntensity(intensity);
    clear();
    writeAll(0x0C, 0x01); // normal op
  }

  void setIntensity(uint8_t v) {
    if (v > 15) v = 15;
    writeAll(0x0A, v);
  }

  uint8_t deviceCount() const { return _devices; }

  void clear() {
    for (uint8_t d = 0; d < _devices; d++) {
      for (uint8_t r = 0; r < 8; r++) _buf[d][r] = 0;
    }
    show();
  }

  void setPixel(int8_t x, int8_t y, bool on) {
    if (y < 0 || y > 7 || x < 0) return;
    uint8_t d = (uint8_t)x / 8;
    uint8_t col = (uint8_t)x % 8;
    if (d >= _devices) return;
    uint8_t mask = (uint8_t)(1 << (7 - col));
    if (on) _buf[d][y] |= mask;
    else _buf[d][y] &= (uint8_t)~mask;
  }

  void setRow(uint8_t device, uint8_t row, uint8_t value) {
    if (device >= _devices || row > 7) return;
    _buf[device][row] = value;
  }

  void fill(bool on) {
    uint8_t v = on ? 0xFF : 0x00;
    for (uint8_t d = 0; d < _devices; d++) {
      for (uint8_t r = 0; r < 8; r++) _buf[d][r] = v;
    }
    show();
  }

  void show() {
    for (uint8_t row = 0; row < 8; row++) {
      digitalWrite(_cs, LOW);
      for (int8_t d = (int8_t)_devices - 1; d >= 0; d--) {
        shiftOutByte((uint8_t)(row + 1));
        shiftOutByte(_buf[d][row]);
      }
      digitalWrite(_cs, HIGH);
    }
  }

private:
  static const uint8_t kMax = 4;
  uint8_t _din, _cs, _clk, _devices;
  uint8_t _buf[kMax][8];

  void shiftOutByte(uint8_t value) {
    for (int8_t i = 7; i >= 0; i--) {
      digitalWrite(_din, (value >> i) & 1);
      digitalWrite(_clk, HIGH);
      digitalWrite(_clk, LOW);
    }
  }

  void writeAll(uint8_t reg, uint8_t data) {
    digitalWrite(_cs, LOW);
    for (uint8_t d = 0; d < _devices; d++) {
      shiftOutByte(reg);
      shiftOutByte(data);
    }
    digitalWrite(_cs, HIGH);
  }
};
