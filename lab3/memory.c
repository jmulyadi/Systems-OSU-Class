//Josh Mulyadi
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structs.h"
#include "debug.h"

#include "memory.h"
//frees memory
void freeMem(void *data)
{
    //counts 
    static int count = 0;
    count++;
    if(DEBUG) printf("DEBUG: The pointer being freed is: %p\n", data);
    if(TEXT) printf("DIAGNOSTIC: %d objects freed\n", count);
    free(data);
}
//allocates memory for mascots or coins
void *allocate(bool wantMascot)
{
    //counts amount of objects allocated
    static int objects = 1;
    if(TEXT) printf("DIAGNOSTIC: allocation #%d allocated %ld bytes\n", objects, wantMascot ? sizeof(struct Buckeye) : sizeof(struct Coin));
    void *p = wantMascot ? calloc(1, sizeof(struct Buckeye)) : calloc(1, sizeof(struct Coin));
    if(DEBUG) printf("DEBUG: The pointer being allocated is: %p\n", p);
    if(p == NULL)
    {
        printf("Allocating memory went wrong\n");
        return NULL;
    }
    objects++;
    return p;
}
