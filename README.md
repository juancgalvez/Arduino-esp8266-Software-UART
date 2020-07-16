# Arduino-Esp8266-Software-UART
I GUESS THIS CODES IS NOT NECCESARY ANY MORE. Software Serial for ESP8266 Arduino is working really good now.

This a collections of wrapper functions to be able to use [pleningerweb's esp8266-software-uart](https://github.com/plieningerweb/esp8266-software-uart) with Arduino.

Currently doesn't support inverted serial data logic.

It's important to notice that this is a software implementation of the serial protocol. There could be some interrupts that make the transmition or reception fail due to invalid timing.

I have noticed some time delays between 2 and 12 microseconds before receive interrupt handler takes control. 2 microseconds doesn't imply  issues most of the time, but 12 microseconds does. One or more bits are lost and in comunications a bit is a lot.

I did some modifications to pleningerweb´s implementation. Instead of using micosecond delays I use the system counter which has 80 Mhz or 160Mhz period depending on CPU clock settings. With this, there is a better granularity and a better timing control.

I did transmition tests at 230400 bps and worked. I tested reception at 115200 bps. I guess it could work at higher speeds but have not tested.
