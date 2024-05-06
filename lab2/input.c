//Josh Mulyadi
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "btp.h"
#include "bits.h"
#include "output.h"
#include "n2.h"

//checks if the one number scaned in is good input
int isInputGood(unsigned short hexNum, double brutus[], int color)
{
    if(!validateInput(hexNum, brutus, color)){
        printf("ERROR: invalid input: hex %hx\n", hexNum);
        teardown();
        return false;
    }
    return true;
}
//handles input reading
int readInput()
{
    int tokens = 0;
    unsigned short hexNum;
    double time;
    double brutus[] = {.5, .5, 0, 0, 0};
    while(1 == (tokens = scanf("%hx", &hexNum)))
    {
        int color = decodeBits(hexNum, brutus);
        if(!isInputGood(hexNum, brutus, color)) return false; 
        time = master_output(brutus, color);  
        flag_graphics(brutus, color, time);
    }
    teardown();
    printf("scanf returned %d\n", tokens);
    return -1 == tokens;
}