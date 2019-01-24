/*
 *  Spencer Goles   22 January 2019    COEN 12
 *  File: sorted.c      Project: Lab 2
 *  Description: 
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "set.h"
# include <stdbool.h>

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
    sp = (SET*)mallocc(sizeof(SET));
    assert(sp != NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = (char**)malloc(sizeof(char *)*maxElts);
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
    assert(sp != NULL);
    return (sp->count); 
}

void addElement(SET *sp, char *elt)
{
    //FINISH
    return;
}
void removeElement(SET *sp, char *elt)
{
    int i;
    bool *found; 
    assert(sp != NULL);
    assert(elt != NULL);
    int temp = search(sp, elt, found);
    if(temp != -1)
    {
        for(i = temp; i < sp->count; i++)
            sp->data[i] = sp->data[i-1];
        free(temp);
        sp->count =- 1;
        return;
    }
    return; 
}

char *findElement(SET *sp, char *elt)
{
    bool *found;
    char *temp = search(sp, elt, found);
    if(temp != -1)
        return sp->count[temp];
    return NULL;
}

char **getElements(SET *sp)
{
    int i;
    char **copy;
    copy = (char **)mallocc(sizeof(sp->data));
    for(i = 0; i < sp->count; i++)
        copy[i] = sp->data[i];
    return copy;
}

static int search(SET *sp, char *elt, bool *found)
{
    //FINISH
    return -1;
}