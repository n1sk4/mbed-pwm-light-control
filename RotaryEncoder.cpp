#include "RotaryEncoder.h"
 
RotaryEncoder::RotaryEncoder(PinName pEncoderA, PinName pEncoderB)
                     : encoderA (pEncoderA), encoderB (pEncoderB){
    encoderA.rise(this, &RotaryEncoder::Count);
    encoderA.fall(this, &RotaryEncoder::Count);
}
 
void RotaryEncoder::SetCounter(float setValue){
    RotaryEncoder::Value = setValue;
}
 
void RotaryEncoder::Count(void){
    aState = RotaryEncoder::encoderA.read();
    if (RotaryEncoder::Enable) {
        if (debounce.read_ms() > 200){
            if (aState != aLastState){
                RotaryEncoder::Value += 5;
                RotaryEncoder::debounce.reset();
            }
            else{
                RotaryEncoder::Value -= 5;
                RotaryEncoder::debounce.reset();
            }
        }
        if(RotaryEncoder::Value > 100){
            RotaryEncoder::Value = 100;
        }
        if (RotaryEncoder::Value <= 0){
            RotaryEncoder::Value = 1;
        }
    }
}
 
void RotaryEncoder::Init(float startValue){
    RotaryEncoder::Enable    = false;
    RotaryEncoder::LastState = 0.0;
    RotaryEncoder::SetCounter(startValue);
    aLastState = RotaryEncoder::encoderA.read();
    debounce.start();
}
