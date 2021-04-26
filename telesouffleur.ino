#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SCREEN_COL 20

LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F,20,4);

void setup()
{
  lcd.init(); // initialisation de l'afficheur
}

void loop()
{
  String sentences[] = {
    "Test",
    "Test 1",
    "Test Sentence"
  };

  unsigned int sentencesCount = (unsigned int) sizeof(sentences) / sizeof(sentences[0]);

  lcd.backlight();
  lcd.clear();
  unsigned int r = random(0, sentencesCount);
  displaySentence(sentences[r], SCREEN_COL);
  delay(9500);
}

void displaySentence(String sentence, byte maxCol) {
  byte currentLine = 0;
  byte pos = 0;

  for (byte index = 0; index < sentence.length(); index ++ ) {
    if (pos >= maxCol) {
      pos = 0;
      currentLine++;
    }
    lcd.setCursor(pos++, currentLine);
    lcd.print(sentence.charAt(index));
  }
}
