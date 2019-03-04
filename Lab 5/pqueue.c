/*
*   Spencer Goles   COEN 12    27 Febuary 2019
*   Description: 
*
*/

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "pqueue.h"
# define START 10
# define p(x) (((x)-1)/2)
# define l(x) ((2(x))+1)
# define r(x) ((2(x))+2)

typedef struct pqueue 
{
    int count;
    int length;
    void **data;
    int (*compare) ();
}PQ;

PQ *createQueue(int (*compare)())
{
    PQ *pq;
    pq = malloc(sizeof(PQ));
    assert(pq != NULL);
    pq->count = 0;
    pq->length = START;
    pq->compare = compare;
    assert(compare != NULL);
    pq->data = malloc(sizeof(void*)*START);
    return pq;
}

void destroyQueue(PQ *pq)
{
    assert(pq != NULL);
    int i;
    for(i = 0; i < pq->count; i++)
        free(pq->data[i]);
    free(pq->data);
    free(pq);
}

int numEntries(PQ *pq)
{
    assert(pq != NULL);
    return pq->count;
}

void addEntry(PQ *pq, void *entry)
{
    assert(pq != NULL && entry != NULL);
    if(pq->length == pq->count)
    {
        pq->data = realloc(pq->data, sizeof(*void)*pq->length*2);
        pq->length *= 2;
    }
    pq->data[pq->count] = entry;
    int loc = pq->count; 
    while(pq->compare(pq->data[loc], pq->data[p(loc)]) < 0)
    {
        void *temp = pq->data[p(loc)];
        pq->data[p(loc)] = pq->data[loc]; 
        pq->data[loc] = temp; 
    }
    pq->count++;
}

void *removeEntry(PQ *pq)
{
    assert(pq != NULL);
    void *root = pq->data[0];
    int loc, small; 
    loc = 0;
    small = 0; 
    pq->data[loc] = pq->data[pq->count - 1];
    pq->count--;
    while(l(loc) < pq->count)
    {
        small = l(loc);
        if(r(loc) < pq->count)
        {
            if(pq->compare(pq->data[l(loc)] , pq->data[r(loc)]) < 0)
                small = l(loc); 
            else 
                small = r(loc); 
        }
        if(pq->compare())
    } 

}
