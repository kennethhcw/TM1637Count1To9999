/*
 * TM1637.cpp
 * A library for the 4 digit display
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Frankie.Chu
 * Create Time: 9 April,2012
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "TM1637.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports
#define DIO 4
TM1637 tm1637(CLK,DIO);
void setup()
{
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}
void loop()
{
  //int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//0~9,A,b,C,d,E,F
  //int8_t ListDisp[4];
  unsigned char d3 = 0;
  unsigned char d2 = 0;
  unsigned char d1 = 0;
  unsigned char d0 = 0;
  delay(150);
  while(1)
  { 
    d0 ++;  
    if(d0>9)
    {
      d1++;
      d0=0;
    }
     if(d1>9)
    {
      d2++;
      d1=0;
    }
     if(d2>9)
    {
      d3++;
      d2=0;
    }
     if(d3>9)
    {
      d0=0;
      d1=0;
      d2=0;
      d3=0;
    }
    tm1637.display(0,d3);
    tm1637.display(1,d2);
    tm1637.display(2,d1);
    tm1637.display(3,d0);
    delay(10);
  }
}