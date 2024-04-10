#include <std/containers/list.h>
#include <check.h>

List *list = NULL;

void setup() {
    list = list_init();
}

void teardown() {
    list_destroy(list);
}

START_TEST(test_list_init) {
    ck_assert_ptr_ne(NULL, list);
    ck_assert_int_eq(0, list_length(list));
}

END_TEST

START_TEST(test_list_push) {
    u64 number = 42;
    list_push(list, &number, sizeof(u64));
    ck_assert_int_eq(1, list_length(list));
    ck_assert_int_eq(42, *((u64 *) list->head->next->data));
}

END_TEST

START_TEST(test_list_pop) {
    u64 number = 42;
    list_push(list, &number, sizeof(u64));

    number = 1500;
    list_pop(list, &number);

    ck_assert_int_eq(0, list_length(list));
    ck_assert_int_eq(42, number);
}

END_TEST

START_TEST(test_list_iterate) {
    u64 number = 42;
    list_push(list, &number, sizeof(u64));
    number = 32;
    list_push(list, &number, sizeof(u64));
    number = 22;
    list_push(list, &number, sizeof(u64));
    number = 12;
    list_push(list, &number, sizeof(u64));
    ck_assert_int_eq(4, list_length(list));

    u64 results[4] = {0};
    u32 i = 0;
    for (Node *it = list_it_first(list); !list_it_is_last(list, it); it = list_it_next(it)) {
        results[i++] = *((u64*)it->data);
    }

    ck_assert_int_eq(42, results[0]);
    ck_assert_int_eq(32, results[1]);
    ck_assert_int_eq(22, results[2]);
    ck_assert_int_eq(12, results[3]);
}

END_TEST

Suite *list_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("List");

    /* Core test case */
    tc_core = tcase_create("Core");
    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_list_init);
    tcase_add_test(tc_core, test_list_push);
    tcase_add_test(tc_core, test_list_pop);
    tcase_add_test(tc_core, test_list_iterate);

    suite_add_tcase(s, tc_core);
    return s;
}