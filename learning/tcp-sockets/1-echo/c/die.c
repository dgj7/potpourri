#include <stdio.h>      /* perror() */
#include <stdlib.h>     /* exit() */

void die_with_error(char *message)
{
    perror(message);
    exit(1);
}
