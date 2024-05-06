#include <stdio.h>
#include "debug.h"
#include <stdlib.h>
#include <stdbool.h>

#define COLORBITMASK 7
#define BITMASK 15
#define SHIFTBITS 4

int checkBit(unsigned short hexNum)
{
   unsigned short leftBit = (hexNum >> SHIFTBITS * 4 - 1);
   return leftBit;
}
int checkColor(unsigned short hexNum)
{
    unsigned short color = (hexNum>> SHIFTBITS * 3) & COLORBITMASK;
    return color;
}
int checkJumpVel(unsigned short hexNum)
{
    unsigned short jumpVel = (hexNum >> SHIFTBITS * 2) & BITMASK;
    return jumpVel;
}
int checkX_VEL(unsigned short hexNum)
{
    return (hexNum >> SHIFTBITS) & BITMASK;
}
int validateInput(unsigned short hexNum)
{
    int result = 0;

    while (hexNum> 0) {
        result ^= (hexNum& 1);
        hexNum >>= 1;
    }

    return result;  
}
int main()
{
    int tokens = 0;
    unsigned short hexNum;
    tokens = scanf("%hx", &hexNum);
    printf("The input is : %hx\n", hexNum);
    printf("The first bit is : %d\n", checkBit(hexNum));
    printf("The color is : %d\n", checkColor(hexNum));
    printf("The Jump Velocity is : %d\n", checkJumpVel(hexNum));
    printf("The X Velocity is : %d\n", checkX_VEL(hexNum));
    if(validateInput(hexNum)) printf("The input has odd number of ones %d\n", validateInput(7));
    else printf("The input has even number of ones %d\n", validateInput(7));
    return 0;
}