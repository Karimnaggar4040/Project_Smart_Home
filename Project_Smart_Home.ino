//LCD config
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //sometimes the LCD adress is not 0x3f. Change to 0x27 if it dosn't work.

// Initialize Pins
const int flameBuzzerPin = 12; //flame buzzer
const int flamePin = 11;
const int echoPin = 10;   // receives the wave
const int trigPin = 9;    //sends the wave

const int ldrPin = A0;    // LDR pins
int ldrValue = 0;   // LDR pins
const int ledPin = 13;

// Initliaze states
int Flame = HIGH;
long duration = 0;
float distance = 0;

void setup() {
  // Output Pins
  pinMode(flameBuzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // Input Pins
  pinMode(flamePin, INPUT);
  pinMode(echoPin, INPUT);

  // Begin serialization
  Serial.begin(9600);
  
  lcd.init();                 //Initialize the LCD
  lcd.backlight();            //Activate backlight
}

void loop() {
    // Main code
    flameSensor();
    ultraSonicSensor();
    light_resistance();
}
