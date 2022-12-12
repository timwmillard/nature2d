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
size_t round_pow2(size_t v)
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

Array *array_grow(Array *arr)
{
    size_t new_size = round_pow2(arr->cap*2);
    arr = realloc(arr, sizeof(Array) + new_size);
    if (!arr) return NULL;
    arr->cap = new_size;
    return arr;
}

Array *array_append(Array *arr, void *data, size_t len)
{
    if (arr->len + len > arr->cap)
        arr = array_grow(arr);

    if (!arr) return NULL;

    memcpy(arr->data+arr->len, data, len);
    arr->len += len;
    return arr;
}

#endif
