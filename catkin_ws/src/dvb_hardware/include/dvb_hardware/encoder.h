#ifndef DEF_ENCODER_H
#define DEF_ENCODER_H

#include "dvb_hardware/hardware.h"

/*
 * Utilisation avec codeurs Kuebler 2400 mini
 * https://www.kuebler.com/k2014/j/fr/produkte/details/drehgeber/Inkremental//Miniatur/2400
 * 
 * Codeur incrémental avec push-pull : 6 signaux délivrés
 * On n'utilise que 2 signaux ( A & B ) pour la 1ère version
 * 
 * Branchement codeur sans push-pull :
 *    - BROWN : 5V
 *    - WHITE : GND
 *    - GRAY :  SIGNAL B en PIN 7 pour gauche, PIN 8 pour droit
 *    - GREEN : SIGNAL A en PIN 2 pour gauche, PIN 3 pour droit
*/

class Encoder : public Hardware
{
    public:
        Encoder(std::string topic_encoder_name, bool debug_mode);
        virtual ~Encoder();

        virtual void spinOnce();

        int32_t getPos();

    private:
        //Topics name
        std::string topic_encoder_name_;

        //On edge rising increment encoder position
        void increment();

        //PIN Number
        int32_t pinA_;
        int32_t pinB_;

        // Encoder position from start
        int32_t pos_; 

        /*
            Publishers
        */
        ros::Publisher pub_encoder_;
  
};
#endif


