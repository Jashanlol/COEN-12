/*
 *  Spencer Goles   22 January 2019    COEN 12
 *  File: sorted.c      Project: Lab 2
 *  Description: 
 */

/*
 *  Spencer Goles   14 January 2019    COEN 12
 *  File: unsorted.c      Project: Lab 2
 *  Description: 
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "set.h"
# include <stdbool.h>
# include <assert.h>

static int bsearch(SET *sp, char *elt, bool *found);

typedef struct set
{
    int length; 
    int count;
    char ** data;
} SET;

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

void destroySet(SET *sp)
{
    int i;
    assert(sp != NULL);
    for(i = 0; i < sp->count;i++)
        free(sp-> data[i]);
    free(sp->data);
    free(sp);
}

int numElements(SET *sp)
{
    return (sp->count); 
}
//***********************************************FINISH AND TEST EVERYTHING
void addElement(SET *sp, char *elt)
{
    bool *found = NULL;
    int index = bsearch(sp, elt, &found);

    if(bsearch(sp, elt, found) == -1)
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

void removeElement(SET *sp, char *elt)
{
    assert(sp != NULL);
    assert(elt != NULL);
    bool found = NULL;
    int i;
    int index = bsearch(sp, elt, &found);
    if(index == -1)
        return; 
    for(i = index; i < sp->count - 1; i++)
    {
        sp->data[i] = sp->data[i + 1];
    }
    sp->data[sp->count] = NULL;
    sp->count -= 1;
    return; 
}

char *findElement(SET *sp, char *elt)
{
    bool *found = NULL;
    int temp = bsearch(sp, elt, found);
    if(temp != -1)
        return sp->data[temp];
    return NULL;
}

char **getElements(SET *sp)
{
    int i;
    char **copy = malloc(sizeof(sp->data));
    for(i = 0; i < sp->count; i++)
        copy[i] = sp->data[i];
    return copy;
}

static int bsearch(SET *sp, char *elt, bool *found)
{
    int mid;
    int low = 0;
    int high = sp->count;
    found = false;
    while(low <= high)
    {
        mid = low + ((high - low) / 2);
        
        if(strcmp(elt, sp->data[mid]) < 0)
            high = mid - 1;
        if(strcmp(elt, sp->data[mid]) > 0)
            low = mid + 1;
        if(strcmp(elt, sp->data[mid]) == 0)
            return mid;
    }
    return -1;
}

