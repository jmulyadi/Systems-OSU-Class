

/* Copyright 2024, Neil Kirby.  Not for disclosure without permission */
//Josh Mulyadi
// put system shared libraries first - they are unlikely to have bugs.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "debug.h"

// includes for header files based on our own C code goes here.
// Always include the header for the file itself
// THis validates the header declarations against the defninitions.
// We are spoiled by our automatically generated headers, but we still
// validate them.  We put the include for this file dead last.
#include "bits.h"

#define BITMASK 0xF
#define COLORBITMASK 0x7
#define COLORSHIFT 12
#define JUMPSHIFT 8
#define XVELSHIFT 4

//Decodes input to get brutus's color
unsigned int get_color(unsigned short code)
{
	return ( code >> COLORSHIFT & COLORBITMASK);
}
//Decodes input to get brutus's jump velocity
unsigned int get_jump_V(unsigned short code)
{
	return ( (code >> JUMPSHIFT) & BITMASK);
}
//decodes input to get brutus's x velocity
unsigned int get_VX(unsigned short code)
{
	return ( (code >> XVELSHIFT) & BITMASK);
}

//checks to make sure the binary representation of the input has an even number of ones
static bool good_parity(unsigned short code)
{

	// add the checksum/parity code here
	unsigned short x = 0;
	// depend on it being unsigned so we shift in 0 on the left end
	if(DEBUG)printf("    validating parity...\n");

	while(code)
	{
	     x = x ^ (code & 1);
	     code = code >> 1;
	}

	if(DEBUG)printf("    all done: parity wanted 0 got %d\n",x);
	return x ==0;
}
//checks all memebers of brutus to make sure they are valid
bool valid_brutus(unsigned short code)
{
	if(DEBUG)printf("valid brutus:\n    validating color...\n");
	if(get_color(code) == 0) return false;

	if(DEBUG)printf("    validating jump V...\n");
	if(get_jump_V(code) == 0) return false;

	if(DEBUG)printf("    validating VX...\n");
	if(get_VX(code) == 0) return false;

	return good_parity(code);
}
//Josh Mulyadi below is my code
//gets x position of coin
unsigned int get_coin_x(unsigned short code)
{
	return ( (code >> JUMPSHIFT) & BITMASK);	
}

//gets y position of coin
unsigned int get_coin_y(unsigned short code)
{
	return ( (code >> XVELSHIFT) & BITMASK);
}
//checks if it's a mascot
bool isMascot(unsigned short code)
{
	return 1 == (code & 1);
}
//checks if it's a coin
bool isCoin(unsigned short code)
{
	return 0 == (code & 1);
}
//validates the coin
bool validateCoin(unsigned short code)
{
	if(DEBUG)printf("valid coin:\n    validating color...\n");
	if(get_color(code) == 0) return false;

	return good_parity(code);
}