#include <check.h>
#include "check_check.h"

int main() {
    SRunner *sr = srunner_create(darray_suite());
    srunner_add_suite(sr, memory_suite());
    srunner_add_suite(sr, list_suite());

    srunner_run_all(sr, CK_NORMAL);
    int failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return failed;
}