/*
*   Spencer Goles   COEN 12   10 March 2019
*   Program: college.c      Project: app3 (Term Project)
*   Description:
*
*/

//Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dataset.h"

int randomAge()
{
    int n = 12;
    int limit;
    int r;
    limit = RAND_MAX - (RAND_MAX % n);
    while((r = rand()) >= limit);
    return (r % n) + 18;
}

int oneOrTwo()
{
    int n = 2;
    int limit;
    int r;
    limit = RAND_MAX - (RAND_MAX % n);
    while((r = rand()) >= limit);
    return (r % n) + 1;
}
int randomID()
{
    int n = 2000;
    int limit;
    int r;
    limit = RAND_MAX - (RAND_MAX % n);
    while((r = rand()) >= limit);
    return (r % n) + 1;
}

int main()
{
    LIST *list;
    list = createDataSet();

    int i, id; 
    id = oneOrTwo();
    for(i = 0; i < 1000; i++)
    {
        NODE *p;
        p->id = id;
        p->age = randomAge();
        p->next = NULL;
        p->prev = NULL;
        insert(list, p);
        id += 2;
    }

    NODE *student;
    student->id = randomID();
    student->age = randomAge();
    student->next = NULL;
    student->prev = NULL;


    int found = searchID(list, student->id);

    delete(list, student->id);

    maxAgeGap(list);

    destroyDataSet(list);

    return 1;
}