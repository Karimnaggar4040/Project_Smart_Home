void printOnLCD(String text) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text);  // printing the recieved text from the website to the lcd
  delay(1500);
  lcd.clear();
}