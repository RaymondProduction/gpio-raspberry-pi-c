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
  int count=0;

  printf ("Raspberry Pi blink\n") ;


  if (wiringPiSetup () == -1)
    return 1 ;

  int i =0;
  for ( i=0; i<7; i++) {
    pinMode (pins[i], OUTPUT);
  }

  pinMode (21, OUTPUT) ;
  digitalWrite (21, 0) ;
  for (;;)
  {
    printf ("%i", count);
    digitalWrite (pins[count], 1);

    delay (500) ;               // mS
    digitalWrite (pins[count], 0);
    count++;

    if (count > 7) { count = 0; }
    delay (500);
  }
  return 0;
}
