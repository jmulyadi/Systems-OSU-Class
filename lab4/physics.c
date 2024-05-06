//Josh Mulyadi
// COpyright 2024 Neil Kirby
// Not for distribution without permission

// list < > style headers first
#include <stdio.h>
#include <math.h>

// includ3 constants and structs next
#include "structs.h"
#include "btp.h"
#include "libll.h"

// defines 
#include "constants.h"

// include function declarations after that
#include "output.h"

// include our own file last
#include "physics.h"

// stuff only we should know about
#define FLAG_LIMIT (13.25)
#define G ( -10.0 )
//checks to see if brutus is close enough to the coin
bool close_enough( double x1, double y1, double x2, double y2)
{
	double dx = x1-x2;
	double dy = y1-y2;
	double dist = sqrt( (dx*dx) + (dy*dy));
	return (dist <= 0.5);

}
//checks if brutus is left of flag
bool is_left_of_flag(void *data, void *helper)
{
	struct Buckeye *brutus = data;
	return( brutus->x_position < FLAG_LIMIT);

}
//does basic motion
static void basic_motion(struct Buckeye *brutus)
{

	brutus->x_position += DELTA_TIME * brutus->x_velocity;
	brutus->y_position += brutus->y_velocity * DELTA_TIME + 
		0.5* G * DELTA_TIME * DELTA_TIME;
	brutus->y_velocity += G * DELTA_TIME;
}
//adjusts brutus if needed
static void make_adjustments(struct Buckeye *brutus)
{
	double XA = btp_X_adjustment(brutus->x_position, brutus->y_position);
	brutus->x_position += XA;
	double YA = btp_Y_adjustment(brutus->x_position, brutus->y_position);
	brutus->y_position += YA;

	if(YA != 0.0) brutus->y_velocity = 0.0;
}
//handles hitting ceiling and floor
static void floor_and_ceiling(double oldVY, struct Buckeye *brutus)
{
	if((oldVY != 0.0) && (brutus->y_velocity == 0.0))
	{
		// if I was moving in Y and now I am not, I hit
		// the floor (or maybe a ceiling)
		if(oldVY < 0.0)floor_message(brutus);
		if(oldVY > 0.0)ceiling_message(brutus);
	}

}
//does jump
static void maybe_jump(double oldX, double oldY, struct Buckeye *brutus)
{
	// I didn't move, I have to jump.
	if(oldX == brutus->x_position && oldY == brutus->y_position) 
	{
	    brutus->y_velocity = brutus->jump_velocity;
	    jump_message(brutus);
	}

}
//moves brutus
static void move_brutus(void * data)
{
	struct Buckeye *brutus = data;

	if(is_left_of_flag(brutus, NULL))
	{

	    double oldX = brutus->x_position, oldY = brutus->y_position;
	    double oldVY = brutus->y_velocity;

	    basic_motion(brutus);
	    make_adjustments(brutus);
	    floor_and_ceiling(oldVY, brutus);
		if(brutus->world->bonus) take_action(brutus->x_position, brutus->y_position, brutus);
		else maybe_jump(oldX, oldY, brutus);
	    if(!is_left_of_flag(brutus, NULL))flag_message(brutus);

	}
}
//moves everyone	
void move_everyone(struct Sim *world)
{
	iterate(world->mascots, move_brutus);
}
//jumps
void jump(struct Buckeye *brutus)
{
	if(brutus->y_velocity == 0)
	{
		brutus->y_velocity = brutus->jump_velocity;
		jump_message(brutus);
	}
}
//moves left
void left(struct Buckeye *brutus)
{
	brutus->x_velocity = -1 * brutus ->movement_velocity;
}
//moves right
void right(struct Buckeye *brutus)
{
	brutus->x_velocity = brutus ->movement_velocity;
}
// stops
void stop(struct Buckeye *brutus)
{
	brutus->x_velocity = 0;
}
//bonus mode stuff
//reacts to input
void react_to_input(double oldX, double oldY, struct Buckeye *brutus)
{
	struct Action responses[256] = {{0, NULL}};
	responses['w'] = (struct Action){1, jump};
	responses['a'] = (struct Action){1, left};
	responses['s'] = (struct Action){1, stop};
	responses['d'] = (struct Action){1, right};
	responses['i'] = (struct Action){2, jump};
	responses['j'] = (struct Action){2, left};
	responses['l'] = (struct Action){2, stop};
	responses['k'] = (struct Action){2, right};
	responses['8'] = (struct Action){3, jump};
	responses['4'] = (struct Action){3, left};
	responses['6'] = (struct Action){3, right};
	responses['5'] = (struct Action){3, stop};
	
	for(int i = 0; i < brutus->world->buffer_count; i++)	
	{
		if(brutus->color == responses[brutus->world->buffer[i]].color) responses[brutus->world->buffer[i]].fp(brutus);
	}
}
//takes actions 
void take_action(double oldX, double oldY, struct Buckeye *brutus)
{
	typedef void (*Jump)(double oldX, double oldY, struct Buckeye *brutus);
	Jump fpArr[] = {NULL, react_to_input, react_to_input, react_to_input, maybe_jump, maybe_jump, maybe_jump, maybe_jump};
	fpArr[brutus->color](oldX, oldY, brutus);
}

