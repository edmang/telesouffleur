#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SCREEN_COL 20

LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F,20,4);

String sentences[] = {
  "Elle ment en Allemand !",
  "Quand on n'a pas les moyens, on pic-nic.",
  "Un face a face d'accord mais moi tout seul .",
  "C'etait pas mauvais, c'etait tres mauvais !",
  "Salomon... Slimane... Salomon... Slimane... vous seriez pas cousins ?",
  "Philippe ! Je sais ou tu te caches ! Viens ici que je te bute encule !",
  "Mon frere, je te vengerai ! Vous savez qui a tue mon frere ?",
  "Je m'en fou des japonais et de leurs compliments, je veux sa tete !",
  "L'impot sur le droit de vivre, ca ne vous dit rien ?",
  "I beg your pardon my Lord. I am sure mais alors I am tout a fait sure",
  "J'aime me beurrer la biscotte",
  "Je connais cette theorie",
  "Il y a forcement une amicale d'anciens nazis",
  "Elle est comment votre blanquette ?",
  "Vas-y !"
};

int sentencesCount = sizeof(sentences) / sizeof(sentences[0]);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("  Bonjour, Maitre");
  lcd.setCursor(0, 2);
  lcd.print("  (K&R ed. fr p.6)");
  delay(6000);
  lcd.clear();
}

void loop()
{
  randomSeed(millis() / 1000000);
  int randomIndex = random(0, sentencesCount);
  displaySentence(sentences[randomIndex]);
  delay(8000);
  lcd.clear();
}

void displaySentence(String sentence) {
  lcd.setCursor(0, 0);
  int currentLine = 0;
  int pos = 0;

  for (int index = 0; index < sentence.length(); index ++ ) {
    if (pos >= SCREEN_COL) {
      pos = 0;
      currentLine++;
    }
    lcd.setCursor(pos++, currentLine);
    lcd.print(sentence.charAt(index));
  }
}
