#ifndef HOST_H
#define HOST_H
 
#include <string>
#include <cstdlib>
#include "mbed.h"
 
class Host : public Serial{
    public:   
        Host(PinName tx, PinName rx);
        void    Init(float startValue);
        string  GetInput();
        float   Value;
        bool    Enable;
        float   LastState;
        Timer   timer;
};
 
#endif
