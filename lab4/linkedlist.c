//Josh Mulyadi
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structs.h"
#include "memory.h"
#include "debug.h"
#include "ctype.h"
#include "output.h"
#include "altmem.h"

#include "linkedlist.h"
//frees data in node
void freeData(void *data)
{
    free_struct(data);
}
//frees the node
void freeNode(void *data)
{
    alternative_free(data);
    node_free_out();
}
//allocates space for nodes
void* allocate_node()
{
    void *ptr;
    if(!(ptr = alternative_malloc(sizeof(Node))))
	{
        if(TEXT) printf("ERROR: linkedlist: Failed to malloc a Node\n");
	}
	return ptr;
}
//iterates through the list
void iterate(void *head, ActionFunction doThis)
{
    Node *node = head;
    while(node != NULL)
    {
        doThis(node->data);
        node = node->next;
    }
}
//return true if any of the things in the list fit the criteria
int any(void *head, CriteriaFunction yes, void *helper)
{
    Node *node = head;
    while(node != NULL)
    {
        if(yes(node->data, helper)) return true;
        node = node->next;
    }
    return false;
}
//inserts into list
bool insert(void *p2head, void *data, ComparisonFunction goesInFrontOf, int text)
{
    Node *newNode = allocate_node();
    if(!newNode) return false;
    newNode->data = data;
    Node **p2p2change = p2head;
    if(DEBUG) printf("DEBUG: linkedlist: inserting (lives at %p)\n", (void*)newNode);
    while(*p2p2change != NULL && !goesInFrontOf(newNode->data, (**p2p2change).data))
    {
        p2p2change = &((**p2p2change).next);
    }
    newNode->next = *p2p2change;
    *p2p2change = newNode;
    node_allocate_out();
    return true;
}       
//deletes from list
int deleteSome(void *p2head, CriteriaFunction mustGo, void *helper,	ActionFunction disposal, int text)
{
    int cnt = 0;
    Node **p2p2change = p2head;
    while(*p2p2change != NULL)
    {
        if(mustGo((**p2p2change).data, helper))
        {
            Node *temp = *p2p2change;
            *p2p2change = (*p2p2change)->next;
            //frees data in node then the node itself
            disposal(temp->data);
            freeNode(temp);
            cnt++;
        }
        else p2p2change = &((**p2p2change).next);
    }
    return cnt;
}
//sorts 
void sort(void *hptr, ComparisonFunction cf)
{
    int swaps;
    Node *stop = NULL;
    do
    {
        swaps = 0;
        Node *p = hptr;
        while(p->next != stop) 
        {
            if(cf((p->next)->data, p->data))
            {
                void *temp = p->data;
                p->data = (p->next)->data;
                (p->next)->data = temp;
                swaps++;
            }
            p = p->next;
        }
        stop = p;
    }while(swaps);
}