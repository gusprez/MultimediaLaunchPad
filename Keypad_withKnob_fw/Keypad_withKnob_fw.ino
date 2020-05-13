/*
  Copyright (c) 2020 Gusprez

  Main code for a keypad with 8 buttons and an encoder.
  Using an Atmega32ua.

  See HID Project documentation for more examples.
  https://github.com/NicoHood/HID/wiki/Consumer-API
*/

#include "HID-Project.h"

// PIN numbers (CONSTANTS)



const uint8_t ENCODER_A  = 14; // rotary encoder: right
const uint8_t ENCODER_B  = 15; // rotary encoder: left
const uint8_t ENCODER_SW = 16; // rotary encoder: button

enum Switch_pos {
    BR_PIN = 3, // bottom row: right
    BL_PIN,     // bottom row: left
    MR_PIN,     // middle row: right
    MC_PIN,     // middle row: center
    ML_PIN,     // middle row: left
    TL_PIN,     // top row: left
    TC_PIN,     // top row: center
    TR_PIN      // top row: right
};

const uint8_t pinLed = LED_BUILTIN;
const uint8_t PIN = MRPIN;

void setup() {
    pinMode( pinLed, OUTPUT );
    pinMode( PIN, INPUT_PULLUP );
    // Sends a clean report to the host. This is important on any Arduino type.
    Consumer.begin();

}

void loop() {
    static unsigned long lastChange = 0;


    if ( digitalRead( PIN ) == LOW && ( millis() - lastChange > 250 ) ) {
        lastChange = millis();
        digitalWrite( pinLed, HIGH );
        Consumer.write(MEDIA_PLAY_PAUSE);
    }
    else {
        digitalWrite( pinLed, LOW );
    }
}
