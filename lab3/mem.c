//Josh Mulyadi
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structs.h"

void freeMem(void *data)
{
    //counts 
    static int count = 0;
    count++;
    printf("DIAGNOSTIC: %d objects freed\n", count);
    free(data);
}
void *allocate(bool wantMascot)
{
    //counts amount of objects allocated
    static int objects = 2;
    printf("DIAGNOSTIC: allocation #%d allocated %ld bytes\n", objects, wantMascot ? sizeof(struct Buckeye) : sizeof(struct Coin));
    void *p = wantMascot ? calloc(1, sizeof(struct Buckeye)) : calloc(1, sizeof(struct Coin));
    if(p == NULL)
    {
        printf("Allocating memory went wrong\n");
        return NULL;
    }
    objects++;
    return p;
}
void *makeWorld()
{
    void *p = calloc(1, sizeof(struct Sim));
    if(p==NULL){
        printf("Allocating memory for the WORLD went wrong\n");
        return NULL;
    }
    printf("DIAGNOSTIC: allocation #1 allocated %d bytes\n", (int)sizeof(struct Sim));
    return p;
}
int main()
{
    struct Sim *world = makeWorld();
    struct Buckeye *daddy = allocate(true);
    struct Coin *money = allocate(false);
    printf("The elapsed time is: %f\n", world->elapsed);
    printf("The mascots x position is: %f\n", daddy->x_position);
    printf("The Coins y position is: %f\n", money->x_position);
    freeMem(world);
    freeMem(daddy);
    freeMem(money);
    return 0;
}

