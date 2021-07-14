#include "external/open-simplex-noise.h"

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
