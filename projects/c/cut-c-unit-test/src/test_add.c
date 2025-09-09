#include <stdio.h>

#include "test_add.h"
#include "add.h"
#include "cut.h"

/* both succeed */
void test1(cut_run_t * run) {
    assert_eq(2 == add(1, 1), run);
    assert_eq(2 == add(1, 1), run);
}

/* first fails */
void test2(cut_run_t * run) {
    assert_eq(3 == add(1, 1), run);
    assert_eq(2 == add(1, 1), run);
}

/* second fails */
void test3(cut_run_t * run) {
    assert_eq(2 == add(1, 1), run);
    assert_eq(3 == add(1, 1), run);
}

/* both fail */
void test4(cut_run_t * run) {
    assert_eq(3 == add(1, 1), run);
    assert_eq(3 == add(1, 1), run);
}
