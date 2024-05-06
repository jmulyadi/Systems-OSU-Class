
#include <math.h>
#include <stdio.h>
#include "n2.h"

#define ITERATIONS 100

int main(int argc, char *argv[])
{
	double opp, adj, h2, hyp, dist, d2;
	double start, end;
	int i;
	double h2_array[ITERATIONS], d2_array[ITERATIONS]; 

	/* the hypoteneuse is always bigger than the longest side but 
	 * shorter than the sum of the two sides.  So with 3.0 and 4.0, it
	 * has to be bigger than 4.0 but smaller than 7.0.  
	 * What we really want to know is if it is bigger than 6.0
	 */

	printf("Input 3.0 4.0 6.0 please: ");
	scanf("%lf %lf %lf", &opp, &adj, &dist);

	start = now();
	for(i=0; i<ITERATIONS; i++)
	{
	    /* we normally do the square root of the sum of the squares */
	    /* do the sum of the squares */
	    h2 = opp * opp + adj * adj;
	    /* compare  to the dsit squared */
	    /* this is the only line that is different */
	    d2 = dist * dist;
	    /* stuff so that the optimizer doesn't throw it all
	     * away. */
	    h2_array[i] = h2;
	    d2_array[i] = d2;
	    opp += 1.0;
	    adj += 1.0;
	    dist += 1.0;
	}

	/* stop timing */
	end = now();

	/* keep printf out of the time computation */

	/* the print loop keeps the optimizier from discarding the arrays
	 */
	for(i=0; i < ITERATIONS; i++)
	{
	printf("%lf %lf\n", h2_array[i], d2_array[i]);
	}

    printf("py3 took %.9lf micro seconds.\n", (end - start) * 1000000.0 );

	return 0;
}
