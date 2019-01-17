/*
 *  Spencer Goles   Jan 14, 2019    COEN 12
 *  File: unsorted.c      Project: Lab 2
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
    sp = mallocc(sizeof(SET));
    assert(sp != NULL);
    sp -> count = 0;
    sp -> length = maxElts;
    sp -> data = malloc(sizeof(char *)*maxElts);
    assert(sp->data != NULL);
    return sp;
}


void destroySet(SET *sp)
{
    assert(sp != NULL);
    for(int i = 0; i < sp->count;i++)
    {
        free(sp-> data[i]);
    }
    free(sp->data);
    free(sp);
}

int numElements(SET *sp)
{
    assert(sp != NULL);
    return (sp->count); 
}
//********NO DUPLICATES IN THE PROGRAM LIST
void addElement(SET *sp, char *elt)
{
    if(sp->count == sp->length)
    {
        printf("Array is currently full.");
        return;
    }
    sp ->data[sp->count] = strup(elt);
    sp->count += 1;
}

void removeElement(SET *sp, char *elt)
{
    assert(sp != NULL)
    char *temp = findElement(sp, elt);
    if(temp != NULL)
    {

        free(temp);
        sp->count =- 1;
        return;
    }
    return; 
}

char *findElement(SET *sp, char *elt)
{
    bool found;
    char *temp = search(sp, elt, found);
    if(temp != -1)
        return sp->count[temp];
    return NULL;
}

char **getElements(SET *sp)
{

    return 'c';
}

static int search(SET *sp, char *elt, bool *found)
{
    found = false;
    for(int i = 0; i < sp->count; i++)
    {
        if(strcmp(elt, sp->data[i]) == 0)
        {
            found = true;
            return i;
        }
    }
    return -1;
}






