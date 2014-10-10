/*

*/

#ifndef FancyPrint_H
#define FancyPrint_H


#include "Arduino.h"


class FancyPrint {

  public:
    Print *printer;
    FancyPrint(Print *p);
    void print(long val, uint8_t d = 0, uint8_t ip = 0, uint8_t dp = 1, char pad = ' '); //ip = number of characters before decimal point, will be padded with spaces, dp = number of characters after decimal point
    void println(long val, uint8_t d = 0, uint8_t ip = 0, uint8_t dp = 1, char pad = ' '); //ip = number of characters before decimal point, will be padded with spaces, dp = number of characters after decimal point
    void println();
  private:

}; //end of class FancyPrint



#endif
