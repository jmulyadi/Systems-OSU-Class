//Josh Mulyadi
#include <stdio.h>
#include "btp.h"
#include "debug.h"
#include "output.h"

#define DELTATIME (1.0/32.0)
#define G (-10.0)
#define X_POS 0
#define Y_POS 1
#define X_VEL 2
#define Y_VEL 3
#define JUMP_VEL 4
#define ERR .00001   


//adjusts brutus's x position
void X_shift(double brutus[], double *time, int color)
{
    brutus[X_POS] += btp_X_adjustment(brutus[X_POS], brutus[Y_POS]);
    double X_adjust =btp_X_adjustment(brutus[X_POS] + ERR, brutus[Y_POS]);   
    if(DEBUG) printf("The X_adjust value is : %f\n", btp_X_adjustment(brutus[X_POS], brutus[Y_POS]));
    // Check if Brutus is hitting a wall
        if (X_adjust && brutus[Y_POS] <= .5)
        {
            brutusJumpText(time, brutus, color);
            
            // If hitting a wall and on the floor, make Brutus jump
            brutus[Y_VEL] = brutus[JUMP_VEL];
        }
}
//handles all the shifting of brutus in the Y
void Y_shift(double brutus[])
{
    double Y_adjust = btp_Y_adjustment(brutus[X_POS], brutus[Y_POS]);
    // Check if Brutus is on the floor
    double temp_Y_POS = brutus[Y_POS] + Y_adjust;
    if(DEBUG) printf("The Y_adjust value is : %f\n", Y_adjust);
    if (Y_adjust)
    {
        brutusCeilingText(brutus, temp_Y_POS);
        if(brutus[Y_VEL] != brutus[JUMP_VEL]) brutus[Y_VEL] = 0;
    }
    
    brutus[Y_POS] += Y_adjust;
}
//handles all the shifting
void both_shift(double brutus[], double *time, int color)
{
    X_shift(brutus, time, color);
    Y_shift(brutus);
}

// x_pos, y_pos, x_vel, y_vel, jump_vel
void move_brutus(double brutus[])
{
    brutus[X_POS]+= DELTATIME * brutus[X_VEL];
    brutus[Y_POS]+= DELTATIME * brutus[Y_VEL] + .5 * G * DELTATIME * DELTATIME;
    brutus[Y_VEL]+= DELTATIME * G;
}
