//Josh Mulyadi
#include <stdio.h>
#include "structs.h"
#include <stdlib.h>

int main()
{
    struct Buckeye *brutus = (struct Buckeye *)malloc(sizeof(struct Buckeye));
	if(brutus == NULL)
	{
		printf("malloc failed for brutus");
		return 1;
	}
	brutus->x_position = 0.5;
    brutus->y_position = 0.5;
    brutus->y_velocity = 0.0;
    brutus->x_velocity = 5.0;
	brutus->x_velocity =69;
	brutus->jump_velocity = 420;
    printf("X = %f, Y = %f\n", brutus -> x_position, brutus-> y_position);
	printf("Y Velocity = %f, X Velocity = %f, and Jump Velocity = %f\n", brutus->y_velocity, brutus->x_velocity, brutus->jump_velocity);

    return 0;
}