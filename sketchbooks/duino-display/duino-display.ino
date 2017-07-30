#include <LiquidCrystal.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
int led = 13;

const int rs = 12, en = 9, rw=10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int bl=11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(rw, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(bl, OUTPUT);
  digitalWrite(rw, LOW);
  lcd.begin(16, 2);
  lcd.print("Biltema lmr24");
  digitalWrite(bl, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  lcd.display();
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  lcd.noDisplay();
  delay(1000);               // wait for a second
}
