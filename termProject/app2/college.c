/*
*   Spencer Goles   COEN 12   12 March 2019
*   Program: college.c      Project: app2 (Term Project)
*   Description: This file generates students and tests the dataset functionality
*
*/

//Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dataset.h"

#define MAX_STUDENTS 3000


int main()
{
    srand(time(NULL));

    SET *sp = createDataSet(MAX_STUDENTS);

    int i, id, age, first; 
    int prevID = 0;

    //Loop to generate 1000 random students
    for(i = 0; i < 1000; i++)
    {
        first = (rand() % (2+1-1)+1);
        id = prevID + first;
        prevID = id;
        age = (rand() % (30+1-18)+18);
        insert(sp, id, age);
    }

    //New student random ID, search, and deletion
    int pID = (rand() % (2000+1-1)+1);

    searchID(sp, pID);

    delete(sp, pID);

    deleteDataSet(sp);

    return 1;
}