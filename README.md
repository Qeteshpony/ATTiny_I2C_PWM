# I2C PWM for ATtiny25/45/85

A very simple Arduino sketch that turns an ATtiny25/45/85 into a simple I2C PWM generator to control LEDs. 

Nothing fancy but it works if you, like me, have tons of ATtiny85s in your drawer but no dedicated pwm ICs...

I think the sketch is self explaining but in short:

The device listens on I2C Address 0x20

Register 0x10 can have its LSB set to 1 or 0 to turn the pwm on or off without losing the settings. All other bits are ignored.

Register 0x11 sets the duty cycle from 0 to 255

You will need [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore) to make this work. 
