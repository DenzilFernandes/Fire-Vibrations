#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
int sensorPin = 9;
int sensorValue = 0;
SoftwareSerial BTserial(10, 11);
int buzzer = 12;
const int xpin = A5;
const int ypin = A4;
const int zpin =A3;
LiquidCrystal lcd(2,3,4,5,6,7);
int x,y,z=0;
void setup()
{
 pinMode(buzzer,OUTPUT);
 lcd.begin(16, 2);
 lcd.setCursor(0,1);
 lcd.write("FIRE");
 Serial.begin(9600);
 BTserial.begin(9600);
}
void loop()
{
  x=analogRead(xpin);
  y=analogRead(ypin);
  z=analogRead(zpin);
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.print(z);
  Serial.println(); 
  delay(100);
  sensorValue = digitalRead(sensorPin);
  Serial.println(sensorValue);
  digitalWrite(buzzer,LOW);
  delay(sensorValue);
  if(x>400||y>400||z>400)
  {
     
     BTserial.print("Earth Quake Predicted . Evacuate !");
     BTserial.print(";");
     exit(1);
  }
  else if(sensorValue==0)
  {
     Serial.println("Fire Detected");
     digitalWrite(buzzer,HIGH);
     delay(1000);
     BTserial.print("Forest Fire Detected");
     BTserial.print(";");
     digitalWrite(buzzer,LOW);
     delay(sensorValue);
     exit(1);
   }
   else 
   {
    BTserial.print("safe");
    BTserial.print(";");
    delay(200);
   }
}
