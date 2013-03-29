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

#include <bitBangedSPI.h>

void bitBangedSPI::begin ()
  {
  if (mosi_ != NO_PIN)
    pinMode (mosi_, OUTPUT);
  if (miso_ != NO_PIN)
    pinMode (miso_, INPUT);
  pinMode (sck_, OUTPUT);
  }   // end of bitBangedSPI::begin
  
  
// Bit Banged SPI transfer
byte bitBangedSPI::transfer (byte c)
{       
  // loop for each bit  
  for (byte bit = 0; bit < 8; bit++) 
    {
    // set up MOSI on falling edge of previous SCK (sampled on rising edge)
    if (mosi_ != NO_PIN)
      {
      if (c & 0x80)
          digitalWrite (mosi_, HIGH);
      else
          digitalWrite (mosi_, LOW);
      }
    // finished with MS bit, get read to receive next bit      
    c <<= 1;
 
    // read MISO
    if (miso_ != NO_PIN)
      c |= digitalRead (miso_) != 0;
 
    // clock high
    digitalWrite (sck_, HIGH);
 
    // delay between rise and fall of clock
    delayMicroseconds (delayUs_);
 
    // clock low
    digitalWrite (sck_, LOW);

    // delay between rise and fall of clock
    delayMicroseconds (delayUs_);
    }  // end of for loop, for each bit
   
  return c;
  }  // end of bitBangedSPI::transfer  

