#include <stdio.h>

#include "test_add.h"
#include "add.h"
#include "cut.h"

void test_add(cut_run_t run) {
    assert_eq(2 == add(1, 1), run);
}
