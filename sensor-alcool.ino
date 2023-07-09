#include <LiquidCrystal.h>

#define sensorDigital 2
#define sensorAnalog A1

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  pinMode(sensorDigital, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  bool digital = digitalRead(sensorDigital);
  int analog = analogRead(sensorAnalog);

  if (digital == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Alcool detectado"); // Mensagem exibida quando o álcool é detectado
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpa a segunda linha do display
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Nao ha Alcool"); // Mensagem exibida quando não há álcool detectado
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpa a segunda linha do display
  }

  lcd.setCursor(0, 1);
  lcd.print("Teor de Alcool: ");
  lcd.print(map(analog, 0, 1023, 0, 100)); // Mapeia o valor analógico para uma escala de 0 a 100
  lcd.print("%");

  delay(1000); // Aguarda 1 segundo antes de atualizar novamente
}
