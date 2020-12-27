#include <SimpleDHT.h>
#include <LiquidCrystal.h>      //Header file for LCD

const int rs=7, en=6, d4=5, d5=4, d6=3, d7=2; //pins of LCD connected to Arduino
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); //lcd function from LiquidCrystal

int bulb = 8;
int m1 = 9;
int m2 = 10; 
int pinDHT11 = 11;
int pir = 12;
int threshold = 29;
SimpleDHT11 dht11;

void setup() {
  // put your setup code here, to run once:
   lcd.begin(16,2);
   pinMode (pir, INPUT);
   pinMode (bulb, OUTPUT);
   pinMode (m1, OUTPUT);
   pinMode (m2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte temperature=0;
  byte humidity=0;
  int err = SimpleDHTErrSuccess;

  if((err=dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error");
    return;
  }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print((int)temperature);
    lcd.print((char)223);
    lcd.print("C");

    lcd.setCursor(0,1);
    lcd.print("Humidity: ");
    lcd.print((int)humidity);
    lcd.print("%");
    delay(750);

if (digitalRead(pir) == HIGH) 
{
    digitalWrite(bulb,HIGH);
    delay(1000);
    if ((int)temperature >= threshold)
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
    }
}
if (digitalRead(pir) == LOW)
{
  digitalWrite(bulb,LOW);
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);

}
    
    
}
