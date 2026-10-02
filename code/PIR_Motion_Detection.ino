#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIR_PIN 27
#define LED_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PIR System");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    // Motion detected
    digitalWrite(LED_PIN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Motion Detected");
    lcd.setCursor(0, 1);
    lcd.print("LED ON");

    Serial.println("Motion Detected - LED ON");
  } 
  else {
    // No motion
    digitalWrite(LED_PIN, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Motion Not");
    lcd.setCursor(0, 1);
    lcd.print("Detected - LED OFF");

    Serial.println("Motion Not Detected - LED OFF");
  }

  delay(500);
}
