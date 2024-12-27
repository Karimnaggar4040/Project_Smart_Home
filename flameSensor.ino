void flameSensor() {
  Flame = digitalRead(flamePin);
  if (Flame == HIGH) { // No fire detected
    digitalWrite(flameBuzzerPin, LOW);
    Serial.println(Flame);
  } else if (Flame == LOW) { // Fire detected
    digitalWrite(flameBuzzerPin, HIGH);
    Serial.println(Flame);
    printOnLCD("FIRE FIRE FIRE");
    openDoor(7000);

    // Add the display to LCD => "FIREEEEEEEE"
    // call the openDoor() function
  }
}