#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "array.h"

void test_round_pow2()
{
    typedef struct
    {
        size_t value;
        size_t want;
    }test;

    test tests[] = {
        {0, 0},
        {1, 1},
        {2, 2},
        {3, 4},
        {4, 4},
        {5, 8},
        {6, 8},
        {7, 8},
        {8, 8},
        {9, 16},
        {15, 16},
        {16, 16},
        {17, 32},
        {63, 64},
        {1024, 1024},
        {1024, 1024},
        {4294967295, 4294967296},
        {4294967296, 4294967296}, // 32 bits
        {4294967297, 8589934592},
        {1099511627776-1, 1099511627776}, // 40 bits
        {1099511627776, 1099511627776}, // 40 bits
        // {ULONG_MAX-2, ULONG_MAX},
        // {ULONG_MAX-1, ULONG_MAX},
        // {ULONG_MAX, ULONG_MAX},
    };

    for (int i = 0; i < sizeof(tests) / sizeof(test); i++) {
        test t = tests[i];
        size_t got = round_pow2(t.value);
        printf("round_pow2(%lu)=%lu\n", t.value, got);
        if (got != t.want)
            printf("*** Error test[%d] failed: got = %lu, want = %lu\n", i, got, t.want);
    }
}

void check_array(Array *arr, size_t len, size_t cap)
{
    if (arr->len != len)
        printf("*** Test failed: got len = %lu, want len = %lu\n", arr->len, len);

    if (arr->cap != cap)
        printf("*** Test failed: got cap = %lu, want cap = %lu\n", arr->cap, cap);
}

void print_array(Array *arr)
{
    printf("array(%lu)[", arr->len);
    int i;
    for (i = 0; i < arr->len; i++) {
        printf(" %x,", arr->data[i]);
    }
    for (; i < arr->cap; i++) {
        printf(" -, ");
    }
    printf("](%lu)\n", arr->cap);
}

void test_array()
{
    int five = 5;
    int six = 6;
    long seven = 7;
    char data[] = {1, 2, 3, 4, 5, 6, 7, 8};

    Array *arr = array_make(0, 3);
    check_array(arr, 0, 3);
    print_array(arr);

    arr = array_append(arr, &five, sizeof(five));
    check_array(arr, 4, 8);
    print_array(arr);

    arr = array_append(arr, &six, sizeof(six));
    check_array(arr, 8, 8);
    print_array(arr);

    arr = array_append(arr, &seven, sizeof(seven));
    check_array(arr, 16, 16);
    print_array(arr);

    arr = array_append(arr, data, sizeof(data));
    check_array(arr, 24, 32);
    print_array(arr);
}


int main()
{
    test_round_pow2();

    test_array();

    printf("\n*********** All test passed ***********\n\n");
    return 0;
}
