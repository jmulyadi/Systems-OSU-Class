//Josh Mulyadi
#include <stdio.h>
#include "debug.h"
#include <stdlib.h>
#include <stdbool.h>
#include "input.h"
#include "btp.h"
#include "n2.h"
#include "physics.h"

#define DELTATIME (1.0/32.0)
#define X_POS 0
#define Y_POS 1
#define X_VEL 2
#define Y_VEL 3
#define JUMP_VEL 4
#define END 13.25
#define PAUSE 4
#define CEILING 9.5

//prints the ending text
void endText(double brutus[], double time, int color)
{
    printf("Brutus makes it to the flag!\n\n");
    int points = brutus[X_POS] + brutus[Y_POS];
    printf("Pts    C    (__X_____, __Y_____)    (__VX_____, __VY_____) ET=%8.5f\n", time);
    printf("%3d    %d    (%8.5f, %8.5f)    (%9.5f, %9.5f)\n",points, color, brutus[X_POS], brutus[Y_POS], brutus[X_VEL], brutus[Y_VEL]);
    move_brutus(brutus);
    both_shift(brutus, &time, color);
}
//handles text for brutus jumping
void brutusJumpText(double *time, double brutus[], int color)
{
    if(TEXT){   
        *time+= DELTATIME;
        printf("\nPts    C    (__X_____, __Y_____)    (__VX_____, __VY_____) ET=%8.5f\n", *time);
        printf("%3d    %d    (%8.5f, %8.5f)    (%9.5f, %9.5f)\n",(int)brutus[X_POS], color, brutus[X_POS], brutus[Y_POS]+btp_Y_adjustment(brutus[X_POS], brutus[Y_POS]), brutus[X_VEL], brutus[Y_VEL]=0);
        printf("Brutus jumps at %8.5f, %8.5f\n", brutus[X_POS], brutus[Y_POS]+btp_Y_adjustment(brutus[X_POS], brutus[Y_POS]));
    }
    else btp_status("Brutus Jumped");
}
//handles text for when brutus hits the ceiling
void brutusCeilingText(double brutus[], double temp_Y_POS)
{
    if(brutus[Y_POS] > .5)
    {
        // Check if Brutus is hitting the ceiling or floor
        if(TEXT && brutus[Y_VEL] > 0.0 && temp_Y_POS >= CEILING) printf("Brutus hits the ceiling at %8.5f, %8.5f\n", brutus[X_POS], temp_Y_POS);
        else if(brutus[Y_VEL] > 0.0 && temp_Y_POS >= CEILING) btp_status("Brutus hit the Ceiling");
    }
}
//prints text for when brutus hits the floor
void printHitFloorCeiling(double brutus[], double original_Y_VEL)
{
    if(TEXT && original_Y_VEL < 0 && brutus[Y_VEL] == 0) printf("Brutus hits the floor at %8.5f, %8.5f\n", brutus[X_POS], brutus[Y_POS]);
    else if(GRAPHICS && original_Y_VEL < 0 && brutus[Y_VEL] == 0) btp_status("Brutus hit the floor");
    //prints while brutus is on the floor
    if(DEBUG && brutus[Y_POS] == .5) printf("Brutus is on the floor\nThe X position is: %f and the Y position is %f\n", brutus[X_POS], brutus[Y_POS]); 

}
//controls all main text
void master_text(double brutus[], int color)
{
    double time = 0;
    //brutus[X_POS]< 13.25
    printf("\n");
    while(brutus[X_POS]<END)
    {
        double original_Y_VEL = brutus[Y_VEL];
        printf("Pts    C    (__X_____, __Y_____)    (__VX_____, __VY_____) ET=%8.5f\n", time);
        printf("%3d    %d    (%8.5f, %8.5f)    (%9.5f, %9.5f)\n",(int)brutus[X_POS], color, brutus[X_POS], brutus[Y_POS], brutus[X_VEL], brutus[Y_VEL]);
        move_brutus(brutus);
        both_shift(brutus, &time, color);
        printHitFloorCeiling(brutus, original_Y_VEL);
        printf("\n");
        time += DELTATIME;
    }
    endText(brutus, time, color);
}
//adjusts the time
void time_adjust(double *time)
{
    microsleep(DELTATIME * 1000000);
    btp_time((int)(*time * 1000000));
    *time += DELTATIME;
}
//does all the brutus writing on the screen
void writeGraphics(double brutus[], int color)
{
    btp_clear();
    //int btp_brutus(int score, int color, double X, double Y, bool faces_right);
    btp_brutus((int)brutus[X_POS], color, brutus[X_POS], brutus[Y_POS], true);
    move_brutus(brutus);
}
//controls all graphics
double master_graphics(double brutus[], int color)
{
    double time = 0;
    while(brutus[X_POS] < END)
    {
        double original_Y_VEL = brutus[Y_VEL];
        writeGraphics(brutus, color);
        both_shift(brutus, 0, color);
        printHitFloorCeiling(brutus, original_Y_VEL);
        time_adjust(&time);
        btp_refresh();
    }
    time+=DELTATIME;
    btp_status("Brutus hit the Flagpole");
    return time;
}
//controls the graphics when brutus hits the flad
void flag_graphics(double brutus[], int color, double time)
{
    if(GRAPHICS) 
    {
        int start = now();
        while(now()-start < PAUSE)
        {
            btp_clear();
            //int btp_brutus(int score, int color, double X, double Y, bool faces_right);
            btp_brutus((int)(brutus[X_POS] + brutus[Y_POS]), color, brutus[X_POS], brutus[Y_POS], true);
            microsleep(DELTATIME * 1000000);
            btp_time((int)(time * 1000000));
            btp_refresh();
        }
    }
}
//controls all output
double master_output(double brutus[], int color)
{
    double res = 0;
    if(TEXT) master_text(brutus, color);
    if(GRAPHICS) res = master_graphics(brutus, color);
    return res;
}
//initializes the text or graphics
int init()
{
    return (TEXT || (GRAPHICS && btp_initialize(DEBUG)));
}
//checks if input can run
int good_input_run()
{
    // x_pos, y_pos, x_vel, y_vel, jump_vel
    //check if the input is valid
    return readInput();
}
//tears down the grahics
void teardown()
{
    if(GRAPHICS) btp_teardown();
}