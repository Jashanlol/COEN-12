/*
*   Spencer Goles   11 Febuary 2019   COEN 12
*   Description:  
*
*/



# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "list.h"

struct list{
    int count;   
    struct node *head;
    int (*compare)();
};
typedef struct node{
     void *data;     
     struct node *next;   
     struct node *prev;
} NODE;

LIST *createList(int (*compare) ())
{

    LIST *lp = malloc(sizeof(LIST));
    assert(lp != NULL);
    lp->count = 0;
    lp->compare = compare;
    lp->head = malloc(sizeof(NODE));
    assert(lp->head != NULL);
    lp->head->next = lp->head;    
    lp->head->prev = lp->head;    
    return lp;
}

void destroyList(LIST *lp)
{
    assert(lp != NULL);
    NODE *pDel, *pNext;
    pDel = lp->head;
    do
    {
        pNext = pDel->next;
        free(pDel);
        pDel = pNext;
    } while (pDel != lp->head);
    free(lp);
}


int numItems(LIST *lp)
{
    assert(lp != NULL);
    return (lp->count);
}

void addFirst(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *temp = malloc(sizeof(NODE));
    temp->data = item;
    temp->prev = lp->head;
    temp->next = lp->head->next;
    lp->head->next = temp;
    temp->next->prev = temp;
    lp->count++;
}

void addLast(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *temp = malloc(sizeof(NODE));
    temp->data = item; 
    temp->next = lp->head;
    temp->prev = lp->head->prev;
    lp->head->prev = temp;
    temp->prev->next = temp;
    lp->count++;
}

void *removeFirst(LIST *lp)
{
    assert(lp != NULL); 
    NODE *pDel = lp->head->next;
    void *first = pDel->data;
    lp->head->next = pDel->next;
    pDel->next->prev = lp->head;
    free(pDel);
    lp->count--;
    return first; 
}

void *removeLast(LIST *lp)
{
    assert(lp != NULL); 
    NODE *pDel = lp->head->prev;
    void *last = pDel->data;
    pDel->prev->next = lp->head;
    lp->head->prev = pDel->prev;
    free(pDel);
    lp->count--;
    return last; 
}

void *getFirst(LIST *lp)
{
    assert(lp != NULL); 
    return(lp->head->next->data);
}

void *getLast(LIST *lp)
{
    assert(lp != NULL); 
    return(lp->head->prev->data);
}

void removeItem(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *check = lp->head;
    int i;
    for(i = 0; i < lp->count; i++)
    {
        if(lp->compare(item, check->data) == 0)
        {
            check->next->prev = check->prev;
            check->prev->next = check->next;
            free(check);
        }
        check = check->next;
    }
    lp->count--;
}

void *findItem(LIST *lp, void *item)
{
    assert(lp != NULL && item != NULL);
    NODE *p = lp->head;
    int i;
    for(i = 0; i < lp->count; i++)
    {
        if(lp->compare(item, p->data) == 0)
        {
            return (p->data);
        }
    }
    return NULL; 
}

void *getItems(LIST *lp)
{
    void **copy = malloc(sizeof(void *)*lp->count);
    NODE *p = lp->head->next;
    int i;
    for(i = 0; i < lp->count; i++)
    {
        copy[i] = p->data;
        p = p->next;
    }
    return copy; 
}