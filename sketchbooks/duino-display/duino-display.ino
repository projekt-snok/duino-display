#include <LiquidCrystal.h>

/*
  duino-display
  Test the display from a Biltema LMR24 Robot Mower.

  Toggles backlight 10 seconds on and 2 seconds off.
  Toggles display of text every second

 */
 
 #define DELAY_BACKLIGHT_LONG 10000
 #define DELAY_BACKLIGHT_SHORT 2000

const int rs = 12, en = 9, rw=10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int bl=11;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long now_millis;
unsigned long next_display_millis;
unsigned long next_backlight_millis;

bool display_state = false;
bool backlight_state = false;


// the setup routine runs once when you press reset:
void setup() { 
  now_millis = millis();
  next_display_millis = now_millis + 500;
  next_backlight_millis = now_millis + DELAY_BACKLIGHT_LONG;
  // initialize the digital pins as an output.
  pinMode(rw, OUTPUT); //low to send data
  pinMode(bl, OUTPUT); //backlight on/off
  
  // 16x2 character display
  lcd.begin(16, 2); 

  //begin write
  digitalWrite(rw, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Biltema lmr24");
  lcd.setCursor(0, 1);
  lcd.print("Projekt SNOK");

  //turn on backlight
  digitalWrite(bl, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  now_millis = millis();
  
  if (now_millis > next_display_millis) {
    display_state = !display_state;
    if (display_state) {
      lcd.display();
    }
    else {
      lcd.noDisplay();
    }
    //next shift of display state in 1.5 seconds
    next_display_millis = now_millis + 1000;
  }

  if (now_millis > next_backlight_millis) {
    backlight_state = !backlight_state;
    digitalWrite(bl, backlight_state);

    if (backlight_state) {
      next_backlight_millis = now_millis + DELAY_BACKLIGHT_LONG;
    }
    else {
      next_backlight_millis = now_millis + DELAY_BACKLIGHT_SHORT;
    }
  }

}
