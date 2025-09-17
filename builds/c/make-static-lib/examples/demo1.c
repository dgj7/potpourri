#include <stdio.h>

#include "addition.h"

int main() {
    int leftAdded = 2;
    int rightAddend = 3;

    printf("%d + %d = %d", leftAdded, rightAddend, add(leftAdded, rightAddend));

    return 0;
}
