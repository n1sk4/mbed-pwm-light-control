	

#ifndef BLUETOOTH_H
#define BLUETOOTH_H
 
#include <string>
#include <cstdlib>
#include "mbed.h"
 
class Bluetooth : public Serial{
    public:   
        Bluetooth(PinName tx, PinName rx);
        float State();
        void Init();
    private:
        bool state;
        char GetKey(void);
        void PutKey(char key);
        void AskUser(string msgString);
        float ReturnAnswer(float value);
        string GetStringInput(void);
};
 
#endif
