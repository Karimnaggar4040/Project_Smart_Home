void closeDoor() {
  printOnLCD("Closing Door...");

  for (int angle = 90; angle >= 0; angle -= 5) {
    doorServoMotor.write(angle);
    delay(15);
  }
}