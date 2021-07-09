#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "test.h"

#include "../nmath.h"

int main()
{
    typedef struct {
        double value;
        double start1;
        double end1;
        double start2;
        double end2;
        double result;
        bool expected;
    } test;

    test tests[] =  {
        {45, 0, 100, 0, 1000, 450.00, true},
        {45, 1, 100, 0, 1000, 450.00, false},
        {145, 100, 200, 200, 300, 245.00, true},
        {145, 100, 200, 1000, 2000, 1450.00, true},
        {50, 0, 100, 500, 1000, 750.00, true},  
    };

    for (int i=0; i<5; i++) {
        test t = tests[i];
        double got = map(t.value, t.start1, t.end1, t.start2, t.end2);
        assert((roundp(got, 2) == t.result) == t.expected);
    }

    passed();

    return 0;
}
