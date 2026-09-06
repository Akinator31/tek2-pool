#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../string.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(string_init, basic_init_test)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_empty, basic_empty_test1)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.empty(&s), 0);
}

Test(string_empty, basic_empty_test2)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(s.empty(&s), 1);
}

Test(string_empty, basic_empty_test3)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.empty(NULL), 1);
}

Test(string_lenght, basic_lenght_test1)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.length(&s), 3);
}

Test(string_lenght, basic_lenght_test2)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(s.length(&s), 0);
}

Test(string_lenght, basic_lenght_test3)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.length(NULL), 0);
}

Test(string_at, basic_at_test1)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.at(&s, 2), 'o');
}

Test(string_at, basic_at_test2)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.at(&s, -1), -1);
}

Test(string_at, basic_at_test3)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.at(&s, 3), -1);
}

Test(string_at, basic_at_test4)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.at(NULL, 3), -1);
}

Test(string_at, basic_at_test5)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_eq(s.at(&s, 0), 'F');
}

Test(string_at, basic_at_test6)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(s.at(&s, 0), -1);
}

Test(string_print, basic_print_test1, .init=redirect_all_std)
{
    string_t s;

    string_init(&s, "Foo");
    s.print(&s);
    cr_assert_stdout_eq_str("Foo");
}

Test(string_print, basic_print_test2, .init=redirect_all_std)
{
    string_t s;

    string_init(&s, "Foo");
    s.print(NULL);
    cr_assert_stdout_eq_str("");
}

Test(string_data, basic_data_test1)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_str_eq(s.data(&s), "Foo");
}

Test(string_data, basic_data_test2)
{
    string_t s;

    string_init(&s, "");
    cr_assert_str_eq(s.data(&s), "");
}

Test(string_data, basic_data_test3)
{
    string_t s;

    string_init(&s, "Foo");
    cr_assert_null(s.data(NULL));
}

Test(string_clear, basic_clear_test1)
{
    string_t s;

    string_init(&s, "Foo");
    s.clear(&s);
    cr_assert_str_eq(s.s, "");
}

Test(string_clear, basic_clear_test2)
{
    string_t s;

    string_init(&s, "");
    s.clear(&s);
    cr_assert_str_eq(s.s, "");
}

Test(string_clear, basic_clear_test3)
{
    string_t s;

    string_init(&s, "Foo");
    s.clear(NULL);
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_assign, basic_assign_test1)
{
    string_t s;

    string_init(&s, "Foo");
    s.assign(&s, "Bar");
    cr_assert_str_eq(s.s, "Bar");
}

Test(string_assign, basic_assign_test2)
{
    string_t s;

    string_init(&s, "Foo");
    s.assign(&s, NULL);
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_assign, basic_assign_test3)
{
    string_t s;

    string_init(&s, "Foo");
    s.assign(NULL, "Bar");
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_assign, basic_assign_test4)
{
    string_t s;

    string_init(&s, "Foo");
    s.assign(NULL, NULL);
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_append, basic_append_test1)
{
    string_t s;

    string_init(&s, "Foo");
    s.append(&s, "Salut");
    cr_assert_str_eq(s.s, "FooSalut");
}

Test(string_append, basic_append_test2)
{
    string_t s;

    string_init(&s, "Foo");
    s.append(&s, "");
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_append, basic_append_test3)
{
    string_t s;

    string_init(&s, "Foo");
    s.append(NULL, "");
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_append, basic_append_test4)
{
    string_t s;

    string_init(&s, "Foo");
    s.append(NULL, "");
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_append, basic_append_test5)
{
    string_t s;

    string_init(&s, "Foo");
    s.append(NULL, NULL);
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_append, basic_append_test6)
{
    string_t s;

    string_init(&s, "Foo");
    s.append(&s, NULL);
    cr_assert_str_eq(s.s, "Foo");
}

Test(string_append, basic_append_test7)
{
    string_t s;

    string_init(&s, NULL);
    s.append(&s, "Salut");
    cr_assert_null(s.s);
}

Test(string_append, basic_append_test8)
{
    string_t s;

    string_init(&s, NULL);
    s.append(&s, NULL);
    cr_assert_null(s.s);
}

Test(string_destroy, basic_append_test2)
{
    string_t s;

    string_init(&s, "Foo");
    string_destroy(NULL);
    cr_assert_not_null(s.s);
}
