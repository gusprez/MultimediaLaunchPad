/*
  Copyright (c) 2020 Gusprez

  Main code for a keypad with 8 buttons and an encoder.
  Using an Atmega32ua.

  See HID Project documentation for more examples.
  https://github.com/NicoHood/HID/wiki/Consumer-API
*/

#include "HID-Project.h"

// PIN numbers (CONSTANTS)
const uint8_t TLPIN      = 8;  // top row: left, center right
const uint8_t TCPIN      = 9;
const uint8_t TRPIN      = 10;
const uint8_t MLPIN      = 7;  // middle row: left, center, right
const uint8_t MCPIN      = 6;
const uint8_t MRPIN      = 5;
const uint8_t BLPIN      = 4;  // bottom row: left, right
const uint8_t BRPIN      = 3;
const uint8_t ENCODER_A  = 14; // rotary encoder: right
const uint8_t ENCODER_B  = 15; // rotary encoder: left
const uint8_t ENCODER_SW = 16; // rotary encoder: button

const int pinLed = LED_BUILTIN;
const uint8_t PIN = MRPIN;

void setup() {
    pinMode( pinLed, OUTPUT );
    pinMode( PIN, INPUT_PULLUP );
  // Sends a clean report to the host. This is important on any Arduino type.
  Consumer.begin();
  delay(500);
//   digitalWrite(pinLed, HIGH);
  // delay(500);
  // // See HID Project documentation for more Consumer keys
  // Consumer.write(MEDIA_PLAY_PAUSE);

  // digitalWrite(pinLed, LOW);
  // delay(500);
  // digitalWrite(pinLed, HIGH);

  // Consumer.write(MEDIA_PLAY_PAUSE);
  // digitalWrite(pinLed, LOW);
  // delay(500);
  // digitalWrite(pinLed, HIGH);
  // for ( uint8_t ii = 0; ii < 5; ++ii )
  //   Consumer.write(MEDIA_VOLUME_UP);
  // // Simple debounce
  // digitalWrite(pinLed, LOW);
  // delay(500);
  // digitalWrite(pinLed, HIGH);
  // for ( uint8_t ii = 0; ii < 5; ++ii )
  //   Consumer.write(MEDIA_VOLUME_DOWN);
  // digitalWrite(pinLed, LOW);
}

void loop() {
    static unsigned long lastChange = 0;
    if ( digitalRead( PIN ) == LOW && ( millis() - lastChange > 250 ) ) {
        lastChange = millis();
        Consumer.write(MEDIA_PLAY_PAUSE);
        digitalWrite( pinLed, HIGH );
        // delay(500);
    }
    else {
        digitalWrite( pinLed, LOW );
    }
}
