#ifndef NATURE2D_H
#define NATURE2D_H

#include <math.h>

static inline double map(double value, double start1, double stop1, double start2, double stop2)
{
    return (value - start1) / (stop1 - start1) * (stop2 - start2) + start2;
}

static inline double max(double a, double b)
{
    return (a > b)? a : b;
}

static inline double min(double a, double b)
{
    return (a < b)? a : b;
}

/**
 * Open Simplex Noise function
 * 
 */

void noise_seed(int seed);
double noise(double x);
double noise2(double x, double y);
double noise3(double x, double y, double z);
void destroy_noise();


/**
 * 2D Vector function
 * 
 */
typedef struct Vec2 {
    double x;
    double y;
} Vec2;

static const Vec2 vec2zero = {0.0f, 0.0f};

static inline Vec2 vec2(const double x, const double y)
{
    Vec2 vec = {x, y};
    return vec;
}

static inline Vec2 vec2_add(const Vec2 a, const Vec2 b)
{
    return vec2(a.x + b.x, a.y + b.y);
}

static inline Vec2 vec2_sub(const Vec2 a, const Vec2 b)
{
    return vec2(a.x - b.x, a.y - b.y);
}

static inline double vec2_dot(const Vec2 a, const Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

static inline double vec2_mag(const Vec2 v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

static inline Vec2 vec2_mult(const Vec2 v, double m)
{
    return vec2(v.x * m, v.y * m);
}

static inline Vec2 vec2_div(const Vec2 v, double m)
{
    return m == 0 ? vec2zero : vec2(v.x / m, v.y / m);
}

static inline Vec2 vec2_normalize(const Vec2 v)
{
    double mag = vec2_mag(v);
    return mag == 0 ? vec2zero : vec2(v.x/mag, v.y/mag);
}

static inline Vec2 vec2_set_mag(const Vec2 v, double m)
{
    return vec2_mult(vec2_normalize(v), m);
}

static inline Vec2 vec2_neg(const Vec2 v)
{
    return vec2(-v.x, -v.y);
}


/**
 * Containers for storing objects
 * 
 *
 */
typedef struct {
    void **data;
    int len;
    int cap;
} Bucket;

Bucket *bucket_new(int size);
void bucket_add(Bucket *bucket, void *obj);
void *bucket_at(Bucket *bucket, int i);
int bucket_len(Bucket *bucket);

typedef struct {
    Vec2 *data;
    int len;
    int cap;
} BucketVec2;

BucketVec2 *bucket_vec2_new(int size);
void bucket_vec2_add(BucketVec2 *bucket, Vec2 v);
Vec2 bucket_vec2_at(BucketVec2 *bucket, int i);
int bucket_vec2_len(BucketVec2 *bucket);


typedef struct {
    double *data;
    int len;
    int cap;
} BucketDouble;

BucketDouble *bucket_double_new(int size);
void bucket_double_add(BucketDouble *bucket, double v);
double bucket_double_at(BucketDouble *bucket, int i);
int bucket_double_len(BucketDouble *bucket);


/**
 * Shapes
 * 
 * Rectangle, Circle and Polygon.
 *
 */
typedef struct Shape {
    double density;
    double surface_area;
    double area;
    double cog;
} Shape;

typedef struct Rectangle {
    Shape shape;
    Vec2 pos;  // Top left corner
    double width;
    double height;
} Rectangle;

typedef struct Circle {
    Shape shape;
    Vec2 center; // center
    double radius; // radius
} Circle;

typedef struct Polygon {
    Shape shape;
    BucketVec2 *points;
} Polygon;


/**
 * Body is a physics body that lives in an enviroment.
 * 
 *
 */
typedef struct Body {
    Vec2 pos;
    Vec2 vel;
    Vec2 acc;
    double mass;

    Bucket *shapes;
} Body;

Body *body_alloc();
void body_init(Body *body, Vec2 pos, double mass);
Body *body_new(Vec2 pos, double mass);
Body *body_new_xy(double x, double y, double mass);
void body_apply_force(Body *body, Vec2 force);
void body_apply_gravity(Body *body, Vec2 force);
void body_update(Body *body, double dt);
void body_destroy(Body *body);


/**
 * Enviorment contains a phyics world
 * 
 *
 */
typedef struct {
    Vec2 gravity;
    double density;

    Shape *shape;

    Bucket *bodies;
} Enviroment;

#endif
