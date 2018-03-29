#include "Ultrasonic.h"
int trig = 12;
int echo = 11;

Ultrasonic objUltra(trig,echo);
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(2,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int dist = objUltra.distanceRead(CM);
  //Serial.print(dist);
  //Serial.println("cm");
  
  if(dist < 8){
  digitalWrite(3,HIGH);  
  digitalWrite(6,LOW);
  Serial.println("Occupied");
  delay(1);  
  }
  else{
  digitalWrite(6,HIGH);
  digitalWrite(3,LOW);
  Serial.println("Vacant");
  delay(1);
  }
  delay(2000);
}
