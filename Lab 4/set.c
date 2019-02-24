/*
*   Spencer Goles   19 Febuary 2019   COEN 12
*   Description:  
*
*/

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "set.h"
# include "list.h" 
# define  AVG 20


typedef struct node
{
    void *data;
    struct node *next;
    struct node *prev; 
} NODE;
typedef struct list
{
    int count; 
    struct node *head; 
    int (*compare) ();
} LIST;
typedef struct set 
{
    int length;
    int count;
    int (*compare)();
    unsigned (*hash)();
    LIST **lists; 
} SET;

SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)())
{    
    int i;    
    SET *sp;    
    assert(compare != NULL && hash != NULL);    
    sp = malloc(sizeof(SET));    
    assert(sp != NULL); 
    sp->compare = compare;    
    sp->hash = hash;    
    sp->count = 0;   
    sp->length =  maxElts / AVG; 
    sp->lists = malloc(sizeof(LIST*)*sp->length);
    for(i = 0; i < sp->length; i++)
        sp->lists[i] = createList(compare);
    return sp;
}

void destroySet(SET *sp)
{
    assert(sp != NULL);
    int i;
    for(i = 0; i < sp->length; i++)
        free(sp->lists[i]);
    free(sp->lists);
    free(sp);
}

int numElements(SET *sp)
{
    assert(sp != NULL);
    return sp->count;
}

void addElement(SET *sp, void *elt)
{
    assert(sp != NULL && elt != elt);
    int index = (*sp->hash)(elt) % sp->length;
    if(findItem(sp->lists[index],elt) == NULL)
    {
        addFirst(sp->lists[index] , elt);
        sp->count++;
    }
    return;
}

void removeElement(SET *sp, void *elt)
{
    assert(sp != NULL && elt != elt);
    int index = (*sp->hash)(elt) % sp->length;
    if(findItem(sp->lists[index],elt) == NULL)
    {
        removeItem(sp->lists[index], elt);
        sp->count--;
    }
    return; 
}

void *findElement(SET *sp, void *elt)
{
    assert(sp != NULL && elt != elt);
    int index = (*sp->hash)(elt) % sp->length;
    return findItem(sp->lists[index], elt); 
}

void *getElements(SET *sp)
{
    assert(sp != NULL);
    NODE *np;
    void **copy = malloc(sizeof(void*)*sp->count);
    int i, j;
    j = 0; 
    for(i = 0; i < sp->length; i++)
    {
        int num = numItems(sp->lists[i]);
        if(num != 0)
        {
            np = sp->lists[i]->head->next;
            while(np != sp->lists[i]->head)
            {
                copy[j] = np->data;
                num++;
                j++;
                np = np->next;
            }
        }
    }
    return copy; 
}
