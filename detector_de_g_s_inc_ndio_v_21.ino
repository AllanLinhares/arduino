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
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Verificando...");
  delay(2000);
  int temp = analogRead(pinoSensorTemp);
  int gas = analogRead(pinoSensorGas);
  if (temp < 219 && gas < 100){
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Em normalidade!");
    digitalWrite(3, HIGH);
    delay(5000);
  }
  else{
    if (temp >= 219 && gas < 100){
    	lcd.clear();
  		lcd.setCursor(0,0);
  		lcd.print("QUENTE!!!");
      	digitalWrite(pinoPiezo, HIGH);
      	int i=0;
      	for (i=0; i<5; i++){
            lcd.noBlink();
      		digitalWrite(pinoAzul, HIGH);
          	digitalWrite(pinoVerde, HIGH);
      		delay(500);
          	lcd.blink();
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
      	int i=0;
      	for (i=0; i<5; i++){
          	lcd.noBlink();
      		digitalWrite(pinoVermelho, HIGH);
          	digitalWrite(pinoAzul, HIGH);
      		delay(500);      	          	
			lcd.blink();
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
       	int i=0;
      	for (i=0; i<5; i++){
          	lcd.noBlink();
          	digitalWrite(pinoVermelho, HIGH);
        	delay(500);
      		lcd.blink();
      		digitalWrite(pinoVermelho, LOW);
          	delay(500);
        }
     }
     
  }
  delay(3000);
  lcd.clear();
  digitalWrite(pinoVerde, LOW);
  digitalWrite(pinoAzul, LOW);
  digitalWrite(pinoVermelho, LOW);
  digitalWrite(pinoPiezo, LOW);      
  delay(1000); 
}
