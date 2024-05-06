/*Josh Mulyadi*/
#include <stdio.h>
#include "include.h"
#include "lab1.h"

int foo(int x)    
{return 2* x;}

int doubleIt(int x)
{
    return 2* x;
}
int main()
{
    int i = INIT, j;

    printf("Before, i=%d\n", i);
    j = doubleIt(i);
    printf("After, j=%d\n", j);
    /*Returning 0 to the sytem signifies no errors*/
    return 0;
}
