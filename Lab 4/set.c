/*
*   Spencer Goles   19 Febuary 2019   COEN 12
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

//Creates full set
// O(n)
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

//Destroys full set
// O(1)
void destroySet(SET *sp)
{
	assert(sp != NULL);
    	free(sp->lists);
    	free(sp);
}

//Returns number of elements
// O(1)
int numElements(SET *sp)
{
	assert(sp != NULL);
    	return sp->count;
}

//Adds elt to list
// O(n)
void addElement(SET *sp, void *elt)
{
	assert(sp != NULL && elt != NULL);
    	int index = (*sp->hash)(elt) % sp->length;
    	if(findItem(sp->lists[index],elt) == NULL)
    	{
        	addFirst(sp->lists[index] , elt);
        	sp->count++;
    	}
}

//Removes elt from list if it exists
// O(n)

void removeElement(SET *sp, void *elt)
{
	    assert(sp != NULL && elt != NULL);
    	int index = (*sp->hash)(elt)%sp->length;
    	if(findItem(sp->lists[index],elt) != NULL)
    	{
        	removeItem(sp->lists[index], elt);
        	sp->count--;
    	}
}


//Find elt if it exists and return pointer
// O(n)
void *findElement(SET *sp, void *elt)
{
	    assert(sp != NULL && elt != NULL);
    	int index = (*sp->hash)(elt) % sp->length;
    	return findItem(sp->lists[index], elt); 
}

//copy elts
//O(n)
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
