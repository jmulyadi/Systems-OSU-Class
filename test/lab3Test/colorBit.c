//Josh Mulyadi
#include <stdio.h>
#include <stdbool.h>

#include "debug.h"
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
//Josh Mulyadi below is my code
//gets x position of coin
unsigned int get_coin_x(unsigned short code)
{
	return ((code >> JUMPSHIFT) & BITMASK);	
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
int main()
{
	unsigned short code;
	int tokens;
	while(1 == (tokens = scanf("%hx", &code))){
		printf("Input is: %hx\n", code);
		if(isMascot(code)) 
		{
			printf("Input is a Mascot\n");
		}
		else
		{
			printf("Input is a coin\n");
			if(validateCoin(code)) printf("Coin is Valid\n");
			else printf("Coin is Invalid\n");
			printf("Color is: %d\n", get_color(code));
			printf("X position is: %d\n", get_coin_x(code));
			printf("Y position is: %d\n", get_coin_y(code));
		} 
	}	
	printf("scanf returns %d\n", tokens);
	return 0;
}