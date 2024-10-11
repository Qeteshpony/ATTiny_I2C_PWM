#include <Wire.h>

// I2C Registers
#define SETON   0x10
#define SETPWM  0x11

// pin to use as output
#define PWMPIN  1

byte pwm = 0;
byte on = 0;

void setup() {
  Wire.begin(0x20);
  Wire.onReceive(ReceiveHandler);
  Wire.onRequest(RequestHandler);
  pinMode(PWMPIN, OUTPUT);
}

void loop() {
  // nothing to loop
}

void ReceiveHandler(size_t num) {
  if (Wire.available() >= 2) {
    char c = Wire.read();
    char v = Wire.read();
    if (c == SETON) {
      on = v % 2;
    }
    if (c == SETPWM) {
      pwm = c;
    }
    analogWrite(PWMPIN, pwm * on);
  }
}

void RequestHandler() {
  Wire.write(on);
  Wire.write(pwm);
}
