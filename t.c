#include <stdio.h>
#include <time.h>

int main (int argc, char *argv[]) {
    time_t now;
    struct tm *tm;

    now = time(0);
    if ((tm = localtime (&now)) == NULL) {
        printf ("Error extracting time stuff\n");
        return 1;
    }

   /* printf ("%04d-%02d-%02d %02d:%02d:%02d\n",
        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec);
    */
    for (;;) {
      now = time(0);
      tm = localtime (&now);
      printf("%d\n", tm->tm_sec);
    }
    return 0;
}
