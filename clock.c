
#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

  int pins[8] = {7, 0, 1, 2, 3, 4, 5, 6};
  int digits[10][7] = {
    { 6, 7, 3, 2, 4, 0,-1},
    { 3, 4,-1,-1,-1,-1,-1},
    { 6, 3, 5, 2, 0,-1,-1},
    { 6, 3, 5, 4, 0,-1,-1},
    { 7, 3, 5, 4,-1,-1,-1},
    { 6, 7, 5, 4, 0.-1,-1},
    { 6, 7, 5, 4, 0, 2,-1},
    { 6, 3, 4,-1,-1,-1,-1},
    { 6, 3, 5, 7, 2, 4, 0},
    { 6, 3, 5, 7, 4, 0,-1}
  };
  int swichPins[4] = { 23, 21,22, 26};
  int timeDigit[4];

  time_t now;
  struct tm *tm;


int main (void)
{
  now = time(0);
  if ((tm = localtime (&now)) == NULL) {
        printf ("Error extracting time stuff\n");
        return 1;
  }

  int count=0;
  printf ("Raspberry Pi clock GPIO\n") ;

  if (wiringPiSetup () == -1)
    return 1 ;

  int i,j,k, digit;

  initPort();
//==================================
  for (;;)
  {
   k = 1;
   for (j=0;j<4;j++){
    digit = (count % (10*k)) / k;
    showDigit(timeDigit[j], 1);
    digitalWrite(swichPins[j],0);
    if (j==0) {
      digitalWrite(1 , timeDigit[2]%2);
    }
    delay(5);               // mS
    digitalWrite(swichPins[j],1);
    if (j==0) {
      digitalWrite(1 , 0);
    }
    showDigit(timeDigit[j], 0);
    k=k*10;
   }
    getTimeDigit();
    //printf("%d\n", timeDigit[2]%2);
    // delay (10);
  }
  return 0;
}
//==================================
  int getTimeDigit(){
    int tmp;
     now = time(0);
     tm = localtime (&now);
     tmp = tm->tm_min;
     timeDigit[0]=(tmp % 10);
     timeDigit[1]=(tmp % 100)/10;
     tmp = tm->tm_sec;
     timeDigit[2]=(tmp % 10);
     timeDigit[3]=(tmp % 100)/10;
     return 0;
  }
  int showDigit(d,s){
    int i;
    for (i=0; i<7;i++){
      if (digits[d][i]>-1){
        digitalWrite (digits[d][i], s);
      }
    }
    return 0;
  }

  int initPort(){
    int i;
    for (i=0; i<7; i++) {
      pinMode (pins[i], OUTPUT);
    }
    for (i=0; i<4; i++){
      pinMode (swichPins[i], OUTPUT);
      digitalWrite (swichPins[i], 1);
    }
    return 0;
  }


/*

  6
7    3
  5
2   4
  0   1

 */
//int tm_sec; Секунды от начала минуты - [0,60][1]
//int tm_min; Минуты от начала часа - [0,59]
//int tm_hour;  Часы от полуночи - [0,23]
