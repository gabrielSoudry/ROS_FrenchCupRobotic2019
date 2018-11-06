/*
 * Code arduino pour codeurs incrémentaux magnétique ou optique.
 * 
 * Utilisation avec codeurs Kuebler 2400 mini
 * https://www.kuebler.com/k2014/j/fr/produkte/details/drehgeber/Inkremental//Miniatur/2400
 * ref : 05.2400.1122.1024
 * check branchements sur la datasheet en fonction de la ref
 * 
 * Codeur incrémental avec push-pull : 6 signaux délivrés
 * On n'utilise que 2 signaux ( A & B ) pour la 1ère version
 * 
 * Branchement codeur sans push-pull :
 *    - BROWN : 5V
 *    - WHITE : GND
 *    - GRAY : SIGNAL B en PIN 7 pour gauche, PIN 8 pour droit
 *    - GREEN : SIGNAL A en PIN 2 pour gauche, PIN 3 pour droit
 *    
 * 
*/

//#define DEBUG_SERIAL //Debug sur le moniteur série


#include <ros.h>
#include "std_msgs/Int32.h"

ros::NodeHandle nh;
std_msgs::Int32 str_msg;
ros::Publisher chatter("Encodeur Gauche", &str_msg); // Test uniquement sur l'encodeur gauche  

#ifdef DEBUG_SERIAL
#define DEBUG_PRINT(str)   Serial.print(str);
#define DEBUG_PRINTLN(str) Serial.println(str);
# 
#define DEBUG_PRINT(str)
#define DEBUG_PRINTLN(str)
#endif

#ifdef DEBUG_SERIAL
#define COMMUNICATION_SETUP Serial.begin(19200)
#else
#define COMMUNICATION_SETUP nh.initNode();  
#endif


#define pinAGauche 2
#define pinBGauche 7
#define pinADroit 3
#define pinBDroit 8

//Encoder simple sans push-pull
typedef struct{
  int pinSignalA;
  int pinSignalB;

  volatile int pos;      // Position (en nombre de pas) du codeur
} EncoderSimple;

EncoderSimple *encoderGauche;
EncoderSimple *encoderDroit;
 
void setup(){

   COMMUNICATION_SETUP; // de base communique avec Ros
   nh.advertise(chatter);
   
   /*
    Attention
    Les pins 2 & 3 du GPIO sont utilisés pour les interruptions. 
    Les pins correspondent à des numéros d'interruptions qui sont respectivement 0 & 1.
   */
   //Initialisation des encodeurs
   if(pinAGauche == 2) encoderGauche->pinSignalA = 0;
   if(pinAGauche == 3) encoderGauche->pinSignalA = 1;

   if(pinADroit == 2) encoderDroit->pinSignalA = 0;
   if(pinADroit == 3) encoderDroit->pinSignalA = 1;
   
   encoderGauche->pinSignalB = 7;
   encoderDroit->pinSignalB = 8;

   encoderGauche->pos = 0;
   encoderDroit->pos = 0;
   
   pinMode(encoderGauche->pinSignalB, INPUT);
   pinMode(encoderDroit->pinSignalB, INPUT);
   
   attachInterrupt(encoderGauche->pinSignalA, IncrementGauche, RISING); 
   attachInterrupt(encoderDroit->pinSignalA, IncrementDroit, RISING);
}
 
void loop(){

   str_msg.data = encoderGauche->pos ;
   chatter.publish( &str_msg );
   nh.spinOnce();
   
   delay(1); //on minimise le delay pour ne pas avoir de problème d'échantillonage

   DEBUG_PRINT(encoderGauche->pos);
   DEBUG_PRINT(encoderDroit->pos);
   
   /*
    * Si on veut print le résultat, il faut diminuer la fréquence d'échantillonage
    * ==>
    * delay(100);
   */
}

/*
 * Si le signal A est en front montant et que le signal B est positif => on a une rotation dans le sens négatif
 * cf site internet
*/
void IncrementGauche(){
   
   int signalA = digitalRead(encoderGauche->pinSignalA);
   int signalB = digitalRead(encoderGauche->pinSignalB);
   if (signalB == HIGH){
      --encoderGauche->pos;
   }
   else{
      ++encoderGauche->pos;
   }
}
void IncrementDroit(){
   int signalA = digitalRead(encoderDroit->pinSignalA);
   int signalB = digitalRead(encoderDroit->pinSignalB);
   if (signalB == HIGH){
      --encoderDroit->pos;
   }
   else{
      ++encoderDroit->pos;
   }
}
