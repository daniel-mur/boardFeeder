#include <Stepper.h>

#define polA 8
#define polnA 9 
#define polB 10 
#define polnB 11 

//#define A 11 // A
//#define nA 12 // nA
//#define nB 9 // nB
//#define B 10 // B
int phase = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(polA, OUTPUT);
  pinMode(polnA, OUTPUT);
  pinMode(polnB, OUTPUT);
  pinMode(polB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor1_FW();
}
  void motor1_FW() {
  switch(phase) {
    case 0:
    A();
    phase++;
    break;
    case 1:
    B();
    phase++;
    break;
    case 2:
    C();
    phase++;
    break;
    case 3:
    D();
    phase = 0;
    break;  
  }delay(7); 
}//MOTOR1




void A() {
  digitalWrite(polA,HIGH); //A 1번 CW
  digitalWrite(polnA,LOW); //nA
  digitalWrite(polB,HIGH); //B
  digitalWrite(polnB,LOW); //nB
}

void B() {
  digitalWrite(polA,LOW); //A
  digitalWrite(polnA,HIGH); //nA
  digitalWrite(polB,HIGH); //B
  digitalWrite(polnB,LOW); //nB 
}

void C() {
  digitalWrite(polA,LOW); //A
  digitalWrite(polnA,HIGH); //nA
  digitalWrite(polB,LOW); //B
  digitalWrite(polnB,HIGH); //nB   
}

void D() {
  digitalWrite(polA,HIGH); //A
  digitalWrite(polnA,LOW); //nA
  digitalWrite(polB,LOW); //B
  digitalWrite(polnB,HIGH); //nB
}

