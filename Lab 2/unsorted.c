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

static int search(SET *sp, char *elt, bool *found);

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

char *findElement(SET *sp, char *elt)
{
    bool *found = NULL;
    int temp = search(sp, elt, found);
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
