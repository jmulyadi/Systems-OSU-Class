#include <stdio.h>

#include "btp.h"
#include "n2.h"
#include "debug.h"

int main()
{
    int intialReturnVal = 6;
    if(TEXT || (GRAPHICS && (intialReturnVal = btp_initialize(0))))
    {
        //btp_brutus(1, 1, 0, 0, 1);
        btp_clear();
        btp_brutus(3, 6, 2.0, 5.0, true);

        btp_refresh();
        getchar();
        btp_clear();
        btp_brutus(3, 6, 4.0, 5.0, true);

        btp_refresh();
        getchar();


        btp_teardown();
        printf("We did Yay return = %d\n", intialReturnVal);
        
    }
    return 0;   
}