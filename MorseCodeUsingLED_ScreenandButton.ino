
#include <LiquidCrystal.h>

// LCD connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Button connections
const int DOT = A0;
const int DASH = A1;
const int SEND = A2;

String morse = "";
String message = "";

String letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.",
  "--.", "....", "..", ".---", "-.-", ".-..",
  "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-",
  "-.--", "--.."
};

// Convert Morse code into a letter
char decodeMorse(String code)
{
  for (int i = 0; i < 26; i++)
  {
    if (code == letters[i])
    {
      return 'A' + i;
    }
  }

  return '?';
}

// Detect button press
bool pressed(int pin)
{
  if (digitalRead(pin) == LOW)
  {
    delay(30);

    if (digitalRead(pin) == LOW)
    {
      while (digitalRead(pin) == LOW)
      {
        delay(5);
      }

      delay(30);
      return true;
    }
  }

  return false;
}

// Display Morse code and message
void updateDisplay()
{
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("M:");
  lcd.print(morse);

  lcd.setCursor(0, 1);
  lcd.print("MSG:");
  lcd.print(message);
}

void setup()
{
  pinMode(DOT, INPUT_PULLUP);
  pinMode(DASH, INPUT_PULLUP);
  pinMode(SEND, INPUT_PULLUP);

  lcd.begin(16, 2);

  lcd.print("MORSE DECODER");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");

  delay(1500);

  updateDisplay();
}

void loop()
{
  if (pressed(DOT))
  {
    if (morse.length() < 5)
    {
      morse += ".";
    }

    updateDisplay();
  }

  if (pressed(DASH))
  {
    if (morse.length() < 5)
    {
      morse += "-";
    }

    updateDisplay();
  }

  if (pressed(SEND))
  {
    if (morse.length() > 0)
    {
      char result = decodeMorse(morse);

      if (message.length() >= 12)
      {
        message.remove(0, 1);
      }

      message += result;
      morse = "";

      updateDisplay();
    }
  }
}
