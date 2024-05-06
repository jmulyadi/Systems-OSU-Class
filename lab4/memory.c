//Josh Mulyadi
// COpyright 2024 Neil Kirby
// Not for distribution without permission

// list < > style headers first
#include <stdio.h>
#include <stdlib.h>

// includ3 constants and structs next
#include "debug.h"
#include "altmem.h"

// include our own file last
#include "memory.h"
//allocates memory
void *allocate_struct(int size)
{
	static int objects = 0;
	void *ptr;

	if( ptr = alternative_malloc(size))
	{
	    objects++;
		if(DEBUG) printf("DEBUG: memory: allocated pointer is %p\n", ptr);
	    if(TEXT)
	    {
    		printf("DIAGNOSTIC: allocation #%d allocated %d bytes\n", objects, size);
	    }

	}
	else
	{
	    if(TEXT)printf("ERROR: memory: failed to allocated %d bytes.\n", size);
	}
	return ptr;

}
//free memory
void free_struct(void *thing)
{
	static int count = 0;
	if(DEBUG) printf("DEBUG: memory: about to free %p\n", thing);
	alternative_free(thing);
	count++;
	if(TEXT)printf("DIAGNOSTIC: %d objects freed\n", count);
}
