#ifndef BUCKET_H
#define BUCKET_H

#include "nature2d.h"

/**
 * Generic Bucket
 * 
 */
Bucket *bucket_new(int size);
void bucket_add(Bucket *bucket, void *obj);
void *bucket_at(Bucket *bucket, int i);
int bucket_len(Bucket *bucket);

/**
 * Bucket Vec2
 * 
 */
BucketVec2 *bucket_vec2_new(int size);
void bucket_vec2_add(BucketVec2 *bucket, Vec2 v);
Vec2 bucket_vec2_at(BucketVec2 *bucket, int i);
int bucket_vec2_len(BucketVec2 *bucket);

/**
 * Bucket Double
 * 
 */
BucketDouble *bucket_double_new(int size);
void bucket_double_add(BucketDouble *bucket, double v);
double bucket_double_at(BucketDouble *bucket, int i);
int bucket_double_len(BucketDouble *bucket);

#endif
