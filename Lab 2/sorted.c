/*
 *  Spencer Goles   22 January 2019    COEN 12
 *  File: sorted.c      Project: Lab 2
 *  Description: Program creates a sorted array with binary search functionality 
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

//Function creates set and allocates memory
//Big-O: O(n)
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

//Function destroys set
//Big-O: O(n)
void destroySet(SET *sp)
{
	int i;
	assert(sp != NULL);
    	for(i = 0; i < sp->count;i++)
        	free(sp-> data[i]);
    	free(sp->data);
    	free(sp);
	return;
}

//Function returns array count
//Big-O: O(1)
int numElements(SET *sp)
{	
	assert(sp != NULL);
	return (sp->count); 
}

//Function adds elt to sorted array
//Big-O(nlog n)
void addElement(SET *sp, char *elt)
{
    	assert(sp != NULL);
    	int i;
    	bool found = true;
    	int index = search(sp, elt, &found);

    	if(found == true) return; 

    	if(sp->count == sp->length)
    	{
        	printf("Array is currently full.\n");
        	return;
    	}
    
    	for(i = sp->count; i > index; i--)
    	{
        	sp->data[i] = sp->data[i - 1];
    	}
    	sp->data[index] = strdup(elt);
    	sp->count += 1;
    	return;
}

//Function removes elt from the sorted array and shifts elt
//Big-O: O(nlog n)
void removeElement(SET *sp, char *elt)
{
    	assert(sp != NULL);
    	bool found = false;
    	int i;
    	int index = search(sp, elt, &found);

    	if(found == true)
    	{
        	free(sp->data[index]);
        	for(i = index + 1; i < sp->count; i++)
        	{
             		sp->data[i - 1] = sp->data[i];
        	}
        	sp->count -= 1;
    	}
    	return; 
}

//Function finds elt and returns char *
//Big-O: O(log n)
char *findElement(SET *sp, char *elt)
{
	assert(sp != NULL);
    	bool found = true;
    	int temp = search(sp, elt, &found);
    	if(found == true)
        	return sp->data[temp];
    	return NULL;
}

//Function to copy all elt from set to char ** and return
//Big-O: O(n)
char **getElements(SET *sp)
{
	assert(sp != NULL);
    	int i;
    	char **copy = malloc(sizeof(char *)*sp->length);
    	for(i = 0; i < sp->count; i++)
        	strcpy(copy[i], sp->data[i]);
    	return copy;
}

//Binary search function to locate index of elt
//Big-O: O(log n)
static int search(SET *sp, char *elt, bool *found)
{
	assert(sp != NULL);
	int mid;
	int low = 0;
	int high = sp->count - 1;
	while(low <= high)
    	{
        	mid = ((high + low) / 2);
        
        	if(strcmp(sp->data[mid], elt) < 0)
            		high = mid - 1;
        	if(strcmp(sp->data[mid], elt) > 0)
            		low = mid + 1;
        	if(strcmp(elt, sp->data[mid]) == 0)
		{
            		*found = true;
            		return mid;
		}
    	}
    	*found = false; 
    	return low; 
}
