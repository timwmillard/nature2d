#ifndef BUCKET_H
#define BUCKET_H

#include <stdlib.h>

#include "nature2d.h"

/**
 * Bucket generic storage of any type of objects.
 * 
 */
Bucket *bucket_new(int size)
{
    Bucket *bucket = malloc(sizeof(Bucket));
    if (!bucket)
        return NULL;

    bucket->data = malloc(size * sizeof(void*));
    if (!bucket->data)
        return NULL;

    bucket->len = 0;
    bucket->cap = size;
    return bucket; 
}

void bucket_add(Bucket *bucket, void *obj)
{
    if (bucket->len >= bucket->cap) {
        bucket->cap = bucket->cap * 2;
        bucket->data = realloc(bucket->data, bucket->cap);
    }
    bucket->data[bucket->len] = obj;
    bucket->len++;
}

void *bucket_at(Bucket *bucket, int i)
{
    return bucket->data[i];
}

int bucket_len(Bucket *bucket)
{
    return bucket->len;
}

/**
 * BucketVec2 storage for Vec2 type.
 * 
 */
BucketVec2 *bucket_vec2_new(int size)
{
    BucketVec2 *bucket = malloc(sizeof(BucketVec2));
    if (!bucket)
        return NULL;

    bucket->data = malloc(size * sizeof(Vec2));
    if (!bucket->data)
        return NULL;

    bucket->len = 0;
    bucket->cap = size;
    return bucket; 
}

void bucket_vec2_add(BucketVec2 *bucket, Vec2 v)
{
    if (bucket->len >= bucket->cap) {
        bucket->cap = bucket->cap * 2;
        bucket->data = realloc(bucket->data, bucket->cap);
    }
    bucket->data[bucket->len] = v;
    bucket->len++;
}

Vec2 bucket_vec2_at(BucketVec2 *bucket, int i)
{
    return bucket->data[i];
}

int bucket_vec2_len(BucketVec2 *bucket)
{
    return bucket->len;
}


/**
 * BucketDouble storage for double type.
 * 
 */
BucketDouble *bucket_double_new(int size)
{
    BucketDouble *bucket = malloc(sizeof(BucketDouble));
    if (!bucket)
        return NULL;

    bucket->data = malloc(size * sizeof(double));
    if (!bucket->data)
        return NULL;

    bucket->len = 0;
    bucket->cap = size;
    return bucket; 
}

void bucket_double_add(BucketDouble *bucket, double v)
{
    if (bucket->len >= bucket->cap) {
        bucket->cap = bucket->cap * 2;
        bucket->data = realloc(bucket->data, bucket->cap);
    }
    bucket->data[bucket->len] = v;
    bucket->len++;
}

double bucket_double_at(BucketDouble *bucket, int i)
{
    return bucket->data[i];
}

int bucket_double_len(BucketDouble *bucket)
{
    return bucket->len;
}


#endif
