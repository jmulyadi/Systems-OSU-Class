//Josh Mulyadi
#include <stdbool.h>
#include <stdio.h>
#include "debug.h"

#define SHIFTBITS 4
#define COLORBITMASK 7
#define BITMASK 15
#define SHIFTBITS 4
#define SHIFTCOLOR 3
#define SHIFTJUMP 2
#define X_POS 0
#define Y_POS 1
#define X_VEL 2
#define Y_VEL 3
#define JUMP_VEL 4
// gets the color of the hex number
int checkColor(unsigned short hexNum)
{
    unsigned short color = (hexNum>> SHIFTBITS * SHIFTCOLOR) & COLORBITMASK;
    return color;
}
// gets the Jump Velocity of the hex number
double checkJumpVel(unsigned short hexNum)
{
    unsigned short jumpVel = (hexNum >> SHIFTBITS * SHIFTJUMP) & BITMASK;
    return jumpVel;
}
// gets the X Velocity of the hex number
double check_X_VEL(unsigned short hexNum)
{
    return (hexNum >> SHIFTBITS) & BITMASK;
}
//checks to see if the input is valid
int validateInput(unsigned short hexNum, double brutus[], int color)
{
    int result = 0;

    while (hexNum> 0) {
        result ^= (hexNum& 1);
        hexNum >>= 1;
    }
    if(DEBUG) printf("The input was: %hx\nThe color is: %d\nThe X Velocity is: %f\nThe Jump Velocity is: %f\n", result, color, brutus[X_VEL], brutus[JUMP_VEL]);
    return !result && color && brutus[X_VEL] && brutus[JUMP_VEL];  
}
//puts all of the decoded numbers into brutus and returns color
int decodeBits(unsigned short hexNum, double brutus[])
{
    brutus[Y_POS] = .5;
    brutus[X_POS] = .5;
    brutus[Y_VEL] = 0;
    brutus[JUMP_VEL] = checkJumpVel(hexNum);
    brutus[X_VEL] = check_X_VEL(hexNum);
    return checkColor(hexNum);
}