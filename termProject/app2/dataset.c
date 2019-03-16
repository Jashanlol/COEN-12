/*
*   Spencer Goles   COEN 12   12 March 2019
*   Program: dataset.c      Project: app2 (Term Project)
*   Description: This file impliments a array to hold students 
*
*/

//Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dataset.h"

//Array states
#define FILLED 1
#define EMPTY 0

struct set
{
    int count;
    int length; 
    int *age; 
    int *flag; 
};

//Function creates and initializes the array
SET *createDataSet(int max)
{
    SET *sp = malloc(sizeof(SET));
    assert(sp != NULL); 
    sp->age = malloc(sizeof(int)*max);
    sp->flag = malloc(sizeof(int)*max);
    assert(sp->age != NULL && sp->flag != NULL);
    sp->count = 0;
    sp->length = max; 
    int i;
    for(i = 0; i < sp->length; i++)
        sp->flag[i] = EMPTY;
    return sp; 
}

//Function deletes all elements in the student array
void deleteDataSet(SET *sp)
{
    assert(sp != NULL);
    free(sp->age);
    free(sp->flag);
    free(sp);
    printf("\nData Set Destroyed\n\n");
}

//Function checks array for student with O(1) lookup
void searchID(SET *sp, int id)
{
    assert(sp != NULL);
    if(sp->flag[id] == FILLED)
        printf("\n\nThe student with ID: %d has been found.\n", id);
    else
        printf("\n\nThe student with ID: %d could not be found.\n", id);
}

//Function inserts a new student into the array based on ID
void insert(SET *sp, int id, int age)
{
    assert(sp != NULL);
    if(sp->flag[id] == FILLED)
    {
        printf("\nStudent already exists.\n");
        return;
    }
    sp->age[id] = id;
    sp->flag[id] = FILLED;
    sp->count++;
    printf("Inserted Student - ID: %d Age: %d\n", id, age);
}

//Function checks and deletes student based on ID
void delete(SET *sp, int id)
{
    assert(sp != NULL);
    if(sp->flag[id] == FILLED)
    {
        sp->flag[id] = EMPTY;
        sp->age[id] = NULL;
        printf("\nStudent with ID: %d Removed\n", id);
        sp->count--;
    }
    else
        printf("\nStudent not found to remove ID: %d.\n\n", id);
}

