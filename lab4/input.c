//Josh Mulyadi
/* Copyright 2023, Neil Kirby.  Not for disclosure without permission */

// put system shared libraries first - they are unlikely to have bugs.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// put our own header files next.
// Start with one that are #define and structs
#include "structs.h"
#include "debug.h"

// includes for header files based on our own C code goes here.
// Always include the header for the file itself
// THis validates the header declarations against the defninitions.
// We are spoiled by our automatically generated headers, but we still
// validate them.  We put the include for this file dead last.
#include "output.h"
#include "bits.h"
#include "physics.h"
#include "sim.h"	// TODO: remove this later

#include "input.h"

#define ERR (-1)
//checks for valid input
bool valid_input(unsigned short code)
{
	if(is_coin(code))return valid_coin(code);
	if(is_brutus(code))return valid_brutus(code);
    if(TEXT)printf("ERROR: Don't know what %hx is, can't validate\n", code);
	return false;
}
//opens file
FILE *fileOpen(char* fileName)
{
	FILE *file_pointer = fopen(fileName, "r");
	if (file_pointer == NULL) {
        if(TEXT) printf("ERROR: Unable to open %s for reading.\n", fileName);
    }	
	else
	{
		if(TEXT) printf("DIAGNOSTIC: Successfully opened %s for reading.\n", fileName);
	}
	return file_pointer;
}
//close file
void closeFile(FILE *file_pointer)
{
	if(TEXT) printf("DIAGNOSTIC: Input file closed.\n");
	fclose(file_pointer);
}
//wraps up all ending stuff
void cleanUp(FILE *file_pointer, int tokens)
{
	output_scanf(tokens);
	closeFile(file_pointer);
}
//reads good input
bool good_input(struct Sim *world, char *argv[])
{
	int tokens;
	unsigned short code;

	FILE *file_pointer = fileOpen(argv[1]);
	if(file_pointer == NULL) return false;
	while( 1 ==(tokens = fscanf(file_pointer, "%hx", &code )))
	{
	    if(valid_input(code)) 
	    {
	    	deal_with_input(code, world);
	    }
	    else
	    {
	    	output_bad_bits(code);
			return false;
	    }
	}
	cleanUp(file_pointer, tokens);
	return( tokens == EOF);
}


