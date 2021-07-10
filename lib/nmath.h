#ifndef NMATH_H
#define NMATH_H

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

double map(double value, double start1, double stop1, double start2, double stop2)
{
    return (value - start1) / (stop1 - start1) * (stop2 - start2) + start2;
}

double max(double a, double b)
{
    return (a > b)? a : b;
}

double min(double a, double b)
{
    return (a < b)? a : b;
}

/**
 * Noise is wrapper for Open Simplex Noise functions
 * 
 */
static struct osn_context *__osn_context__;

void noise_seed(int seed)
{
    open_simplex_noise(seed, &__osn_context__);
}

double noise(double x)
{
    return open_simplex_noise2(__osn_context__, x, 0.0);
}

double noise2(double x, double y)
{
    return open_simplex_noise2(__osn_context__, x, y);
}

double noise3(double x, double y, double z)
{
    return open_simplex_noise3(__osn_context__, x, y, z);
}

void destroy_noise()
{
    open_simplex_noise_free(__osn_context__);
}

#endif
