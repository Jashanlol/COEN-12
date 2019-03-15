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


int main()
{
    srand(time(NULL));

    LIST *list;
    list = createDataSet();

    printf("\none\n");
    int i, id, age, first; 
    int prevID = 0;

    for(i = 0; i < 1000; i++)
    {
       first = (rand() % (2+1-1)+1);
       id = prevID + first;
       prevID = id;
       age = (rand() % (30+1-18)+18);
       insert(list, id, age);
       printf("\nNew Student - ID %d Age: %d", id, age);
    }

    printf("two\n");

    int pID = (rand() % (2000+1-1)+1);

    searchID(list, pID);

    printf("three\n");

    delete(list, pID);

    printf("four\n");

    maxAgeGap(list);

    printf("five\n");

    destroyDataSet(list);

    printf("done\n");

    return 1;
}

