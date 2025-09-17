#include <stdio.h>

#include "simple.h"

int main() {
    /* create some input variables; to make this really useful we'd use args, but nope not today */
    int left = 2;
    int right = 2;

    /* print a message after calling the external function */
    printf("%d + %d = %d", left, right, sum(left, right));

    /* signal to the operating system that we didnt screw anything up */
    return 0;
}
