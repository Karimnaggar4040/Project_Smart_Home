void light_resistance() {

  ldrValue = analogRead(ldrPin);

  
  Serial.print("Resistance Value = ");
  Serial.print(ldrValue);
  Serial.println();

  if (ldrValue <= 50) {          // adjust the threshold as needed
    digitalWrite(ledPin, HIGH);  // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }

  delay(100);  // Adjust the delay as needed
}