// COpyright 2024 Neil Kirby
// Not for distribution without permission
//Josh Mulyadi
// list < > style headers first
#include <stdio.h>
#include <stdlib.h>

// includ3 constants and structs next
#include "structs.h"
#include "constants.h"
#include "debug.h"

// library headers that don't have bugs
#include "btp.h"

// include function declarations after that
#include "n2.h"

#include "bits.h"
#include "input.h"
#include "output.h"
#include "physics.h"
#include "sim.h"

// include our own file last
#include "lab3.h"
//gets the score 
#define RVAL_BAD_INIT (1)
#define RVAL_BAD_INPUT (2)
//get brutus's score
int get_score(struct Buckeye *brutus)
{
	if(is_left_of_flag(brutus))
	{
	    return (int) brutus->x_position + brutus->loot;
	}
	else
	{
	    return (int)  (brutus->x_position + brutus->y_position + brutus->loot);
	}
}


/* I own all inits.  In future labs, I might morph to master init and call
 * my init minions to do the various subtasks.  For now, I'm simple enough
 * to do it all easily myself.  I shield main for all details about
 * initializations */
//initalizes the program
bool init()
{
	/* we might take manual control over what we feed btp_init
	 * SO that we turn it off but still debug our code. */
	return(TEXT || ( GRAPHICS && btp_initialize(false)));

}

/* Put all of the toys away.  In future labs I will own more stuff and
 * call my minions to do those things. */
//tears down graphics
void teardown()
{
	if(GRAPHICS)btp_teardown();
}


/* Avoid details and call upon my minions to make it everything happen.  I own
 * those highest level things that I must own: performance timing and the
 * value we return to linux */
//the main function runs here
int main()
{
	int rval = EXIT_SUCCESS;
	double start, runtime;

	struct Sim contents = {NULL, NULL, 0.0};
	struct Sim *world = &contents;
	start = now();	// this is the very first executable statement

	if( init())
	{
		if(good_input(world)) run_sim(world);//JOsh Mulyadi changed this line
	    else rval = RVAL_BAD_INPUT;
	    teardown();
	}
	else
	{
	    rval = RVAL_BAD_INIT;	// non zero, indicates an error
	}
	
	/* at this point we are done, graphics has been torn down*/
	printf("Returning %d\n", rval);
	runtime = now() - start;
	/* after graphics has been torn down, we can freely print */
	printf("Total runtime is %.9lf seconds\n", runtime);

	return rval;
}

