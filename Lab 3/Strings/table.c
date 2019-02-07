/*
*   Spencer Goles   COEN 12     30 January 2019
*   Description: 
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "set.h"
# include <stdbool.h>
# include <assert.h>

#define EMPTY 1
#define FILLED 2
#define DELETED 3

unsigned strhash(char *s);
static int search(SET *sp, char *elt, bool *found);

typedef struct set
{
    int count;
    int length;
    char ** data;
    int *flags;
} SET;


SET *createSet(int maxElts)
{
    int i;
    SET *sp;
    sp = (SET*)malloc(sizeof(SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->data = (char **)malloc(sizeof(char*)*maxElts);
    assert(sp->data != NULL);
    sp->flags = malloc(sizeof(int*)*maxElts);
    assert(sp->flags != NULL);
    for(i = 0; i < sp->length; i++)
    {
        sp->flags[i] = EMPTY;
    }
    return sp;
}

void destroySet(SET *sp)
{
    assert(sp != NULL);
    int i;
    for(i = 0; i < sp->count; i++)
    {
        if(sp->flags[i] == FILLED)
            free(sp->data[i]);
    }
    free(sp->data);
    free(sp->flags);
    free(sp);
    return;
}

int numElements(SET *sp)
{
    assert(sp != NULL);
    return (sp->count);
}

void addElement(SET *sp, char *elt)
{
    assert(sp != NULL && elt != NULL);
    if (sp->count == sp->length) return;
    bool found = false;
    int index = search(sp, elt, &found);

    if(found == true || index == -1) return;

    sp->data[index] = strdup(elt);
    sp->flags[index] = FILLED;
    sp->count++;
    return;
}

void removeElement(SET *sp, char *elt)
{
    assert(sp != NULL && elt != NULL);
    bool found = false;
    int index = search(sp, elt, &found);
    if (found == true)
    {
        free(sp->data[index]);
        sp->flags[index] = DELETED;
        sp->count--;
    }
    return;
}

char *findElement(SET *sp, char *elt)
{
    assert(sp != NULL && elt != NULL);
    bool found = false;
    int index = search(sp, elt, &found);
    if(found == true)
        return (sp->data[index]);
    return NULL;

}

char **getElements(SET *sp)
{
    assert(sp != NULL);
    char ** copy = malloc(sizeof(char *)* sp->count);
    assert(copy != NULL);
    int i, j;
    j = 0;
    for(i = 0; i < sp->length; i++)
    {
        if(sp->flags[i] == FILLED)
        {
            memcpy(copy[j],sp->data[i], sizeof(char*)*sp->count);
            j++;
        }
    }
    return copy; 
}

unsigned strhash(char *s)
{
    unsigned hash = 0;
    while(*s != '\0')
        hash = 31 * hash + *s ++;
    return hash;
}

static int search(SET *sp, char *elt, bool *found)
{
    assert(sp != NULL);
    assert(elt != NULL);
    int i, pos;
    int rem;
    int first = 0;
    *found = false;
    unsigned key = strhash(elt);

    for(i = 0; i < sp->length; i++)
    {
        pos = (key + 1) % (sp->length);

        if(sp->flags[pos] == FILLED)
        {
            if(strcmp(elt, sp->data[pos]) == 0)
            {
                 *found = true;
                 return pos;
            }
        }
        if(sp->flags[pos] == DELETED)
        {
            rem = pos;
            first = 1;
        }
        if(sp->flags[pos] == EMPTY)
        {
            *found = false;
            if(first == 1)
                return rem;
            return pos;
        }
    }
    *found = false;
    return -1;
}