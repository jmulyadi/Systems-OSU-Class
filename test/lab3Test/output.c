// Copyright 2024 Neil Kirby
// Not for distribution without permission

//Josh Mulyadi
// Include < > style headers first:
#include <stdio.h>

// include debug, subscripts, etc before functions
#include "structs.h"
#include "debug.h"
#include "btp.h"
#include "constants.h"
#include "libll.h"

// include any function headers now, other than our own.
#include "n2.h"
#include "lab3.h"
#include "sim.h"
#include "callback.h"
#include "memory.h"

// include the header file for this file as the very last include
#include "output.h"
#define WAIT 4.0 // Josh Mulyadi added this

//draws the coins
static void draw_coin(void * data)
{
	struct Coin *cash = data;
	btp_coin( cash->color, cash->x_position, cash->y_position);
}
//draws brutus
static void draw_brutus(void * data)
{
	struct Buckeye *brutus = data;
	btp_brutus( get_score(brutus), brutus->color, 
		brutus->x_position, brutus->y_position, true);
}
//handing all drawing
static void master_draw(struct Sim *world)
{

	btp_clear();
	btp_time( (int) (1000 * world->elapsed));

	iterate(world->mascots, draw_brutus);
	iterate(world->coins, draw_coin);

	btp_refresh();
	microsleep( (unsigned int) (DELTA_TIME * 1000000));
}
//prints the coins
static void print_coin(void * data)
{
	struct Coin *cash = data;

	printf("%d    (%8.5lf, %8.5lf)\n",
	    cash->color, cash->x_position, cash->y_position);

}
//prints brutus
static void print_brutus(void * data)
{
	struct Buckeye *brutus = data;

	printf("%3d    %d    (%8.5lf, %8.5lf)    (%9.5lf, %9.5lf)\n",
	    get_score(brutus), brutus->color, 
	    brutus->x_position,
	    brutus->y_position,
	    brutus->x_velocity,
	    brutus->y_velocity);

}
//handles all printing
static void master_print(struct Sim *world)
{
	// do the header, then brutus
	
printf(
    "\nPts    C    (__X_____, __Y_____)    (__VX_____, __VY_____) ET=%8.5lf\n",
    world->elapsed);
    	iterate(world->mascots, print_brutus);
	printf( "\nC    (__X_____, __Y_____)\n" );
	iterate(world->coins, print_coin);
}
//handles the final drawing
static void final_draw(struct Sim *world)
{
	double delay = 0.0;
	while (delay < WAIT)
	{
	    master_draw(world);
	    delay += DELTA_TIME;
	}
}
//handles final output
void final_output(struct Sim *world)
{
	if(GRAPHICS)
	{
	    final_draw(world);
	}
	if(TEXT)
	{
	    master_print(world);
	}
}
//handles all output
void master_output(struct Sim *world)
{
	if(GRAPHICS)master_draw(world);
	if(TEXT)master_print(world);
}

// messages
//handles flag message
void flag_message(struct Buckeye *brutus)
{
	if(GRAPHICS)
	{
	    btp_status("Brutus makes it to the flag");
	}
	if(TEXT)
	{
	    printf("\nBrutus makes it to the flag!\n");
	}
}
//handles loot message
void loot_message(struct Buckeye *brutus)
{
	if(TEXT)printf("Brutus finds loot at %8.5lf, %8.5lf\n",
		brutus->x_position, brutus->y_position);
	if(GRAPHICS)btp_status("Brutus finds some loot");
}
//handles ceiling messages
void ceiling_message(struct Buckeye *brutus)
{
	if(TEXT)printf("Brutus hits the ceiling at %8.5lf, %8.5lf\n",
		brutus->x_position, brutus->y_position);
	if(GRAPHICS)btp_status("Brutus hits the ceiling");

}

//floor ceiling messages
void floor_message(struct Buckeye *brutus)
{
	if(TEXT)printf("Brutus hits the floor at %8.5lf, %8.5lf\n",
		brutus->x_position, brutus->y_position);
	if(GRAPHICS)btp_status("Brutus hits the floor");

}
//handles jump messages
void jump_message(struct Buckeye *brutus)
{
	if(TEXT)printf("Brutus jumps at %8.5lf, %8.5lf\n",
		brutus->x_position, brutus->y_position);
	if(GRAPHICS)btp_status("Brutus jumps");

}

//handles bad bits output
void output_bad_bits(unsigned short code)
{
	if(TEXT)printf("ERROR: invalid input: hex %X\n", code);
}
//handles scanf output
void output_scanf(int tokens)
{
	if(TEXT)printf("scanf returned %d\n", tokens);
}
//Josh Mulyadi Code under
//handles clearing mascot 
void clear_mascots(struct Sim *world)
{
	if(TEXT) printf("Clearing mascots list...\n");
    int mascots_deleted = deleteSome(&(world->mascots), all, NULL, freeMem, TEXT);
    if(TEXT) printf("     %d mascots deleted.\n", mascots_deleted);
}
//handles clearing coins
void clear_coins(struct Sim *world)
{
	if(TEXT) printf("Clearing coins list...\n");
    int coins_deleted = deleteSome(&(world->coins), all, NULL, freeMem, TEXT);
    if(TEXT) printf("     %d coins deleted.\n",coins_deleted);
}