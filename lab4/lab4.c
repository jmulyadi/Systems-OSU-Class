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

// include function declarations after that
#include "n2.h"

#include "bits.h"
#include "input.h"
#include "output.h"
#include "sim.h"

// include our own file last
#include "lab4.h"



#define RVAL_BAD_INIT (1)
#define RVAL_BAD_INPUT (2)

//initalizes
/* I own all inits.  In future labs, I might morph to master init and call
 * my init minions to do the various subtasks.  For now, I'm simple enough
 * to do it all easily myself.  I shield main for all details about
 * initializations */
bool init(int argc)
{
	/* we might take manual control over what we feed btp_init
	 * SO that we turn it off but still debug our code. */
	if(DEBUG) printf("DEBUG: lab4.c: argc was %d", argc);
	if(argc < 2 || (argc == 3 && TEXT) || argc > 3) return false;
	return(TEXT || ( GRAPHICS && btp_initialize(false)));

}
//tears down the graphics
/* Put all of the toys away.  In future labs I will own more stuff and
 * call my minions to do those things. */
void teardown()
{
	if(GRAPHICS)btp_teardown();
}

//prints ending stuff
void print_end(double start, int rval)
{
	printf("Returning %d\n", rval);
	double runtime = now() - start;
	/* after graphics has been torn down, we can freely print */
	printf("Total runtime is %.9lf seconds\n", runtime);
}
//main function
/* Avoid details and call upon my minions to make it everything happen.  I own
 * those highest level things that I must own: performance timing and the
 * value we return to linux */
int main(int argc, char *argv[])
{
	int rval = EXIT_SUCCESS;
	double start;

	start = now();	// this is the very first executable statement
	
	if( init(argc))
	{
	    struct Sim ohio = {NULL, NULL, 0.0}, *world = &ohio;
		if(argc == 3) world->bonus = 1;	

	    if( good_input(world, argv)) run_sim(world);
	    else rval = RVAL_BAD_INPUT;

	    teardown();
	}
	else
	{
	    rval = RVAL_BAD_INIT;	// non zero, indicates an error
	}
	
	/* at this point we are done, graphics has been torn down*/
	print_end(start, rval);

	return rval;
}

