#include "Host.h"
 
Host::Host(PinName tx, PinName rx) : Serial(tx, rx){
}
 
string Host::GetInput(){
    char s_value[5];
    int i = 0;
    char ch;
    do{ 
        if (Serial::readable()){
            ch = Serial::getc();   
            if (i < 5){          
                s_value[i++]=ch;  
            };
            if (Host::timer.read_ms() > 5000){
                s_value[i] = '\r';
            };
        }
    }
    while (ch!='\r');  
    s_value[i] = '\x0';
    Host::timer.reset();      
    return (s_value);
}
 
void Host::Init(float startValue){
    Host::timer.start();
    Host::Enable    = false;
    Host::Value     = startValue;
    Host::LastState = 0.0;
}
