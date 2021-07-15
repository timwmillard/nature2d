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

typedef struct {
    Vec2 *data;
    int len;
    int cap;
} BucketVec2;

typedef struct {
    double *data;
    int len;
    int cap;
} BucketDouble;

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

Rectangle *rectangle_new(double x, double y, double width, double height);
Rectangle *rectangle_new_v(Vec2 start, Vec2 end);

typedef struct Circle {
    Shape shape;
    Vec2 center; // center
    double radius; // radius
} Circle;

Circle *circle_new(double x, double y, double r);
Circle *circle_new_v(Vec2 center, double r);

typedef struct Polygon {
    Shape shape;
    BucketVec2 *points;
} Polygon;

Polygon *polygon_new(double x1, double y1, double x2, double y2, double x3, double y3, ...);
Polygon *polygon_new_v(Vec2 x1, Vec2 x2, Vec2 x3, ...);

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
Body *body_new_v(Vec2 pos, double mass);
Body *body_new(double x, double y, double mass);
void body_add_shape(Body *body, Shape *shape);
Shape *body_get_shape(Body *body, int i);
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
