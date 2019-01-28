/*
 *  Spencer Goles   14 January 2019    COEN 12
 *  File: unsorted.c      Project: Lab 2
 *  Description: Creates an unsorted list and provides certain functionality such as add or delete
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "set.h"
# include <stdbool.h>
# include <assert.h>

static int search(SET *sp, char *elt, bool *found);

typedef struct set
{
	int length; 
	int count;
    	char ** data;
} SET;

//Function allocates set sand initializes
//Big-O: O(1)
SET *createSet(int maxElts)
{
	SET *sp;
    	sp = malloc(sizeof(SET));
    	assert(sp != NULL);
    	sp -> count = 0;
    	sp -> length = maxElts;
    	sp -> data = malloc(sizeof(char *)*maxElts);
    	assert(sp->data != NULL);
    	return sp;
}

//Function deltes the entire array
//Big-O: O(n)
void destroySet(SET *sp)
{
	int i;
    	assert(sp != NULL);
    	for(i = 0; i < sp->count;i++)
        	free(sp-> data[i]);
    	free(sp->data);
    	free(sp);
}

//Function returns the num of elt in array
//Big-O: O(1)
int numElements(SET *sp)
{
	return (sp->count); 
}

//Function checks for repeate then adds elt to array end
//Big-O: O(n)
void addElement(SET *sp, char *elt)
{
	bool *found = NULL;
    	if(search(sp, elt, found) == -1)
    	{
        	if(sp->count == sp->length)
        	{
            		printf("Array is currently full.");
            		return;
        	}
        	sp ->data[sp->count] = strdup(elt);
        	sp->count += 1;
    	}
    	return;
}

//Function removes elt from array and replaces with last elt 
//Big-O: O(n)
void removeElement(SET *sp, char *elt)
{
	assert(sp != NULL);
    	assert(elt != NULL);
    	bool found = NULL;
    	int index = search(sp, elt, &found);
    	if(index == -1)
        	return; 
    	sp->data[index] = sp->data[sp->count-1];
    	sp->data[sp->count-1] = NULL;
    	sp->count -= 1;
    	return; 
}

//Function returns the pointer to the word in the char **
//Big-O: O(n)
char *findElement(SET *sp, char *elt)
{
	bool *found = NULL;
    	int temp = search(sp, elt, found);
    	if(temp != -1)
        	return sp->data[temp];
    	return NULL;
}

//Function creates a char** copy of the data and returns copy
//Big-O: O(n)
char **getElements(SET *sp)
{
	int i;
    	char **copy = malloc(sizeof(sp->data));
    	for(i = 0; i < sp->count; i++)
        	copy[i] = sp->data[i];
    	return copy;
}

//Function searches through the char ** and returns index of elt and bool
//Big-O: O(n)
static int search(SET *sp, char *elt, bool *found)
{
	int i;
    	found = false;
    	for(i = 0; i < sp->count; i++)
    	{
        	if(strcmp(elt, sp->data[i]) == 0)
            	return i;
    	}
    	return -1;
}
