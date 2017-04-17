/*
 * test.c:
 *      blinks the first LED
 *      Gordon Henderson, projects@drogon.net
 */

#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
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

  int count=0;

/*

  6
7    3
  5
2   4
  0   1

 */



  printf ("Raspberry Pi blink\n") ;


  if (wiringPiSetup () == -1)
    return 1 ;

  int i,j,c;
  for (i=0; i<7; i++) {
    pinMode (pins[i], OUTPUT);
  }

  int swichPins[4] = {21, 22, 26, 23};

  c=0;

  for (i=0; i<4; i++){
      pinMode (swichPins[i], OUTPUT);
      digitalWrite (swichPins[i], 1);
  }

  for (;;)
  {
   for (j=0;j<4;j++){
   // printf("%d\n",j);
    for (i=0; i<7;i++){
      if (digits[count][i]>-1){
        digitalWrite (digits[count][i], 1);

      }

    }
    digitalWrite(swichPins[j],0);
    delay(5);               // mS
    digitalWrite(swichPins[j],1);
    for (i=0; i<7;i++){
      if (digits[count][i]>-1){
        digitalWrite (digits[count][i], 0);
      }
    }
   }
    c++;
    if (c>10){
      count++;
      c=0;
    }
    if (count > 9) { count = 0; }
   // delay (10);
  }
  return 0;
}
