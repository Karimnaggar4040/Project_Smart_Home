void ultrasonicSensor() {
  // clear the trigPin to make sure no output wave from before
  digitalWrite(trigPin, LOW);
  delay(2);

  // begin the trigPulse for a short amount of time
  digitalWrite(trigPin, HIGH);
  delay(10);
  // End the trig pulse
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the duration it took
  duration = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance = (duration * 0.0343) / 2;

  // ################################
  // Based on the distance, set the light to on or OFF (make two separate methods if needed by someone else)
  // ################################

  // ################################
  // If the door is locked and the ultrasonic sensor senses a movement then there is a burglar, activate the buzzer, display on LCD and open the door
  // ################################

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print(" ");
  Serial.print("cm");
  Serial.println();

  delay(100);
}