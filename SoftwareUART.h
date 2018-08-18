/*
The MIT License (MIT)

Copyright (c) 2018 Juan Carlos Galvez

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef SoftwareUART_h
#define SoftwareUART_h

#if !defined(BOOL)
#define BOOL bool
#endif
#include <inttypes.h>
#include <Stream.h>

extern "C" {
#include <softuart.h>

// from softuart.c trying not to modify softuart.h
uint8_t Softuart_Read(Softuart *s);

}

// This class is compatible with the corresponding AVR one,
// the constructor however has an optional rx buffer size.
// Speed up to 115200 can be used.


class SoftwareUART : public Stream {
public:
  SoftwareUART(int receivePin, int transmitPin, bool inverse_logic = false, unsigned int buffSize = 64);
  virtual ~SoftwareUART();

  void begin(long speed);
  long baudRate();

  bool overflow();
  int peek();
  
  virtual size_t write(uint8_t byte);
  virtual int read();
  virtual int available();
  virtual void flush();
  operator bool() {return true; }
  
    // AVR compatibility methods
  bool listen() { return true; }
  void end() { stopListening(); }
  bool isListening() { return true; }
  bool stopListening() { return true; }
  unsigned long getBitTime() { return _softuart.bit_time; }
  void enableRs485(uint8_t gpio_id);

  using Print::write;

private:
  Softuart _softuart;
  unsigned long _speed;

};

// If only one tx or rx wanted then use this as parameter for the unused pin
#define SW_SERIAL_UNUSED_PIN -1


#endif
