//Josh Mulyadi
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structs.h"
#include "libll.h"
#include "debug.h"

bool first_letter(void *data1, void *data2)
{
    char *letter1 = data1;
    char *letter2 = data2;
    return (*letter1)-(*letter2) < 0;
}
bool deleteAll(void *data, void *helper)
{
    return true;
}
void disposal(void *data)
{
    return;
}
void print(void *data)
{
    char *c = data;
    printf("%s\n", c);
}
int main()
{
    void *list = NULL;
    bool (*fp)(void *, void *);
    fp = first_letter;
    //alwasy pass text in to last parameter
    bool rval = insert(&list, "Go Bucks!",fp, TEXT);
    printf("%d\n", rval);
    insert(&list, "Martin Sucks", first_letter, TEXT);
    insert(&list, "A", first_letter, TEXT);
    insert(&list, "Josh is better at Catan", first_letter, TEXT);
    iterate(list, print);
    int delVal = deleteSome(&list, deleteAll, NULL, disposal, TEXT);
    return 0;   
}