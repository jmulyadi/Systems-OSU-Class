//Josh Mulyadi
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bits.h"
#include "btp.h"

#define X_POS 0
#define Y_POS 1
#define X_VEL 2
#define Y_VEL 3
#define JUMP_VEL 4

void master_text(double brutus[], int color)
{
    int points = brutus[X_POS];
    printf("Pts\tC\t(__X_____, __Y_____)\t(__VX_____, __VY_____) ET= 0.0000\n");
    printf("%3d\t%d\t(%8.5lf, %8.5lf)\t(%9.5lf, %9.5lf)\n",points, 
    color, brutus[X_POS], brutus[Y_POS], brutus[X_VEL], brutus[Y_VEL]);
}

int main()
{
    int color = 2;
    double brutus[] = {2.5, 10.5, 14.0,-15, 0};
    printf("Brutus is at the position x = %f and y = %f and his X Velocity is %f and his Y Velocity is %f\n", brutus[X_POS], brutus[Y_POS], brutus[X_VEL], brutus[Y_VEL]);
    printf("Brutus is the color %d\n", color);
    master_text(brutus, color);
    return 0;
}