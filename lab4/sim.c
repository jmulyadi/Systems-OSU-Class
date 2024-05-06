//Josh Mulyadi
// COpyright 2024 Neil Kirby
// Not for distribution without permission

// list < > style headers first
#include <stdio.h>
#include <stdlib.h>

// includ3 constants and structs next
#include "structs.h"
#include "constants.h"
#include "debug.h"

// library headers that don't have bugs
#include "btp.h"
#include "linkedlist.h"

// include function declarations after that
#include "n2.h"

#include "bits.h"
#include "callbacks.h"
#include "output.h"
#include "physics.h"
#include "memory.h"
#include "curses.h"

// include our own file last
#include "sim.h"
//checks if brutus and coin match
bool my_coin(void *data, void *helper)
{
	struct Coin *cp = data;
	struct Buckeye *brutus = helper;

	return( (brutus->color == cp->color) && 
		(close_enough(brutus->x_position, brutus->y_position,
				cp->x_position, cp->y_position)
		)
	    );

}
//handles brutus picking up coins
void sweep(void *data)
{
	struct Buckeye *brutus = data;
	int winnings;

	winnings = deleteSome(&brutus->world->coins, my_coin, brutus, 
			free_struct, TEXT);
	if(winnings > 0)
	{
	    brutus->loot += winnings;
	    loot_message(brutus);
	}
}
//collects coins
void collect_coins(struct Sim *world)
{
	iterate(world->mascots, sweep);
}
//gets the score
int get_score(struct Buckeye *brutus)
{
	int score = brutus->loot;
	if(is_left_of_flag(brutus, NULL))
	{
	    score += (int) brutus->x_position;
	}
	else
	{
	    score += (int)  (brutus->x_position + brutus->y_position);
	}
	return score;
}
//checks if the game should keep going
static bool game_on(struct Sim *world)
{
	return( any(world->mascots, is_left_of_flag, NULL));
}
//clears a list
void clear_a_list(void *avp, char *name)
{
	int d = 0;
	// output belongs in output.c
	if(TEXT)printf("Clearing %s list...\n", name);
	d = deleteSome(avp, always_true, NULL, free_struct, TEXT);
	if(TEXT)printf("     %d %s deleted.\n", d, name);
}
//clears all lists
void clear_lists(struct Sim *world)
{
	clear_a_list(&world->mascots, "mascots");
	clear_a_list(&world->coins, "coins");
}

//reads keyboard input
void keyboard_input(struct Sim *world)
{
	world->buffer_count = 0;
	while(world->buffer_count < BUFFER_SIZE)
	{
		int c = btp_getch();
		if(c == ERR) break;
		(world->buffer)[world->buffer_count] = c;
		(world->buffer_count)++;
	}
}
//runs the sim
void run_sim(struct Sim *world)
{
	while(game_on(world))
	{
	    sort(world->mascots, brutus_Y_order);
	    master_output(world);

	    world->elapsed += DELTA_TIME;
		//bonus
		if(world->bonus) keyboard_input(world);
	    move_everyone(world);
	    collect_coins(world);
	}
	sort(world->mascots, brutus_score_order);
	final_output(world);
	clear_lists(world);
}
//fills the coins
static void fill_coin(unsigned short code, struct Coin *cash)
{
	cash->x_position = 0.5 + get_coin_X(code);
	cash->y_position = 0.5 + get_coin_Y(code);
	cash->color = get_color(code);
}
//fills brutus
static void fill_brutus(struct Sim *world, unsigned short code, struct Buckeye *brutus)
{
	// start at (0.5, 0.5)
	brutus->x_position = 0.5;
	brutus->y_position = 0.5;
	brutus->x_velocity = get_VX(code);
	// we aren't falling at the moment
	brutus->y_velocity = 0.0;
	brutus->jump_velocity = get_jump_V(code);
	brutus->color = get_color(code);
	brutus->world = world;
	if(world->bonus) brutus->movement_velocity = brutus->x_velocity;
}
//deals with the coins
static void deal_with_coin(unsigned short code, struct Sim *world)
{
	struct Coin *cash;

	if( cash = allocate_struct(sizeof(struct Coin)))
	{
	    fill_coin(code, cash);
	    if(!insert(&world->coins, cash, coin_color_order, TEXT))
	    {
	    	free_struct(cash);
	    }
	}

}
//deals with brutus
static void deal_with_brutus(unsigned short code, struct Sim *world)
{
	struct Buckeye *brutus;
	if( brutus = allocate_struct(sizeof(struct Buckeye)))
	{
	    fill_brutus(world, code, brutus);
	    if(!insert(&world->mascots, brutus, brutus_Y_order, TEXT))
	    {
	    	free_struct(brutus);
	    }
	}

}
//deals with input
void deal_with_input(unsigned short code, struct Sim *world)
{
	if(is_coin(code)) deal_with_coin(code, world);
	if(is_brutus(code)) deal_with_brutus(code, world);
}



