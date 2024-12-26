// Initialize Pins
const int buzzerPin = 12;
const int flamePin = 11;
const int trigPin = 9;   //sends the wave
const int echoPin = 10;  // receives the wave

// Initliaze states
int Flame = HIGH;
long duration = 0;
float distance = 0;

void setup() {
  // Output Pins
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  // Input Pins
  pinMode(flamePin, INPUT);
  pinMode(echoPin, INPUT);

  // Begin serialization
  Serial.begin(9600);
}

void loop() {
    // Main code
    flameSensor();
    ultraSonicSensor();
}
