#include <stdlib.h>

#include "nature2d.h"
#include "bucket.h"


Body *body_alloc()
{
    return (Body *) malloc(sizeof(Body));
}

void body_init(Body *body, Vec2 pos, double mass)
{
    body->pos = pos;
    body->vel = (Vec2) {0.0, 0.0};
    body->acc = (Vec2) {0.0, 0.0};
    body->mass = mass;

    body->shapes = bucket_new(4);
}

Body *body_new_v(Vec2 pos, double mass)
{
    // Can't have zero mass body
    if (mass==0)
        return NULL;

    Body *body = body_alloc();
    if (!body)
        return NULL;

    body_init(body, pos, mass);

    return body;
}

Body *body_new(double x, double y, double mass)
{
    Vec2 pos = vec2(x, y);
    return body_new_v(pos, mass);
}

void body_add_shape(Body *body, Shape *shape)
{
    bucket_add(body->shapes, shape);
}

Shape *body_get_shape(Body *body, int i)
{
    return bucket_at(body->shapes, i);
}

void body_apply_force(Body *body, Vec2 force)
{
    force = vec2_div(force, body->mass);
    body->acc = vec2_add(body->acc, force);
}

void body_apply_gravity(Body *body, Vec2 force)
{
    body->acc = vec2_add(body->acc, force);
}

void body_update(Body *body, double dt)
{
    body->acc = vec2_mult(body->acc, dt);
    body->vel = vec2_add(body->vel, body->acc);
    body->pos = vec2_add(body->pos, body->vel);

    body->acc = vec2zero;
}

void body_destroy(Body *body)
{
    free(body);
}
