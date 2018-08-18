# Arduino-esp8266-Software-UART
This a wrapper to be able to use pleningerweb's esp8266-software-uart with Arduino.

Currently doesn't support inverted serial data logic.

It's important to notice that this is a software implementation of the serial protocol. There could be some interrupts that make the transmition or reception fail due to invalid timing.

I have noticed some time delay between 2 and 12 microseconds in receive interrupt handler. 2 microseconds doesn't imply many issued, but 12 microseconds does.

I did some modifications to pleingerweb´s implementation. Instead of using micosecond delays I use the system counter which has 80 Mhz or 160Mhz period depending on CPU clock settings.
