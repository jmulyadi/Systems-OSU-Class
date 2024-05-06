//Josh Mulyadi
#include <stdio.h>
#include "debug.h"
#include <stdlib.h>
#include "n2.h"
#include "btp.h"
#include "input.h"
#include "output.h"

#define RVAL_BAD_INPUT 2
#define RVAL_BAD_INIT 1
//is the main file
int main()
{
    int rval = EXIT_SUCCESS;
    double start, runtime;
   
    start = now();
    if( init())
    {
        if( !good_input_run()) rval = RVAL_BAD_INPUT;
    }
    else
    {
        rval = RVAL_BAD_INIT;  
    }
    printf("Returning %d\n", rval);
    runtime = now() - start;
    printf("Total runtime is %.9lf seconds\n", runtime);
    return rval;
}   
