#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("BUTTON TEST");
}

void loop()
{
  lcd.setCursor(0, 1);

  if (digitalRead(A0) == LOW)
    lcd.print("DOT PRESSED    ");
  else if (digitalRead(A1) == LOW)
    lcd.print("DASH PRESSED   ");
  else if (digitalRead(A2) == LOW)
    lcd.print("SEND PRESSED   ");
  else
    lcd.print("NO BUTTON      ");
}