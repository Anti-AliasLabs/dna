/***************************************************
 * This is an example for our Adafruit 12-channel PWM/LED driver
 *
 * Pick one up today in the adafruit shop!
 * ------> http://www.adafruit.com/products/
 *
 * These drivers uses SPI to communicate, 2 pins are required to
 * interface: Data and Clock. The boards are chainable
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Limor Fried/Ladyada for Adafruit Industries.
 * BSD license, all text above must be included in any redistribution
 ****************************************************/

#include "Adafruit_TLC59711.h"
#include <SPI.h>

// How many boards do you have chained?
#define NUM_TLC59711 1

#define data   11
#define clock  13

Adafruit_TLC59711 tlc = Adafruit_TLC59711(NUM_TLC59711, clock, data);
//Adafruit_TLC59711 tlc = Adafruit_TLC59711(NUM_TLC59711);

int numLights = 1;
int lowGlow =  500;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  tlc.begin();
  tlc.write();

  // set all lights to lower glow
  for ( int i = 0; i < numLights; i++ ) {
    tlc.setPWM(i, lowGlow);
    tlc.write();
  }

delay(3000);
}

void loop() {
  // test lights by fading up and down
  for ( int i = 0; i < numLights; i++ ) {
    fade( i );
    delay(1000);
  }

}


void fade(int light) {
  // fade on
  for (int i = lowGlow; i >= 0; i-- ) {
    tlc.setPWM(light, i);
    tlc.write();
    delay(2);
  }
  delay(500);

  // fade off
  for (int i = 0; i <= lowGlow; i++ ) {
    tlc.setPWM(light, i);
    tlc.write();
    delay(2);
  }
}


