#include <stdio.h>

#include "../nature2d.h"

int main()
{
    Body *ball = body_new(5, 5, 25);

    body_add_shape(ball, (Shape*)circle_new(4, 5, 4));

    printf("Ball area is %lf\n", body_get_shape(ball, 0)->area);
    return 0;
}
