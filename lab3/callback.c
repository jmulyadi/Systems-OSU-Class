//Josh Mulyadi
#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "physics.h"
#include "debug.h"
#include "lab3.h"
#include "memory.h"
#include "libll.h"
#include "output.h"
#include "callback.h"
//helps insert coins
bool coinInsert(void *data1, void *data2)
{
    struct Coin *d1 = data1;
    struct Coin *d2 = data2;

    return d1->color >= d2->color;
}
//for deleting all items in list
bool all(void *data, void *helper)
{
    return true;
}
//helps insert mascots
bool mascotInsert(void *data1, void *data2)
{
    struct Buckeye *d1 = data1;
    struct Buckeye *d2 = data2;

    return d1->y_position > d2->y_position;
}
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
//checks if brutus is left of flag
bool all_left_of_flag(void *data, void *helper)
{
    struct Buckeye *currBrutus = data;
    return is_left_of_flag(currBrutus);
}
//changes all brutus's to be after the flag
void all_done(void *data)
{
    struct Buckeye *brutus = data;
    brutus->x_position = 15;
}
//sorts mascots by y position
bool sort_mascots_y(void *data1, void *data2)
{
    struct Buckeye *d1 = data1;
    struct Buckeye *d2 = data2; 
    return d1->y_position > d2->y_position;
}
//move brutus if he's left of the flag
void move(void *data)
{
    struct Buckeye *brutus = data;
    if(!is_left_of_flag(brutus)) return;
    move_brutus(brutus);
}
//sort by points
bool sort_points(void *data1, void *data2)
{
    struct Buckeye *d1 = data1;
    struct Buckeye *d2 = data2; 
    return get_score(d1) >= get_score(d2);
}
//checks if coin and brutus match
bool my_coin(void *data, void *helper)
{
    struct Coin *coin = data;
    struct Buckeye *brutus = helper; 
    return coin->color == brutus->color && close_enough(coin, brutus);
}
//collect the coins
void sweep_coins(void *data)
{
    struct Buckeye *brutus = data;
    int coins_deleted = deleteSome(&((brutus->sim)->coins), my_coin, brutus, freeMem, TEXT);
    if(coins_deleted) loot_message(brutus);
    brutus->loot += coins_deleted;
}