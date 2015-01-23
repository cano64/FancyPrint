/*

*/


#include "FancyPrint.h"


FancyPrint::FancyPrint(Print *p) : printer(p) {

}

//function will print integer val divided by 10^d 
//ip = number of characters before decimal point, will be padded with pad character, 
//dp = number of characters after decimal point

void FancyPrint::print(long val, uint8_t d, uint8_t ip, uint8_t dp, char pad) {
  uint8_t isNegative = val < 0;
  if (isNegative) val = -val;
  long divisor = 1;
  
  //match dp with d
  if (d < dp) { //add zeroes (create more decimal places)
    while (d < dp) {
      d++;
      val *= 10;
    }
  } else if (d > dp) { //remove decimal places (round)
    while (d > dp) {
      d--;
      val = (val + 5) / 10; //TODO fix the rounding, now 0.44445 would round to 1.00000, it good enough though for noisy values that change fast
    }
  }
  
  for (int i = 0; i < d; i++) {
    divisor *= 10;
  }
  long ival = val / divisor;
  long tival = ival;
  uint8_t lival = 1; //length of integer part of val
  while (tival >= 10) {
    lival++;
    tival /= 10;
  }
  
  //lival++;
  if (isNegative) lival++; //add one for minus sign
  //print padding characters
  while (ip > lival) {
    this->printer->print(pad);
    lival++;
  }
  
  if (isNegative) this->printer->print('-');
  this->printer->print(ival);
  if (dp > 0) { //display decimal part
    this->printer->print('.');
    unsigned long dval = val - ival * divisor; 
    divisor /= 10;
    if (dval == 0) divisor /= 10;
    while (dval < divisor) {
      this->printer->print('0');
      divisor /= 10;
    }
    this->printer->print(dval);
  }
  
  /*
  
  val = 123456
  d = 2
  divisor = 100
  ival = 1234
         1234.56
  dval = 56
  dp = 3
  output: 1234.560
  
  
  */
 
}


void FancyPrint::println(long val, uint8_t d, uint8_t ip, uint8_t dp, char pad) {
  this->print(val, d, ip, dp, pad);
  this->println();
}


void FancyPrint::println() {
  this->printer->println();
}


void FancyPrint::printHMS(long s, uint8_t hp, char pad) {

}


void FancyPrint::printMS(long s, uint8_t mp, char pad) {
  int min = s / 60;
  uint8_t ss = s - 60*min;
  if (min < 10 && mp > 1) this->printer->print(pad);
  this->printer->print(min);
  this->printer->print(":");
  if (ss < 10) this->printer->print("0");
  this->printer->print(ss);
}



//