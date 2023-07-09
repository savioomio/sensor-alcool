/* Sensor MQ3 de alcohol etílico. 
Créditos a:  http://elprofegarcia.com/ y modificado por Danny Balanta. 11-01-2021

Conecta el Arduino con el Sensor de alcohol MQ3 y cuando el nivel de concentracion de alcohol supera un limite se activa una alarma sonora y 
visual con el LED del Pin13, el nivel de alcohol se puede visualizar por un monitor LCD 1602

*/
#include <LiquidCrystal.h> // importar la librería del LCD1602

int VO = 3; // declara las variables para el funcionamiento del LCD 1602 en los pines designados
int RS = 12;
int E = 11;
int D4 = 10;
int D5 = 9;
int D6 = 8;
int D7 = 7;

int valor_limite= 400; // Fija el valor limite en el que se activa la alarma. este es el valor limite en Colombia, que equivale a 0.04 g/dL, o lo que es lo mismo 40 mg de alcohol por 100 mL de sangre, o 400 ppm   
float valor_alcohol; // variable flotante para valor medido por el sensor MQ3
                               										
LiquidCrystal lcd (RS, E, D4, D5 ,D6, D7); // inicializa el LCD

void setup() { // configura el LCD16002 y la alarma del sensor
  lcd.begin(16, 2); // inicializa las 16 columnas y 2 filas del LCD 
   analogWrite(VO, 50); // contraste del LCD
  lcd.setCursor(0,0); // Muestra la primera linea del tablero LCD
  lcd.print("Nivel.alcohol:"); // muestra el mensaje de nivel de alcohol
   pinMode(13,OUTPUT);  // Configura el Pin 13 como salida para un zumbador y como salida visual para la alarma
}

void loop() { // establece acciones para el sensor y las despliega en el monitor LCD
  valor_alcohol=analogRead(A0); // lee el valor del sensor MQ3
  float porcentaje=(valor_alcohol/10000);  // calcula el porcentaje de alcohol detectado

 if(valor_alcohol > valor_limite){ // Si la medida de alcohol es mayor de valor limite
    digitalWrite(13, HIGH);   // Enciende el zumbador conectado al Pin 13 y también este LED
	   lcd.setCursor(0,1); // segunda linea del tablero LCD
	   lcd.print(valor_alcohol); // Envia al monitor LCD el valor leido del Sensor MQ3 
     lcd.print(" % "); // muestra el símbolo de porcentaje
	  lcd.print(porcentaje);   // Envia al monitor LCD el valor del porcentaje de alcohol detectado por el Sensor MQ3 
}
       
else { // Si el valor de la medida de alcohol es menor al valor limite apaga el zumbador y al led del pin 13
   digitalWrite(13, LOW);  // Apaga el zumbador conectado al Pin 13 y también este LED
	  lcd.setCursor(0,1); // segunda linea del tablero LCD
	  lcd.print(valor_alcohol); // Envia al monitor LCD el valor leido del Sensor MQ3 
    lcd.print(" % "); // muestra el símbolo de porcentaje
	  lcd.print(porcentaje); // Envia al monitor LCD el valor del porcentaje de alcohol detectado por el Sensor MQ3 
	 }
delay (400);  // Espera de 400 milisegundos para realizar la proxima medida

}
