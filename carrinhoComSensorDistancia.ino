#include <Ultrasonic.h>     
#define TRIGGER_PIN 3               
#define ECHO_PIN    2               
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN); 
#define IN1 9                       
#define IN2 8                       
#define IN3 7                       
#define IN4 6                       
#define ENA 5                      
#define ENB 10                      
void setup() 
{
  pinMode(IN1,OUTPUT);              
  pinMode(IN2,OUTPUT);              
  pinMode(IN3,OUTPUT);             
  pinMode(IN4,OUTPUT);              
  pinMode(ENA,OUTPUT);              
  pinMode(ENB,OUTPUT);              
  analogWrite(ENA,200);             
  analogWrite(ENB,150);             
  delay(1000);                    
} //end setup
void loop()                         
{
  robo_frente();                    
  float dist_cm = distancia();     
    if(dist_cm < 35)                
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      decisao();
    } else
    {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    }
delay(80);                           
} 
float distancia()                   
{
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print(cmMsec);
  Serial.println(" cm");
  return(cmMsec);                   
delay(10);
} 
void robo_frente()                  
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
} 
void robo_esquerda()             
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 
} 
void robo_parado()                  
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);   
} 
void decisao()                      
{
  robo_parado();
  delay(400);
  robo_esquerda();
  delay(500);                       
  robo_parado();
  delay(400);
}