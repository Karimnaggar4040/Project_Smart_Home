//LCD config
#include <Servo.h>
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Constants and configurations
#define PASSWORD_LENGTH 7                                // Password length including null terminator
const char MASTER_PASSWORD[PASSWORD_LENGTH] = "123456";  // Master password

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 7, 6, 5, 4 };
byte colPins[COLS] = { 3, 2, 9, 8 };
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

Servo doorServoMotor;

LiquidCrystal_I2C lcd(0x27, 16, 2);  //sometimes the LCD adress is not 0x3f. Change to 0x27 if it dosn't work.

// Initialize Pins
const int flameBuzzerPin = 12;  //flame buzzer
const int flamePin = 11;

// Initliaze states
int Flame = HIGH;

char enteredPassword[PASSWORD_LENGTH] = { 0 };
byte passwordIndex = 0;

void setup() {
  // Servo Motors attach
  doorServoMotor.attach(10);
  // Output Pins
  pinMode(flameBuzzerPin, OUTPUT);
  // Input Pins
  pinMode(flamePin, INPUT);

  // Begin serialization
  Serial.begin(9600);

  // doorServoMotor.write(90);
  closeDoor();
  // LCD initialization
  lcd.init();       //Initialize the LCD
  lcd.backlight();  //Activate backlight
}

void loop() {
  // Main code
  flameSensor();

  char customKey = customKeypad.getKey();
  if (customKey) {
    handleKeyInput(customKey);
  }
}
