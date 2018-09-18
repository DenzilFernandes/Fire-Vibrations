#include<SoftwareSerial.h>

int sensorPin = 2;
int sensorValue = 0;

int buzzer = 12; //
void setup() {

pinMode(buzzer,OUTPUT);

Serial.begin(9600);

}

void loop()

{

sensorValue = digitalRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue==0)

{
Serial.println("Fire Detected");


digitalWrite(buzzer,HIGH);

delay(1000);

}

digitalWrite(buzzer,LOW);

delay(sensorValue);

}
