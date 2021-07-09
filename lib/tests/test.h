#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <math.h>


void passed()
{
    printf("\n*********** All test passed ***********\n\n");
}

double roundp(double var, int percision)
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3767 
    // then divided by 100 so the value converted into 37.67 
    int multi = pow(10, percision);
    double value = (int)(var * multi + 0.5); 
    return (double) value / multi; 
}

#endif
