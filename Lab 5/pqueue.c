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
    
}

void *removeEntry(PQ *pq);
