void closeDoor() {
  printOnLCD("Closing Door...");

  for (int pos = 180; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    doorServoMotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}