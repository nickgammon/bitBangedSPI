/*
 
 Bit-banged SPI class
 Author: Nick Gammon
 Date:   24 March 2013
 
 
 PERMISSION TO DISTRIBUTE
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
 and associated documentation files (the "Software"), to deal in the Software without restriction, 
 including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in 
 all copies or substantial portions of the Software.
 
 
 LIMITATION OF LIABILITY
 
 The software is provided "as is", without warranty of any kind, express or implied, 
 including but not limited to the warranties of merchantability, fitness for a particular 
 purpose and noninfringement. In no event shall the authors or copyright holders be liable 
 for any claim, damages or other liability, whether in an action of contract, 
 tort or otherwise, arising from, out of or in connection with the software 
 or the use or other dealings in the software. 
 
 */

#include <Arduino.h>

class bitBangedSPI
  {
  // pins
  const int mosi_;
  const int miso_;
  const int sck_;
  // delay for clock being high
  unsigned long delayUs_;
  
  public:
    // constructor
    bitBangedSPI (const int mosi, const int miso, const int sck, const unsigned long delayUs = 4)
       : mosi_ (mosi), miso_ (miso), sck_ (sck), delayUs_ (delayUs) { }
    
    void begin ();
    byte transfer (byte input);

  enum { NO_PIN = -1 };
    
  };  // end of bitBangedSPI
