#include <stdio.h>          // printf()
#include <string.h>         // strcpy()
#include <stdlib.h>         // malloc()

#include "cut.h"

cut_test_t tests[1000];
static int index = 0;

// todo: handle malloc() failure
void register_test(void (*f)(cut_run_t), char * name) {
    cut_test_t test;
    test.test = f;
    test.name = malloc(sizeof(char) * strlen(name));
    strcpy(test.name, name);
    tests[index] = test;
    index += 1;
}

int run_tests() {
    int failed = 0;
    for (int c = 0; c < index; c++) {
        cut_run_t run = {.total_successful=0, .total_failed=0};
        cut_test_t test = tests[c];
        (*test.test)(run);
        failed += run.total_failed;
        printf("%s: %s", test.name, run.total_failed > 0 ? "failed" : "succeeded");
    }
    return failed;
}

void assert_eq(bool assertion, cut_run_t run) {
    if (assertion) {
        run.total_successful += 1;
    } else {
        run.total_failed += 1;
    }
}
