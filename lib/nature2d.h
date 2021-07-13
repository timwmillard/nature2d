#ifndef NATURE2D_H
#define NATURE2D_H

#include <math.h>

#include "external/open-simplex-noise.h"

#if defined(__GNUC__)
#   define    HUGE_VAL     __builtin_huge_val()
#   define    HUGE_VALF    __builtin_huge_valf()
#   define    HUGE_VALL    __builtin_huge_vall()
#   define    NAN          __builtin_nanf("0x7fc00000")
#else
#   define    HUGE_VAL     1e500
#   define    HUGE_VALF    1e50f
#   define    HUGE_VALL    1e5000L
#   define    NAN          __nan()
#endif

#define INFINITY    HUGE_VALF

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
 * Noise is wrapper for Open Simplex Noise functions
 * 
 */
static struct osn_context *__osn_context__;

static inline void noise_seed(int seed)
{
    open_simplex_noise(seed, &__osn_context__);
}

static inline double noise(double x)
{
    return open_simplex_noise2(__osn_context__, x, 0.0);
}

static inline double noise2(double x, double y)
{
    return open_simplex_noise2(__osn_context__, x, y);
}

static inline double noise3(double x, double y, double z)
{
    return open_simplex_noise3(__osn_context__, x, y, z);
}

static inline void destroy_noise()
{
    open_simplex_noise_free(__osn_context__);
}


/**
 * Noise that are thread safe
 * 
 * Noise *noise = noise_new();
 * double x = noise_get(noise, 1);
 * 
 */
typedef struct{
    struct osn_context *context
} Noise;
Noise *noise_new();
double noise_get(Noise *n, double x);
double noise_get2(Noise *n, double x, double y);
double noise_get3(Noise *n, double x, double y, double z);
void noise_destroy(Noise *n);

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
 * Body function
 * 
 *
 */

typedef struct Body {
    Vec2 pos;
    Vec2 vel;
    Vec2 acc;
    double mass;
} Body;

Body *body_alloc();
void body_init(Body *body, Vec2 pos, double mass);
Body *body_new(Vec2 pos, double mass);
Body *body_new_xy(double x, double y, double mass);
void body_apply_force(Body *body, Vec2 force);
void body_apply_gravity(Body *body, Vec2 force);
void body_update(Body *body, double dt);
void body_destroy(Body *body);


#endif
