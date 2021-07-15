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
    body->vel = vec2zero;
    body->force = vec2zero;
    body->gravity = vec2zero;
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
    body->force = vec2_add(body->force, force);
}

void body_set_gravity(Body *body, Vec2 force)
{
    body->gravity = force;
}

void body_update(Body *body, double dt)
{
    // Newtons law
    // F = ma or a = F / m
    Vec2 acc = vec2_div(body->force, body->mass);

    // Apply gravity (not effected by mass)
    acc = vec2_add(acc, body->gravity);

    // Mutiply by delta time
    acc = vec2_mult(acc, dt);

    body->vel = vec2_add(body->vel, acc);
    body->pos = vec2_add(body->pos, body->vel);

    body->force = vec2zero;
}

void body_destroy(Body *body)
{
    free(body);
}
