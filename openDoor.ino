void openDoor(int delay_ms) {
  printOnLCD("Opening Door...");

  for (int pos = 90; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
    doorServoMotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  delay(delay_ms); // Keep the door open for a while
  closeDoor();
}