#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H
 
#include "mbed.h"
 
class RotaryEncoder{
    public:
        RotaryEncoder(PinName pEncoderA, PinName pEncoderB);
        void        SetCounter(float setValue);
        void        Init(float startValue);
        void        Count();
        bool        Enable;
        float       Value;
        float       LastState;
    private:
        int         aState;
        int         aLastState;
        InterruptIn encoderA;
        DigitalIn   encoderB;
        Timer       debounce;
};
 
#endif
