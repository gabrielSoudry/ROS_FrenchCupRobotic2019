#include <ServoTimer2.h>

ServoTimer2 myservo;


#include <DualVNH5019MotorShield.h>

#include <PID_v1.h>

#define PIN_A 3 //Pin encodeur piste A
#define PIN_B 13 //Pin encodeur piste B
#define PIN_obst A2


double valeuraappliquer;
double valeuraappliquer2;
double kp =0.045, ki = 0.0 , kd = 0.001;             // A modifier



double input, output, setpoint; //Setpoint a rentrer manuellement, on va fixer une vitesse
long temp=0;
long temparret = 0; //temps qu'on a pass� � l'arret jusqu'� maintenant
long longarret = 0; //somme des arret de la derni�re fois, pas de la fois actuelle quand on 
est en plein arr�t
volatile long encoderPos = 0;
volatile long encoderPos2 = 0;
int interruptA;

DualVNH5019MotorShield md;
PID myPID(&input, &output, &setpoint, kp, ki, kd, REVERSE);  //'DIRECT' le moteur ne sera 
pas � pleine puissance


double input2, output2, setpoint2; //Setpoint a rentrer manuellement, on va fixer une vitesse

PID myPID2(&input2, &output2, &setpoint2, kp, ki, kd, DIRECT);  //'DIRECT' le moteur ne sera 
pas � pleine puissance

static unsigned long temps = 0;

int obst = 0;

unsigned long currentMillis;
unsigned long Millisdepart;

void setup() { 
input = 0;
  //Initialiser le moteur avec polulu
  pinMode(PIN_A, INPUT_PULLUP);                  // quadrature encoder A
  pinMode(PIN_B, INPUT_PULLUP); 
  pinMode(PIN_obst, INPUT);
  if(PIN_A == 2) interruptA = 0;
  if(PIN_A == 3) interruptA = 1;// quadrature encoderB
  attachInterrupt(interruptA, Increment, FALLING);              // mettre � jour la position 
encoder

 
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(1); //Fr�quence du PID dans le loop
  myPID.SetOutputLimits(-50, 50); //Va fixer le PWM entre -400 et 400 comme sur nos moteurs

  myPID2.SetMode(AUTOMATIC);
  myPID2.SetSampleTime(1); //Fr�quence du PID dans le loop
  myPID2.SetOutputLimits(-50, 50); //Va fixer le PWM entre -400 et 400 comme sur nos moteurs

  
  Serial.begin (115200);                              //DEBUG
  md.init();
    valeuraappliquer = 0;
    valeuraappliquer2 = 0;

//lock demarrage
Millisdepart = millis();
  }

void loop()
{    
 
asservissement(100,TRUE)
 }



void asservissement(double cible, bool arret)
{
  setpoint = cible;
  if(millis()- Millisdepart-temps >10)
{

  
      
        
  input = encoderPos ;                                // donn�es encoder


Serial.print(input);
Serial.print(" , ");
Serial.print(setpoint);
Serial.println();







  myPID.Compute();
 
 
 valeuraappliquer+= output;
 if(valeuraappliquer>300)
 {
  valeuraappliquer = 300;
 }
  md.setM2Speed(valeuraappliquer); 


  
  encoderPos=0; 

  if(!arret){
    temps=millis()-Millisdepart;
    longarret = temparret;
  }
  else{
    temparret=millis() - Millisdepart- temps + longarret; 
  }
}// Doit sortir le pwm modifi� en output
  
}

// Pareil mais avec encoderPos2
//========================================================================
//


void asservissement2(double cible, bool arret)
{
  setpoint2 = cible;
  if(millis()- Millisdepart-temps >10)
  {

  input2 = encoderPos2 ;                                // donn�es encoder


  Serial.print(input2);
  Serial.print(" , ");
  Serial.print(setpoint2);
  Serial.println();


  myPID2.Compute();
 
 
 valeuraappliquer2+= output2;
 if(valeuraappliquer2>300)
 {
  valeuraappliquer2 = 300;
 }
  md.setM2Speed(valeuraappliquer2); 


  encoderPos2=0; 

  if(!arret){
    temps=millis()-Millisdepart;
    longarret = temparret;
  }
  else{
    temparret=millis() - Millisdepart- temps + longarret; 
  }
}// Doit sortir le pwm modifi� en output
  
}

void Increment()
{  
   int signalB = digitalRead(PIN_B);
   if (signalB == LOW){
      ++encoderPos;
      --encoderPos2;
   }
   else{
      --encoderPos;
      ++encoderPos2;
   }
}