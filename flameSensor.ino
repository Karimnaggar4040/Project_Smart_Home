void flameSensor() {
  Flame = digitalRead(flamePin);
  if (Flame == HIGH) { // No fire detected
    digitalWrite(buzzerPin, LOW);
    Serial.println(Flame);
  } else if (Flame == LOW) { // Fire detected
    digitalWrite(buzzerPin, HIGH);
    Serial.println(Flame);
    // Add the display to LCD => "FIREEEEEEEE"
    // call the openDoor() function
  }
}