#include <Servo.h> 
 const int servoPin = 8;  // Servo pin
 const int buttonPin = 9;  // Pushbutton pin
 int buttonState = 0; 
 int directionState = 0; 
 Servo myservo; 
 int pos = 0;
 int ledPin = 7; //Led no pino 7
int ldrPin = 0; //LDR no pino analígico 0
int ldrValor = 0; //Valor lido do LDR

void setup() {
   myservo.attach(servoPin);
   pinMode(buttonPin, INPUT);
   pinMode(ledPin,OUTPUT); //define a porta 7 como saída
   Serial.begin(9600); //Inicia a comunicação serial
 }
 
 void loop(){
   ///ler o valor do LDR
   ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
   //se o valor lido for maior que 500, liga o led
   if (ldrValor>= 800) digitalWrite(ledPin,HIGH);
   // senão, apaga o led
   else digitalWrite(ledPin,LOW);
   
   buttonState = digitalRead(buttonPin);
   if (directionState == 0){
     if (buttonState == HIGH) {
       directionState = 1;
       for(pos = 0; pos < 180; pos += 1)
       {
         myservo.write(pos);  
         delay(15);  // waits 15ms to reach the position 
       }
     }
 
   } else if (directionState == 1) {
     if (buttonState == HIGH) {
       directionState = 0;   
       
      for (pos = 180; pos>=1; pos -=1)
       {
         myservo.write(pos);
         delay(100);
       }
     }
   }
 }