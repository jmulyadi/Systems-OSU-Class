//Josh Mulyadi
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "structs.h"
#include "libll.h"
#include "debug.h"


bool first_letter(void *data1, void *data2)
{
    char *letter1 = data1;
    char *letter2 = data2;
    return (*letter1)-(*letter2) < 0;
}
bool deleteUpperCase(void *data, void *helper)
{
    char *letter = data;
    return isupper(*letter);
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
    //alway pass text in to last parameter
    bool rval = insert(&list, "Go Bucks!",fp, TEXT);
    printf("The return value of insert is %d\n", rval);
    insert(&list, "martin Sucks", first_letter, TEXT);
    insert(&list, "a", first_letter, TEXT);
    insert(&list, "Josh is better at Catan", first_letter, TEXT);
    printf("Before Delete:\n");
    iterate(list, print);
    int delVal = deleteSome(&list, deleteUpperCase, NULL, disposal, TEXT);
    printf("The Deleted Value is or amount deleted is: %d\n", delVal);
    printf("After Delete:\n");
    iterate(list, print);
    deleteSome(&list, deleteAll, NULL, disposal, TEXT); 
    return 0;   
}