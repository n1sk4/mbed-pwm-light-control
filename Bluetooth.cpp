#include "Bluetooth.h"
 
Bluetooth::Bluetooth(PinName tx, PinName rx) : Serial(tx, rx){
}
 
char Bluetooth::GetKey(void){
    return Serial::getc();
}
 
void Bluetooth::PutKey(char key){
    Serial::putc(key);
}
 
string Bluetooth::GetStringInput(void){
char value[100];
int index=0;
char ch;
    do{ 
    if (Serial::readable()){
        ch = Serial::getc();   
        if (index<100)               
            value[index++]=ch;  
    }
    } while (ch!='\r');    
    value[index]='\x0';     
    return (value);
}
 
void Bluetooth::Init(void){
    state = false;
    Bluetooth::printf("\nEnter ON to turn on the light!\n");
}
 
void Bluetooth::AskUser(string msgString){
    if (msgString == "ON\r" || msgString == "on\r" || msgString == "On\r"){
        state = true;
    }
    else if(msgString == "OFF\r" || msgString == "off\r" || msgString == "Off\r" || msgString == "0\r"){
        state = false;
    }
}
 
float Bluetooth::ReturnAnswer(float value){
    if(state){
        Bluetooth::printf("\nEnter brightness level [%%]: ");
        value = atof((Bluetooth::GetStringInput()).c_str());
        if(value < 0 || value > 100){
            Bluetooth::printf("\nWARNING: Brightness can be set from 1 to 100 [%%]!");
            Bluetooth::printf("\nEnter brightness level [%%]: ");
        }
        else if(value == 0){
            Bluetooth::printf("\nLight is switched off\n");
            Bluetooth::Init();
            return 0;
        }
        else{
            Bluetooth::printf("\nPress enter to change the brightness! or type Off or 0 to switch the light off\n");
            return value/100;
        };
    }
    else{
        Bluetooth::printf("\nLight is switched off\n");
        Bluetooth::Init();
        return 0;
    };
}
 
float Bluetooth::State(void){
    float value;
    Bluetooth::AskUser(Bluetooth::GetStringInput());    
    return ReturnAnswer(value);
}
