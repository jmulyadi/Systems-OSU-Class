

// SP24 Lab6 header file

#include <stdio.h>
#include <stdlib.h>

#include "ops.h"

struct Operation {
	int result;
	char printable;
	short operation;
	int a,b;
	};

typedef int (*mathOp)(int a, int b);

mathOp table[] = { plus, left_shift, times, divide};

struct Operation ops_table[] = {
	{0, '+', 0, 4, 16},
	{0, '<', 1, 16, 4},
	{0, '*', 2, 16, 4},
	{0, '/', 3, 16, 4}
			};

//int do_op( struct Operation *op, mathOp table[]);
int d_shim( struct Operation *op, mathOp table[]);

// struct Operation *search(long count, struct Operation ops[], mathOp table[]);
struct Operation *s_shim(long count, struct Operation ops[], mathOp table[]);

int main()
{
	struct Operation *biggest;

	printf("BONUS is searching...\n\n");
	biggest = s_shim(4, ops_table, table);
	printf("The largest result comes from: %d %c %d = %d\n", 
		biggest->a, biggest->printable, biggest->b, biggest->result);

	return EXIT_SUCCESS;
}
