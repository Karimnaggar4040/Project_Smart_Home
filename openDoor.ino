void openDoor(int delay_ms) {
  printOnLCD("Opening Door...");

  for (int angle = 0; angle <= 90; angle += 5) {
    servoMotor.write(angle);
    delay(15);
  }

  delay(delay_ms); // Keep the door open for a while
  closeDoor();
}