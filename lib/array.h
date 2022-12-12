#ifndef _ARRAY_H
#define _ARRAY_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    size_t len;
    size_t cap;
    char data[];
} Array;

Array *array_make(size_t len, size_t cap)
{
    Array *arr = (Array*) malloc(sizeof(Array) + cap);
    arr->len = len;
    arr->cap = cap;
    memset(arr->data, 0, cap);
    return arr;
}

// compute the next highest power of 2 of 32-bit v
// 64 bit only (TODO: should have guard clause or loop that checks sizeof(size_t))
// https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
unsigned long round_pow2(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    v++;
    return v;
}

Array *_array_grow(Array *arr)
{
    size_t new_size = round_pow2(arr->len*2);
    arr->cap = new_size;
    arr = realloc(arr, sizeof(Array) + new_size);
    if (!arr) return NULL;
    return arr;
}

Array *array_append(Array *arr, void *data, size_t len)
{
    int start = arr->len;
    arr->len += len;
    if (arr->len > arr->cap)
        arr = _array_grow(arr);

    if (!arr) return NULL;

    memcpy(arr->data+start, data, len);
    return arr;
}

#endif
