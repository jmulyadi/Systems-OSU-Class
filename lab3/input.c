
/* Copyright 2023, Neil Kirby.  Not for disclosure without permission */

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
#include "memory.h"
#include "callback.h"
#include "debug.h"

#include "input.h"
#define START_POSITION .5 //Josh Mulyadi added this

//Josh Mulyadi
void deal_with_coin(unsigned short code, struct Sim *world)
{
	struct Coin *newCoin = allocate(false);
	newCoin->color = get_color(code);	
    newCoin->x_position = get_coin_x(code)+START_POSITION;
    newCoin->y_position = get_coin_y(code)+START_POSITION;
	insert(&(world->coins), newCoin, coinInsert, TEXT);
}

void deal_with_mascot(unsigned short code,struct Sim *world)
{
	struct Buckeye *newBrutus = allocate(true);
	newBrutus->x_position = START_POSITION;
	newBrutus->y_position = START_POSITION;
    newBrutus->x_velocity = get_VX(code);
	newBrutus->jump_velocity = get_jump_V(code);
	newBrutus->color = get_color(code);
	newBrutus->sim = world;
	insert(&(world->mascots), newBrutus, mascotInsert, TEXT);
}
void deal_with_input(unsigned short code, struct Sim *world)
{
	if(isMascot(code)) deal_with_mascot(code, world);
	if(isCoin(code)) deal_with_coin(code, world);
}
bool good_input(struct Sim *world)
{
	int tokens;
	unsigned short code;


	while( 1 ==(tokens = scanf("%hx", &code )))
	{
	    if(!isMascot(code) && !isCoin(code)) 
	    {
		  	output_bad_bits(code);
			return false;
	    }
			deal_with_input(code, world);
	}
	output_scanf(tokens);
	return( tokens == EOF);

}

// int main()
// {
// 	struct Sim *world = calloc(1, sizeof(struct Sim));
// 	world->mascots = NULL;
// 	world-> coins = NULL;	
// 	good_input(world);
//     iterate(world->coins, print_coins);
//     iterate(world->mascots, print_mascots);
// 	return 0;

// }

/* the lab 4 bonus code will have more input routines. */

