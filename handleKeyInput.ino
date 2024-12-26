void handleKeyInput(char key) {
  if (key == '#') {  // Clear input
    clearPassword();
    printOnLCD("Cleared", "");
  } else if (key == '*') {  // Submit password
    lcd.clear();
    if (strcmp(enteredPassword, MASTER_PASSWORD) == 0) {
      printOnLCD("Access Granted", "");
      openDoor(3000);  // Keep door open for 3 seconds
    } else {
      printOnLCD("Access Denied", "");
      delay(2000);
    }
    clearPassword();
  } else if (passwordIndex < PASSWORD_LENGTH - 1) {  // Add character to password
    enteredPassword[passwordIndex++] = key;
    lcd.setCursor(passwordIndex - 1, 1);
    lcd.print('*');
  }
}