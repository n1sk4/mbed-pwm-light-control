#include "Room.h"
 
Room::Room(PinName pRoomLight, PinName pRotaryA, PinName pRotaryB, 
            PinName pSwitch, PinName pBtTx, PinName pBtRx, 
            PinName pHostTx, PinName pHostRx) 
            : roomLight(pRoomLight), re(pRotaryA, pRotaryB), 
            swButton(pSwitch), bt(pBtTx, pBtRx), pc(pHostTx, pHostRx){ 
    Room::Loop();
}
 
void Room::Init(void){
    Room::pc.Init(50.0);
    Room::re.Init(50.0);
    Room::Enable = false;
    Room::re.LastState = 0;
    Room::pc.LastState = 0;
    Room::LastState = 0;
    Room::debounce.start(); 
    Room::timeout_pc.start(); 
}
 
void Room::Loop(void){
    Room::Init();
    Room::swButton.rise(this, &Room::SwitchStates);
    Room::tickerEnable.attach(this, &Room::CheckEnables, 0.01);
    Room::pc_thread.start(this, &Room::ListenHost);
    while(1){
        Refresh();
        Thread::wait(500);
    }
}
 
void Room::Refresh(){
    float brightness = Room::SetBrightness();
    if (brightness > 0 && brightness <= 100){
        Room::roomLight = brightness;
        if (Room::LastState != Room::roomLight){
            if(Room::roomLight != 0.0 && Room::LastState == 0.0){
                Room::pc.printf("\nLight is switched on!\n");
            }
            Room::Update();
        }
        Room::LastState = Room::roomLight;
    }
    else{
        Room::roomLight = 0;
        if (Room::roomLight == 0.0 && Room::LastState != 0.0){
            Room::pc.printf("\nLight is switched off!\n");
        }
        Room::LastState = Room::roomLight;   
    }
}
 
void Room::Update(){
    if (Room::LastState != Room::roomLight || 1){
        float printValue = Room::roomLight;
        Room::pc.printf("\nCurrent brightness is: %.2f[%%]\n",  printValue*100);
    }
}
 
float Room::SetBrightness(void){
    float returnValue = 0;
    bool enable = Room::Enable;
    if(enable){
        if(Room::re.Enable && !Room::pc.Enable){
            returnValue = Room::re.Value/100;
            Room::re.LastState = Room::re.Value;
        };
        if(Room::pc.Enable && !Room::re.Enable){
            returnValue = Room::pc.Value/100;
            Room::pc.LastState = Room::pc.Value;
        };
    }
    return returnValue;
}
 
void Room::CheckEnables(void){
    if (Room::re.Enable || Room::pc.Enable){
        Room::Enable = true;
    }
    else {
        Room::Enable = false;
    };
}
 
void Room::ListenHost(void){
    while(1){
        Room::pc.printf("\nSet brightness [%%]: ");
        float setValue = atof(Room::pc.GetInput().c_str());  
        if(setValue > 0 && setValue <=100){
            Room::pc.Enable = true;
            Room::pc.Value = setValue;
        }
        else if (setValue == 0){
            Room::pc.Enable = false;
            Room::pc.Value = 0.0;
        }else if (setValue == 000){
            //do nothing
            Room::pc.printf("\nTimeout\n");
        }
    }
}
 
void Room::ListenHardware(void){
}
 
void Room::ListenBluetooth(void){ 
}
 
void Room::SwitchStates(void){
    if(debounce.read_ms() > 200){
        Room::re.Enable = !Room::re.Enable;
        Room::debounce.reset();
    }
}
