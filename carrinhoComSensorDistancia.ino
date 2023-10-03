#include <Ultrasonic.h>     
#define FrenteTRIGGER_PIN 3               
#define FreteECHO_PIN     2    
#define DireitaTRIGGER_PIN 11               
#define DireitaECHO_PIN    12      
#define EsquerdaTRIGGER_PIN 13               
#define EsquerdaECHO_PIN    4           
Ultrasonic frenteUltrasonic(FrenteTRIGGER_PIN, FreteECHO_PIN); 
Ultrasonic direitaUltrasonic(DireitaTRIGGER_PIN, DireitaECHO_PIN); 
Ultrasonic esquerdaUltrasonic(EsquerdaTRIGGER_PIN, EsquerdaECHO_PIN); 
#define IN1 9                       
#define IN2 8                       
#define IN3 7                       
#define IN4 6                       
#define ENA 5                      
#define ENB 10  
int LED = A0;
                    
void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(IN1,OUTPUT);              
  pinMode(IN2,OUTPUT);              
  pinMode(IN3,OUTPUT);             
  pinMode(IN4,OUTPUT);              
  pinMode(ENA,OUTPUT);              
  pinMode(ENB,OUTPUT);              
  analogWrite(ENA,200);             
  analogWrite(ENB,150);             
  delay(1000);                    
} //end setuphnj 
void loop()                         
{
  robo_frente();                    
  float distFrente_cm = distanciaFrente();  
  if(distFrente_cm < 20)                
  {
    analogWrite(LED, 255); 
    decisaoFrente();
  } 
  float distEsquer_cm = distanciaEsquerda();
  if(distEsquer_cm < 20)                
  {
    analogWrite(LED, 255); 
    decisaoEsquerda();
  } 
  float distDireita_cm = distanciaDireita();  
  if(distDireita_cm < 20)                
  {
    analogWrite(LED, 255); 
    decisaoDireita();
  }   
  analogWrite(LED, 0); 

delay(100);                           
} 
float distanciaFrente()                   
{
  float cmMsec;
  long microsec = frenteUltrasonic.timing();
  cmMsec = frenteUltrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print(cmMsec);
  Serial.println(" cm - Frente");
  return(cmMsec);                   
  delay(10);
} 
float distanciaDireita()                   
{
  float cmMsec;
  long microsec = direitaUltrasonic.timing();
  cmMsec = direitaUltrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print(cmMsec);
  Serial.println(" cm - Direita");
  return(cmMsec);                   
  delay(10);
} 
float distanciaEsquerda()                   
{
  float cmMsec;
  long microsec = esquerdaUltrasonic.timing();
  cmMsec = esquerdaUltrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print(cmMsec);
  Serial.println(" cm Esquerda");
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
void robo_direita()             
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); 
} 
void robo_parado()                  
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);   
} 
void robo_re()                  
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);   
}
void decisaoFrente()                      
{
  robo_parado();
  delay(400);
  robo_re();
  delay(600);
  robo_parado();
  delay(300);
  robo_esquerda();
  delay(500);                       
  robo_parado();
  delay(400);
}
void decisaoEsquerda()                     
{
  robo_parado();
  delay(400);
  robo_direita();
  delay(500);                       
  robo_parado();
  delay(300);
}
void decisaoDireita()                    
{
  robo_parado();
  delay(400);
  robo_esquerda();
  delay(500);                       
  robo_parado();
  delay(300);
}