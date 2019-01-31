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

typedef struct set
{
    int count;
    int length;
    char* *elts;
    int *flags;
} SET;

unsigned strhash(char *s);

SET *createSet(int maxElts)
{
    SET *sp;
    sp = (SET*)malloc(sizeof(SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->elts = (char **)malloc(sizeof(char*)*maxElts);
    assert(sp->elts != NULL);
    sp->flags = malloc(sizeof(int*)*maxElts;)
}

void destroySet(SET *sp)
{

}

int numElements(SET *sp)
{

}

void addElement(SET *sp, char *elt)
{

}

void removeElement(SET *sp, char *elt)
{

}

char *findElement(SET *sp, char *elt)
{

}

char **getElements(SET *sp)
{

}

unsigned strhash(char *s)
{
    unsigned hash = 0;
    while(*s != '\0')
        hash = 31 * hash + *s ++;
    return hash;
}