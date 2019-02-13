/*
*   Spencer Goles   11 Febuary 2019   COEN 12
*   Description:  
*
*/



# include <time.h>		/* for time(), used to seed the rng */
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <curses.h>
# include <unistd.h>		/* for usleep() */
# include <stdbool.h>
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

extern LIST *createlist(int (*compare) ())
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

extern void destroyLIST(LIST *lp)
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


extern int numItems(LIST *lp)
{
    assert(lp != NULL);
    return (lp->count);
}

extern void addFirst(LIST *lp, void *item)
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

extern void addLast(LIST *lp, void *item)
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

extern void *removeFirst(LIST *lp)
{
    assert(lp != NULL); 
    NODE *pDel = lp->head;
    
}

extern void *removeLast(LIST *lp)
{

}

extern void *getFirst(LIST *lp)
{
    assert(lp != NULL); 
    return(lp->head->next->data);
}

extern void *getLast(LIST *lp)
{
    assert(lp != NULL); 
    return(lp->head->prev->data);
}

extern void removeItem(LIST *lp, void *item);

extern void *findItem(LIST *lp, void *item);

extern void *getItems(LIST *lp);