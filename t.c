#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

int main()
{
  int i=0;
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
else
{
    for (;;){
      i++;
      printf("%d\n",i);
    }
}
}
