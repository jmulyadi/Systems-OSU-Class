

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

int main()
{
	static int a1[] = { -400, -200, -300, -100};
	static int a2[] = { 1024, 2048, 64, 16, 32};
	int a3[] = { 0, -1, 1};


	run(-300, 4, a1);
	run(0, 5, a2);
	run(0, 3, a3);

	printf("\n");

}
