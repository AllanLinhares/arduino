#include <LiquidCrystal.h>

const int pinoSensorGas = A0;
const int pinoSensorTemp = A1;

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
  
const int pinoVermelho = 1;
const int pinoVerde = 3;
const int pinoAzul = 2;
const int pinoPiezo = 0;

void setup()
{
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAzul, OUTPUT);
  pinMode(pinoPiezo, OUTPUT);
}

void loop()
{
  int temp = analogRead(pinoSensorTemp);
  int gas = analogRead(pinoSensorGas);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Verificando...");
  delay(2000);
  if (temp < 219 && gas < 100){
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Em normalidade!");
    digitalWrite(3, HIGH);
    delay(5000);
  }
  if (temp >= 219 && gas < 100){
    	lcd.clear();
  		lcd.setCursor(0,0);
  		lcd.print("QUENTE!!!");
      	digitalWrite(pinoPiezo, HIGH);
    	lcd.blink();
      	for (int i=0; i<5; i++){
      		digitalWrite(pinoAzul, HIGH);
          	digitalWrite(pinoVerde, HIGH);
      		delay(500);
      		digitalWrite(pinoAzul, LOW);
          	digitalWrite(pinoVerde, LOW);
      		delay(500);	
       	}
  }
  if (temp < 219 && gas >= 100){
    	lcd.clear();
  		lcd.setCursor(0,0);
  		lcd.print("GAS!!!");
      	digitalWrite(pinoPiezo, HIGH);
    	lcd.blink();
      	for (int i=0; i<5; i++){
      		digitalWrite(pinoVermelho, HIGH);
          	digitalWrite(pinoAzul, HIGH);
      		delay(500);      	          	
      		digitalWrite(pinoVermelho, LOW);
          	digitalWrite(pinoAzul, LOW);
          	delay(500);
        }
  }
  if (temp >= 219 && gas >= 100){
    	lcd.clear();
  		lcd.setCursor(0,0);
       	lcd.print("FOGO!!!");
       	digitalWrite(pinoPiezo, HIGH);
    	lcd.blink();
      	for (int i=0; i<5; i++){
          	digitalWrite(pinoVermelho, HIGH);
        	delay(500);
      		digitalWrite(pinoVermelho, LOW);
          	delay(500);
        }
  }
  lcd.noBlink();
  lcd.clear();
  digitalWrite(pinoVerde, LOW);
  digitalWrite(pinoAzul, LOW);
  digitalWrite(pinoVermelho, LOW);
  digitalWrite(pinoPiezo, LOW);      
  delay(1000); 
}
