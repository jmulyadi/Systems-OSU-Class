//Josh Mulyadi
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bits.h"
#define SHIFT 4

// int test(unsigned short binaryNum) {

//     // Print the binary representation
//     printf("Binary: ");
//     for (int i = 15; i >= 0; i--) {
//         int bit = (binaryNum >> i) & 1;
//         printf("%d", bit);
//     }

//     printf("\n");

//     return 0;
// }
int readInput(double brutus[])
{
    bool res = true;
    int tokens = 0;
    unsigned short hexNum;
    printf("This is what the input file holds : \n");
    while(1 == (tokens = scanf("%hx", &hexNum)))
    {
       printf("%hx\n", hexNum);
    }
    printf("scanf returned %d", tokens);
    return res;
}
int main() {
    double brutus[] = {.5, .5, 14, 0, 15};

    readInput(brutus);
    
    return 0;
}
