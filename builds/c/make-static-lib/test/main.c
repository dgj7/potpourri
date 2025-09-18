#include "addition.h"

#include "cut.h"

void test_add(cut_run_t * run);

int main() {
    register_test(test_add, "test_add");

    return run_tests();
}

void test_add(cut_run_t * run) {
    assert_true(2 == add(1, 1), run);
}
