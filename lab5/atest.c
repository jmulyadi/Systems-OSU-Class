
#include <stdio.h>
#include <stdlib.h>

int *a_shim(int value, int count, int array[], int *min_ptr, int *max_ptr);

void run (int value, int count, int array[], int *min_ptr, int *max_ptr)
{
	int *ip;

	printf("\nRun: looking for %d in %d ints\n", value, count);
	ip = a_shim(value, count, array, min_ptr, max_ptr);
	if(ip) printf("Found %d at %p\n", *ip, (void *)ip);
	else printf("Did not find %d\n", value);
	printf("Min is %d, max is %d\n", *min_ptr, *max_ptr);
}

int main()
{
	int min, max;
	static int a1[] = { -400, -200, -300, -100};
	static int a2[] = { 1024, 2048, 64, 16, 32};
	int a3[] = {0, -1, 1};

	run(-300, 4, a1, &min, &max);
	run(0, 5, a2, &min, &max);
	run(0, 3, a3, &min, &max);

	printf("\n");

}
