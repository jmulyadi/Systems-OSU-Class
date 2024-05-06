#include <stdio.h>
#include <stdbool.h>

#include "btp.h"
#include "n2.h"
#include "debug.h"

int main()
{
    int intialReturnVal = 6;
    double x = 0.5, y = 1.5;
    double x_start = x, y_start = y;
    if(TEXT || (GRAPHICS && (intialReturnVal = btp_initialize(1))))
    {
        while(x <= 13.25)
        {
            btp_clear();
            btp_brutus(2, 3, x, y, true);
            x+=1.5;
            y+=.65;
            btp_refresh();
            getchar();
        }
    }
    btp_teardown();
    printf("Brutus starts at x = %f and y = %f\n", x_start, y_start);
    printf("The return value is  %d\n", intialReturnVal);
    printf("Ending position is x = %f and y = %f\n", x, y);
    return 0;   
}