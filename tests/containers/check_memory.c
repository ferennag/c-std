#include <core/memory.h>
#include <check.h>

START_TEST(test_memory_alloc) {
    u64 *block = (u64 *) memory_alloc(sizeof(u64));
    ck_assert_ptr_ne(0, block);
    memory_free(block);
}
END_TEST

START_TEST(test_memory_zero) {
    u64 *block = (u64 *) memory_alloc(sizeof(u64));

    *block = 10;
    ck_assert_int_eq(10, *block);
    memory_zero(block, sizeof(u64));
    ck_assert_int_eq(0, *block);

    memory_free(block);
}
END_TEST

START_TEST(test_memory_copy) {
    u64 *block = (u64 *) memory_alloc(sizeof(u64));
    u64 *block2 = (u64 *) memory_alloc(sizeof(u64));
    memory_zero(block2, sizeof(u64));

    *block = 10;
    memory_copy(block2, block, sizeof(u64));
    ck_assert_int_eq(10, *block);
    ck_assert_int_eq(10, *block2);

    memory_free(block);
    memory_free(block2);
}
END_TEST

Suite *memory_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Memory");

    /* Core test case */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_memory_alloc);
    tcase_add_test(tc_core, test_memory_zero);
    tcase_add_test(tc_core, test_memory_copy);

    suite_add_tcase(s, tc_core);
    return s;
}