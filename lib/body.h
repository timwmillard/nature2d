#ifndef BODY_H
#define BODY_H

#include <stdlib.h>

#include "vec2.h"

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
