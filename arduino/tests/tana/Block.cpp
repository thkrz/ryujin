#include "Block.h"

#define VOLT(x) ((x)*5.0/1023.0)

static String& Block::CONCAT(float *x, int len) {
  static String s;

  s = "";
  for (int i = 0; i < len; i++) {
    if (x[i] >= 0)
      s += '+';
    s += x[i];
  }
  return s;
}

Block::Block(int8_t d, int8_t a, int8_t b) {
  pinMode(d, INPUT_PULLUP);
  _dip = d;
  _pin[0] = a;
  _pin[1] = b;
}

bool Block::isConnected() {
  return digitalRead(_dip) == LOW;
}

void Block::readSample(int num) {
  for (int i = 0; i < 2; i++) {
    _u[i] = 0;
    analogRead(_pin[i]);
    for (int n = 0; n < num; n++)
      _u[i] += VOLT(analogRead(_pin[i]));
    _u[i] /= num;
  }
}
