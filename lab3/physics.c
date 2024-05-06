#include <math.h>
#include <stdbool.h>
// COpyright 2024 Neil Kirby
// Not for distribution without permission

//Josh Mulyadi
#include "structs.h"
// list < > style headers first
#include <stdio.h>

// includ3 constants and structs next
#include "btp.h"

// defines 
#include "constants.h"

// include function declarations after that
#include "output.h"

// include our own file last
#include "physics.h"

// stuff only we should know about
#define FLAG_LIMIT (13.25)
#define G ( -10.0 )
//checks if brutus is left of the flag
bool is_left_of_flag(struct Buckeye *brutus)
{
	return(brutus->x_position < FLAG_LIMIT);

}
//upates all of brutus's position and Y velocity
static void basic_motion(struct Buckeye *brutus)
{

	brutus->x_position += DELTA_TIME * brutus->x_velocity;
	brutus->y_position += brutus->y_velocity * DELTA_TIME + 
		0.5* G * DELTA_TIME * DELTA_TIME;
	brutus->y_velocity += G * DELTA_TIME;
}
//makes necessary adjustments if brutus is in walls, floor, or ceiling
static void make_adjustments(struct Buckeye *brutus)
{
	double XA = btp_X_adjustment(brutus->x_position, brutus->y_position);
	brutus->x_position += XA;

	double YA = btp_Y_adjustment(brutus->x_position, brutus->y_position);
	brutus->y_position += YA;

	if(YA != 0.0) brutus->y_velocity = 0.0;
}

//controls and updates all brutus motion
void move_brutus(struct Buckeye *brutus)
{
	double oldX = brutus->x_position, oldY = brutus->y_position;
	double oldVY = brutus->y_velocity;
	
	basic_motion(brutus);
	make_adjustments(brutus);

	if((oldVY != 0.0) && (brutus->y_velocity == 0.0))
	{
		// if I was moving in Y and now I am not, I hit
		// the floor (or maybe a ceiling)
		if(oldVY < 0.0)floor_message(brutus);
		if(oldVY > 0.0)ceiling_message(brutus);
	}

	// I didn't move, I have to jump.
	if(oldX == brutus->x_position && oldY == brutus->y_position) 
	{
	    brutus->y_velocity = brutus->jump_velocity;
	    jump_message(brutus);
	}
	if(!is_left_of_flag(brutus)) flag_message(brutus);//Josh Mulyadi added this line
}
//JOsh Mulyadi code below
//checks if coin and brutus is close enough to collect	
bool close_enough(struct Coin *c, struct Buckeye *b)
{
	double x_c = c->x_position;
	double y_c = c->y_position;
	double x_b = b->x_position;
	double y_b = b->y_position;
	//distance formula
	return sqrt((x_c - x_b) * (x_c - x_b) + (y_c - y_b) * (y_c - y_b)) <=.5;
}

