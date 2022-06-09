# Mbed PWM light control
Short project I've done as an Electrical engineering student to showcase the use of:
- Classes
- Interrupts
- Tickers
- Timers
- Debouncing mechanical switches
- PWM control

About
=====
PWM light control using Mbed LPC1768

Light control by using PWM signal to regulate the brightness of the LED light strip.
The PWM signal is connected to the Power source by using some kind of Galvanic isolation,
and the signal travels trough the MOSFET switch to the LED strip.

![](https://os.mbed.com/media/uploads/nzupcic/blockschematics.png)
  
  
*Original project: [PWM LED lights](https://os.mbed.com/users/nzupcic/code/PWM_LED_Lights/)*

Microcontroller Mbed NXP LPC1768
--------------------------------
More about this microcontroller and platform can be found [here](https://os.mbed.com/platforms/mbed-LPC1768/)
The image demonstrates the basic pinout layout of the Mbed prototyping board featuring LPC1768 as the microcontroller.

![](https://os.mbed.com/media/platforms/lpc1768_pinout.png)

Some of it's features are:
* NXP LPC1768 MCU
  - High performance ARM® Cortex™-M3 Core
  - 96MHz, 32KB RAM, 512KB FLASH
  - Ethernet, USB Host/Device, 2xSPI, 2xI2C, 3xUART, CAN, 6xPWM, 6xADC, GPIO
* Prototyping form-factor
  - 40-pin 0.1" pitch DIP package, 54x26mm
  - 5V USB or 4.5-9V supply
  - Built-in USB drag 'n' drop FLASH programmer
* mbed.org Developer Website
  - Lightweight Online Compiler
  - High level C/C++ SDK
  - Cookbook of published libraries and projects

**Schematics and datasheets**
[Mbed NXP LPC1768 Schematics](https://os.mbed.com/media/uploads/chris/mbed-005.1.pdf)

[NXP LPC1768 Data Sheet](https://www.nxp.com/docs/en/data-sheet/LPC1769_68_67_66_65_64_63.pdf)


Pulse width modulation
----------------------
This project is using PWM to control the brightness of the LED lights. That is achieved by
modulating the width of the pulses that are created at the microcontroller Analog output pin.
Mbed NXP LPC1768 has six Analog outputs that are all capable of producing PWM signal.

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
