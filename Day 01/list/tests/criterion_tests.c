#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../list.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(list_empty, basic_init_test1)
{
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
}

Test(list_size, basic_size_test1)
{
    list_t l;

    list_init(&l);
    cr_assert_eq(l.size(&l), 0);
}

Test(list_get, basic_get_test1)
{
    list_t l;

    list_init(&l);
    cr_assert_null(l.get(&l, 0));
    cr_assert_null(l.get(&l, 1));
    cr_assert_null(l.get(&l, 2));
    cr_assert_null(l.get(&l, 42));
}

Test(list_set, basic_set_test1)
{
    int i = 42;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.set(&l, 0, &i), 0);
    cr_assert_eq(l.set(&l, 1, &i), 0);
    cr_assert_eq(l.set(&l, 2, &i), 0);
    cr_assert_eq(l.set(&l, 42, &i), 0);
}

Test(list_push_front, basic_push_front_test1)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    l.push_front(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_front(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &k);
    cr_assert_eq(*(int *)l.get(&l, 0), 84);
    cr_assert_eq(l.get(&l, 1), &i);
    cr_assert_eq(*(int *)l.get(&l, 1), 42);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.push_front(&l, &j);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &j);
    cr_assert_eq(*(int *)l.get(&l, 0), 100);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.get(&l, 2), &i);
    cr_assert_eq(*(int *)l.get(&l, 2), 42);
    cr_assert_eq(l.size(&l), 3);
    cr_assert_eq(l.length, 3);
}

Test(list_push_back, basic_push_back_test1)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_back(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.push_back(&l, &j);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.get(&l, 2), &j);
    cr_assert_eq(*(int *)l.get(&l, 2), 100);
    cr_assert_eq(l.size(&l), 3);
    cr_assert_eq(l.length, 3);
}

Test(list_pop_front, basic_pop_front_test1)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.pop_front(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
}

Test(list_pop_front, basic_pop_front_test2)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_back(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.pop_front(&l);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);

    l.pop_front(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);

    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_back(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.pop_front(&l);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);

    l.pop_front(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
}

Test(list_pop_back, basic_pop_back_test1)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.pop_back(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
}

Test(list_pop_back, basic_pop_back_test2)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_back(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.pop_back(&l);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);

    l.pop_back(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);

    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_back(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.pop_front(&l);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);

    l.pop_front(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
}

Test(list_clear, basic_clear_test1)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_back(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.clear(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.clear(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.clear(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
}

void *function(void *element)
{
    int i = 500;

    element = &i;
    return element;
}

Test(list_apply, basic_apply_test1)
{
    int i = 42;
    int k = 84;
    int j = 100;
    list_t l;

    list_init(&l);
    cr_assert_eq(l.empty(&l), 1);
    cr_assert_eq(l.size(&l), 0);
    l.push_back(&l, &i);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.size(&l), 1);
    cr_assert_eq(l.length, 1);

    l.push_back(&l, &k);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.get(&l, 0), &i);
    cr_assert_eq(*(int *)l.get(&l, 0), 42);
    cr_assert_eq(l.get(&l, 1), &k);
    cr_assert_eq(*(int *)l.get(&l, 1), 84);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(l.length, 2);

    l.apply(&l, function);
    cr_assert_eq(l.empty(&l), 0);
    cr_assert_eq(l.size(&l), 2);
    cr_assert_eq(*(int *)l.get(&l, 0), 500);
    cr_assert_eq(*(int *)l.get(&l, 1), 500);
}
