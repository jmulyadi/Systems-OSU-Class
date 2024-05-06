//Josh Mulyadi
// COpyright 2024 Neil Kirby
// Not for distribution without permission
//

#include <stdbool.h>
#include <stdio.h>

#include "structs.h"

#include "sim.h"

// General home for list callback functions.  Two halves; coin related and
// brutus related.
//always returns true
bool always_true(void *data, void *helper)
{
	// I don't care about parameters,
	return true;

}

//**************** brutus *************
//sorts brutus by score
bool brutus_score_order(void *data1, void * data2)
{
	struct Buckeye *b1 = data1, *b2 = data2;

	return( get_score(b1) > get_score(b2));
}


//sorts brutus by y position
bool brutus_Y_order(void *data1, void * data2)
{
	struct Buckeye *b1 = data1, *b2 = data2;

	return( b1->y_position > b2->y_position);
}



// ************** coin related ********
//sorts coins by color
bool coin_color_order( void *data1, void * data2)
{
	struct Coin *c1 = data1, *c2 = data2;
	return (c1->color > c2->color);

}
//Josh Mulyadi code below
//prints all coins
void print_coins(void *data)
{
    struct Coin *c = data;
    printf("The color is: %d\n", c->color);
}
//prints all mascots
void print_mascots(void *data)
{
    struct Buckeye *b = data;
    printf("The y position is: %f\n", b->y_position);
    printf("The x position is: %f\n", b->x_position);
}