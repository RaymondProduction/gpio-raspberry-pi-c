#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    system("echo '"+argv[0]+"' | festival --tts --language russian");
    return 0;
}
