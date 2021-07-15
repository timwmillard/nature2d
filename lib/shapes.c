#include <stdlib.h>
#include <math.h>
#include "nature2d.h"

Rectangle *rectangle_new(double x, double y, double width, double height);
Rectangle *rectangle_new_v(Vec2 start, Vec2 end);


Circle *circle_new_v(Vec2 center, double radius)
{
    Circle *c = malloc(sizeof(Circle));
    if (!c) {
        return NULL;
    }
    c->center = center;
    c->radius = radius;
    c->shape.area = M_PI * radius * radius;
    return c;
}

Circle *circle_new(double x, double y, double r)
{
    return circle_new_v(vec2(x, y), r);
}


Polygon *polygon_new(double x1, double y1, double x2, double y2, double x3, double y3, ...);
Polygon *polygon_new_v(Vec2 x1, Vec2 x2, Vec2 x3, ...);
