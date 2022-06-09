# Mbed PWM light control
About
=====
PWM light control using Mbed LPC1768

Light control by using PWM signal to regulate the brightness of the LED light strip.
The PWM signal is connected to the Power source by using some kind of Galvanic isolation,
and the signal travels trough the MOSFET switch to the LED strip.

![](https://os.mbed.com/media/uploads/nzupcic/blockschematics.png)
  
  
*Original project: [PWM LED lights](https://os.mbed.com/users/nzupcic/code/PWM_LED_Lights/)*

Simple project
==============
Controlling integrated LED lights on Mbed NXP LPC1768 prototype board.

This project requires only the use of an rotary incremental encoder and Mbed NXP LPC1768.

Connection diagram
------------------
Without using the pin p20 for PWM output, this is the basic wiring diagram between an encoder and Mbed.
If the Mbed is connected with the PC via micro USB, then 3.3V DC can be used to power up the encoder.
If an external power source is used (e.g., battery) then the 3.3V DC should be used to power up the encoder.

⚠️ Important to note, the encoder and Mbed MUST be on the same GND potential ⚠️

![image](https://user-images.githubusercontent.com/92214769/172785864-8cd87058-1ca7-494e-829f-bcbc8d65ce45.png)


Code example
------------
<pre>
#include "mbed.h"
#include "Room.h"
 
Room livingRoom(LED2, p11, p12, p13, p9, p10, USBTX, USBRX);
// LED2 -> integrated LED
// p11 -> encoder pin A
// p12 -> encoder pin B
// p13 -> encoder pin SW
// p9 and p10 -> not used (Bluetooth)
// USBTX and USBRX -> Serial connection to the PC

int main() {
  while(1){
    //do something
  }
}
</pre>
