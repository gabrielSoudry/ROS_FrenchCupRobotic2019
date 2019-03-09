
/*+------------/*
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

/************* SETUP ******************/

#define PIN_A 2
#define PIN_B 10

#define TOPIC_ENCODER_NAME "/robot/base/wheel/left/state"
#define TOPIC_ENCODER_RESET_NAME "/robot/base/wheel/left/reset"


/**************************************/

#include <ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

volatile int pos;
int interruptA;

std_msgs::Float64 encoder_pos;

void encoder_reset(const std_msgs::Int16& toggle_msg) {
  pos=0;
}

ros::Publisher pub_encoder(TOPIC_ENCODER_NAME, &encoder_pos);
ros::Subscriber <std_msgs::Int16>  sub_encoder(TOPIC_ENCODER_RESET_NAME, &encoder_reset);





/*
 * Si le signal A est en front montant et que le signal B est positif => on a une rotation dans le sens négatif
 * cf site internet
*/

void Increment(){
   
   int signalA = digitalRead(PIN_A);
   int signalB = digitalRead(PIN_B);
   if (signalB == LOW){
      --pos;
   }
   else{
      ++pos;
   }
}


void setup()
{
   /*
    Attention
    Les pins 2 & 3 du GPIO sont utilisés pour les interruptions. 
    Les pins correspondent à des numéros d'interruptions qui sont respectivement 0 & 1.
   */
   //Initialisation des encodeurs
   if(PIN_A == 2) interruptA = 0;
   if(PIN_A == 3) interruptA = 1;
   
   pos = 0;
   
   pinMode(PIN_B, INPUT);
   
   nh.initNode();
   nh.advertise(pub_encoder);
   nh.subscribe(sub_encoder);
   attachInterrupt(interruptA, Increment, FALLING);
}
 
void loop(){
  nh.spinOnce();

  encoder_pos.data = -pos;

  pub_encoder.publish( &encoder_pos );
  
  delay(10);
}
