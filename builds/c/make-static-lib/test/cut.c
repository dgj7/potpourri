#include <stdio.h>          // printf()
#include <string.h>         // strcpy()
#include <stdlib.h>         // malloc()

#include "cut.h"

cut_test_t tests[1000];
static int cutTestIndex = 0;

/**
 * Register a test with cut; this is necessary for the test to be run by the framework.
 */
void register_test(void (*f)(cut_run_t *), char * name) {
    /* create a test instance; this will be stored internally */
    cut_test_t test;

    /* set fields in the test */
    test.test = f;
    test.name = malloc(sizeof(char) * strlen(name));                                    // todo: handle malloc() failure
    strcpy(test.name, name);

    /* store the test */
    tests[cutTestIndex] = test;

    /* increment the current index */
    cutTestIndex += 1;
}

/**
 * Run all tests registered with cut.
 */
int run_tests() {
    /* storage for the number of failed tests; initially, zero */
    int total = 0;
    int succeeded = 0;
    int failed = 0;
    printf("running unit tests:\n");

    /* loop over all registered tests; number is equal to the current index, minus 1 */
    for (int c = 0; c < cutTestIndex; c++) {
        /* create a test run; values are initially zero */
        cut_run_t run = {.total_successful=0, .total_failed=0};

        /* get the test instance */
        cut_test_t test = tests[c];

        /* run the test instance */
        (*test.test)(&run);

        /* update the failed count with the failed count from the test run */
        total += run.total_successful + run.total_failed;
        succeeded += run.total_successful;
        failed += run.total_failed;

        /* print test summary */
        printf("\t%s: %s\n", test.name, run.total_failed > 0 ? "failed" : "succeeded");       // todo: make configurable, to potentially not print if not requested?
    }

    printf("test results: %d run, %d passed, %d failed\n", total, succeeded, failed);

    /* done; return the failed count */
    return failed;
}

/**
 * Assert that the given value is true.
 */
void assert_true(bool assertion, cut_run_t * run) {
    if (assertion) {
        run->total_successful += 1;
    } else {
        run->total_failed += 1;
    }
}
