

#include <stdio.h>
#include <stdlib.h>

int *m_shim(int value, int count, int array[] );

void run (int value, int count, int array[])
{
	int *ip;

	printf("\nlab5: looking for %d in %d ints\n", value, count);
	ip = m_shim(value, count, array);
	if(ip) printf("lab5: Found %d at %p\n", *ip, (void *)ip);
	else printf("lab5: Did not find %d\n", value);
}

