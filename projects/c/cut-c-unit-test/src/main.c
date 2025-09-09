#include <stdio.h>

#include "cut.h"
#include "test_add.h"

int main() {
    register_test(test_add, "test_add");

    return run_tests();
}
