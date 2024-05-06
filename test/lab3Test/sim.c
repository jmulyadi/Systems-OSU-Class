//Josh Mulyadi
// put system shared libraries first - they are unlikely to have bugs.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// put our own header files next.
// Start with one that are #define and structs

// includes for header files based on our own C code goes here.
// Always include the header for the file itself
// THis validates the header declarations against the defninitions.
// We are spoiled by our automatically generated headers, but we still
// validate them.  We put the include for this file dead last.
#include "structs.h"
#include "libll.h"
#include "output.h"
#include "bits.h"
#include "physics.h"
#include "lab3.h"
#include "input.h"
#include "memory.h"
#include "callback.h"
#include "debug.h"
#include "constants.h"

#include "sim.h"
//frees everything
void free_all(struct Sim *world)
{
    clear_mascots(world);
    clear_coins(world);
}
//collects coins
void collect_coins(struct Sim *world)
{
    iterate(world->mascots, sweep_coins);
}
//checks if the sim should keep going
bool game_on(struct Sim *world)
{
    return any(world->mascots, all_left_of_flag, "");
}
//run the sim
void run_sim(struct Sim *world)
{
    while(game_on(world))
    {
        //sort mascots
        sort(world->mascots, sort_mascots_y);
        master_output(world);
        //Update Time
        world->elapsed += DELTA_TIME;
        //move everyone iterate something
        iterate(world->mascots, move);
        //collect coins  
        collect_coins(world);
    }
    //sort by points final output 
    sort(world->mascots, sort_points);
    final_output(world); 
    //clear everything
    free_all(world);
}