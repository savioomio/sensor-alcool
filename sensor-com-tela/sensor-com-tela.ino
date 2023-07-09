// CÓDIGO SENSOR MQ-3 JUNTAMENTE À TELA LCD

#define sensorDigital 8
#define LED1 9
#define LED2 10
#define buzzer 12
#define sensorAnalog A1
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
 
void setup() {
  pinMode(sensorDigital, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  delay(2000);

//INICIO CÓDIGO TELA
  lcd.begin(16, 2); // definção de colunas(16) e linhas(2)
  lcd.clear();
}
void loop() {

  bool digital = digitalRead(sensorDigital);
  int analog = analogRead(sensorAnalog);
 
  Serial.print("Analog value : ");
  Serial.print(analog);
  Serial.print("t");
  Serial.print("Digital value :");
  Serial.println(digital);
 
  if (digital == 0) {
    digitalWrite(LED1, HIGH);
    digitalWrite(buzzer, HIGH);
    333333333
     digitalWrite(LED2, LOW);
    digitalWrite(buzzer, LOW);
    
    lcd.setCursor(0, 0);
    lcd.print("Alcool detectado"); // Mensagem exibida quando o álcool é detectado
    lcd.setCursor(0, 1);

    lcd.print("no ar: ");
    lcd.print(map(analog, 0, 1023, 0, 100)); // Mapeia o valor analógico para uma escala de 0 a 100
    lcd.print("%");

  }

  else {
    digitalWrite(LED1, LOW);
    digitalWrite(buzzer, LOW);

     digitalWrite(LED2, HIGH);
    digitalWrite(buzzer, LOW);

    lcd.setCursor(3, 0);
    lcd.print("Sem alcool");
    lcd.setCursor(5, 2);
    lcd.print("no ar!");
  }

  delay(2000);

 lcd.clear();

}