# Arduino-esp8266-Software-UART
This a wrapper to be able to use pleningerweb's esp8266-software-uart with Arduino.

Currently doesn't support inverted serial data logic.

It's important to notice that this is a software implementation of the serial protocol. There could be some interrupts that make the transmition or reception fail due to invalid timing.

I have noticed some time delays between 2 and 12 microseconds before receive interrupt's handler take control. 2 microseconds doesn't imply many issues, but 12 microseconds does. One or more bits are lost and in comunications a bit is a lot.

I did some modifications to pleningerweb´s implementation. Instead of using micosecond delays I use the system counter which has 80 Mhz or 160Mhz period depending on CPU clock settings. With this, there is a better granularity and a better timing control. I did transmition tests up to 230400 bps. Didn't test reception.
