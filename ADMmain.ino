/*
// drug deriver automation using arduino, motor shield, and LCD module (Hitachi HD44780 or equiv.)
// (c) 2015 Akio Fujimoto.
// twitter : @shiva5300
// License : MIT License, see LICENSE.
*/


// declare abbrev.
#define kprint Serial.print
#define kprintln Serial.println

// include libraries.
#include <LiquidCrystal.h>
#include <EEPROM.h>

// declare constant variables.
const int RS = 2;
const int RW = 3;
const int D4 = 4;
const int D5 = 5;
const int D6 = 6;
const int D7 = 7;
const int aPin = A0;
const int lcdCols = 16;
const int lcdRows = 2;

// declare misc variables.
int intervalMilliSec;
int intervalDrugHour;
int keyIn;


// initialize LCD.
LiquidCrystal lcd (RS, RW, D4, D5, D6, D7);  // rs, en, d4..d7

// setup routine begins here.
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // initialize serial monitor for debugging.

  // initialize LCD monitor.
  lcd.begin(lcdCols, lcdRows);  // 列, 行
  lcd.clear();
  intervalMilliSec = 999;
  intervalDrugHour = 8;
  pinMode(aPin, INPUT);
}


// loop routine begins here.
void loop() {
  // put your main code here, to run repeatedly:
  kprintln("Adjust Time!!");
  kprintln("<> to Adjust interval.");
  kprintln("up down :: adjust interval for 1 second in msec.");
  kprintln("button 1 or 2 :: adjust drug deriver hours.");
  /*   This routine is pseudo timer, yet...   */
  for (int i = 1; i <= intervalDrugHour; i++) {  // hour.
    for (int j = 1; j <= 60; j++) {  // min.
      for (int k = 1; k <= 60; k++) {  //sec.
        delay(intervalMilliSec);
        setInterval();  // this loops forever with interval.
      }
    }
  }
  runMotor(1, 2); // The first arg. is  <!!STUB!!>   ,
  // the second arg. is also  <!!STUB!!>    .

}


// sub-level module routines.
void setInterval() {
  // stub.
  // this routine monitors key inputs and decide appropriate actions.
  keyIn = analogRead(aPin);
  switch (keyIn) {
      if (keyIn < 100) {
        keyIn = 0;
      } else if (keyIn < 200) {
        keyIn = 1;
      } else if (keyIn < 300) {
        keyIn = 3;
      } else if (keyIn < 400) {
        keyIn = 4;
      } else if (keyIn < 500) {
        keyIn = 5;
      } else if (keyIn < 600) {
        keyIn = 6;
      }
    case 0:
      kprintln(keyIn);
      break;  // don't forget this. otherwise, you miss codes.
    case 1:
      kprintln(keyIn);
      break;
    case 2 :
      kprintln(keyIn);
      break;
    case 3:
      kprintln(keyIn);
      break;
    case 4:
      kprintln(keyIn);
      kprintln("4");
      break;
    case 5:
      kprintln(keyIn);
      break;
    case 6:
      kprintln(keyIn);
      break;

    default:
      // this runs always by default.

      kprintln(keyIn);
      break;

      /*
      FOR C&P USE.

      case :
      break;
      */
  }

}


// motor runner.
int runMotor(int x, int y) {
  // stub.
  kprint(x);
  kprint(", ");
  kprintln(y);
  return 0;
}
