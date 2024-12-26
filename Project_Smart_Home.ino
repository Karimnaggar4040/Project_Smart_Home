// Initialize Pins
const int buzzerPin = 12;
const int flamePin = 11;

// Initliaze states
int Flame = HIGH;

void setup() {
  // Output Pins
  pinMode(buzzerPin, OUTPUT);

  // Input Pins
  pinMode(flamePin, INPUT);

  // Begin serialization
  Serial.begin(9600);
}

void loop() {
    // Main code
    flameSensor();
}
