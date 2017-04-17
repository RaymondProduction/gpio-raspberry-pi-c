/*
 * test.c:
 *      blinks the first LED
 *      Gordon Henderson, projects@drogon.net
 */

#include <stdio.h>
#include <wiringPi.h>
#include <sys/types.h> /* for pid_t */

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

  int i,j,k, digit;
  for (i=0; i<7; i++) {
    pinMode (pins[i], OUTPUT);
  }

  int swichPins[4] = {22, 26, 23, 21};


  for (i=0; i<4; i++){
      pinMode (swichPins[i], OUTPUT);
      digitalWrite (swichPins[i], 1);
  }

  for (;;)
  {
   k = 1;
   for (j=0;j<4;j++){
    digit = (count % (10*k)) / k;
    for (i=0; i<7;i++){
      if (digits[digit][i]>-1){
        digitalWrite (digits[digit][i], 1);

      }

    }
    digitalWrite(swichPins[j],0);
    delay(5);               // mS
    digitalWrite(swichPins[j],1);
    for (i=0; i<7;i++){
      if (digits[digit][i]>-1){
        digitalWrite (digits[digit][i], 0);
      }
    }
    k=k*10;
   }
    count++;
    printf("%d\n", count);

    if (count % 1000 == 0) {
      speak();
    }

    if (count > 9999) { count = 0; }
    // delay (10);
  }
  return 0;
}

int speak(){
  pid_t childpid = fork();
  if(childpid < 0)
  {
    // Handle error
  }
  else if(childpid == 0)
  {
    //system("echo 'Я работаю' | festival --tts --language russian");
   system("echo 'One' | festival --tts");
 }
};
