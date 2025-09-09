#ifndef C__UNIT__TESTS__H__
#define C__UNIT__TESTS__H__

#include <stdbool.h>

typedef struct {
    int total_successful;
    int total_failed;
} cut_run_t;

typedef struct {
    char * name;
    void (*test)(cut_run_t);
} cut_test_t;

extern void register_test(void (*f)(cut_run_t), char * name);

extern int run_tests();

extern void assert_eq(bool assertion, cut_run_t run);

#endif
