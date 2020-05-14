/*
  Copyright (c) 2020 Gusprez

  Main code for a keypad with 8 buttons and an encoder.
  Using an Atmega32ua.

  See HID Project documentation for more examples.
  https://github.com/NicoHood/HID/wiki/Consumer-API
*/

#include "HID-Project.h"

// PIN numbers
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
const uint8_t number_of_switches = 8;
// Switch_pos switch_pos;
// Encode channels
const uint8_t ENCODER_A  = 14; // rotary encoder: right
const uint8_t ENCODER_B  = 15; // rotary encoder: left
const uint8_t ENCODER_SW = 16; // rotary encoder: button

const uint8_t pinLed = LED_BUILTIN;

void setup() {
    for ( uint8_t ii = BR_PIN; ii < number_of_switches + BR_PIN; ++ii ) {
        pinMode( ii, INPUT_PULLUP );
    }
    pinMode( pinLed, OUTPUT );

    // Sends a clean report to the host. This is important on any Arduino type.
    Consumer.begin();

}

void loop() {
    static unsigned long lastChange = 0;
    for ( uint8_t ii = BR_PIN; ii < number_of_switches + BR_PIN; ++ii ) {
        if ( digitalRead( ii ) == LOW && ( millis() - lastChange > 250 ) ) {
            lastChange = millis();
            digitalWrite( pinLed, HIGH );
            switch ( ii ) { // Cases for each key
                case 3:
                    Consumer.write( HID_CONSUMER_AL_CALCULATOR );
                    break;
                case 4:
                    Consumer.write( HID_CONSUMER_AL_LOCAL_MACHINE_BROWSER );
                    break;
                case 5:
                    Consumer.write( CONSUMER_BROWSER_FORWARD );
                    break;
                case 6:
                    Consumer.write( CONSUMER_BROWSER_HOME );
                    break;
                case 7:
                    Consumer.write(  CONSUMER_BROWSER_BACK );
                    break;
                case 8:
                    Consumer.write( MEDIA_PREVIOUS );
                    break;
                case 9:
                    Consumer.write( MEDIA_PLAY_PAUSE );
                    break;
                case 10:
                    Consumer.write( MEDIA_NEXT );
                    break;
            }
        }
        else {
            digitalWrite( pinLed, LOW );
        }
    }
}
