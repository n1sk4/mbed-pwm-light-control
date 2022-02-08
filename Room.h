	

#ifndef ROOM_H
#define ROOM_H
 
#include "Host.h"
#include "Bluetooth.h"
#include "RotaryEncoder.h"
#include "mbed.h"
#include "rtos.h"
 
class Room{
    public:
        Room(PinName pRoomLight, PinName pRotaryA, PinName pRotaryB, 
            PinName pSwitch, PinName pBtTx, PinName pBtRx, PinName pHostTx, 
            PinName pHostRx);
        bool            Enable;
        float           LastState;
    private:
        void            Init();
        void            Loop();
        float           SetBrightness();
        void            CheckEnables();
        void            ListenHost();
        void            ListenHardware();
        void            ListenBluetooth();
        void            SwitchStates();
        void            Refresh();
        void            Update();
    protected:
        Thread          pc_thread;
        PwmOut          roomLight;
        Host            pc;
        Bluetooth       bt;
        RotaryEncoder   re;
        InterruptIn     swButton;
        Ticker          tickerEnable;
        Ticker          updateValues;
        Timer           debounce;  
        Timer           timeout_pc;
};
 
#endif
