
const int ledPin = 13;

const int DOT_BLNK_LEN = 500;
const int DASH_BLNK_LEN = 1500;
const int GAP_LEN = 500;
const int LETTER_GAP = 1000;
const int WORD_GAP = 2000;

const char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.",
  "--.", "....", "..", ".---", "-.-", ".-..",
  "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-",
  "-.--", "--.."
};

const char* message =
"WAR GREED CRUELTY AND DOMINATION ARE THE ROOT CAUSE OF ALL SUFFERING";

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(DOT_BLNK_LEN);
  digitalWrite(ledPin, LOW);
  delay(GAP_LEN);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(DASH_BLNK_LEN);
  digitalWrite(ledPin, LOW);
  delay(GAP_LEN);
}

void sendLetter(char c) {
  if (c >= 'A' && c <= 'Z') {
    const char* code = letters[c - 'A'];

    for (int i = 0; code[i] != '\0'; i++) {
      if (code[i] == '.') dot();
      else dash();
    }
    delay(LETTER_GAP);
  }
  else if (c == ' ') {
    delay(WORD_GAP);
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; message[i] != '\0'; i++) {
    sendLetter(message[i]);
  }

  delay(3000);
}


