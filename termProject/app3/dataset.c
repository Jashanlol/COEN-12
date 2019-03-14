/*
*   Spencer Goles   COEN 12   10 March 2019
*   Program: dataset.c      Project: app3 (Term Project)
*   Description:
*
*/

//Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dataset.h"

typedef struct node
{
    int id;
    int age; 
    struct node *next; 
    struct node *prev;
} NODE;

struct list
{
    int count; 
    NODE *head;
};

LIST *createDataSet()
{
    printf("Creating List");
    LIST *lp = malloc(sizeof(LIST));
    assert(lp != NULL);
    lp->count = 0;
    lp->head = malloc(sizeof(NODE));
    assert(lp->head != NULL);
	lp->head->next = lp->head;    
	lp->head->prev = lp->head;    
	return lp;
}

void destroyDataSet(LIST *lp)
{
    assert(lp != NULL);
	NODE *pDel, *pNext;
	pDel = lp->head;
	do
	{
		pNext = pDel->next;
		free(pDel);
		pDel = pNext;
	} while (pDel != lp->head);
    printf("List Destroyed");
	free(lp);
}

int searchAge(LIST *lp, int age)
{
    assert(lp != NULL);
    NODE *p = lp->head->next;
    int i, found;
    found = 0;
    for(i = 0; i < lp->count; i++)
    {
        if(p->age == age)
        {
            printf("Search has been successful!\n");
            printf("Student ID: %d with age %d\n", p->id, p->age);
            found = 1;
            break;
        }
        p = p->next;
    }
    if(found == 1) 
    {
        printf("\nAll students with age %d found\n", age);
        return 1;
    }
    printf("\nNo students with age %d found", age);
    return -1;
}

int searchID(LIST *lp, int id)
{
    printf("\nSearching for ID\n");
    assert(lp != NULL);
    NODE *p = lp->head->next;
    int i;
    for(i = 0; i < lp->count; i++)
    {
        if(p->id == id)
        {
            printf("\nSearch has been successful!\n");
            printf("\nStudent ID: %d  Age: %d\n", p->id, p->age);
            return 1;
        }
        p = p->next;
    }
    printf("\nNo students with id %d found\n", id);
    return -1;
}

void insert(LIST *lp, int id, int age)
{
    assert(lp != NULL);
    NODE *p;
    p->id = id;
    p->age = age; 
    NODE *h = lp->head->next;
    while(h != NULL)
    {
        if(p->age <= h->age)
        {
            p->next = h;
            p->prev = h->prev;
            h->prev = p;
            h->prev->next = p;
            lp->count++;
            printf("Student Added ID: %d Age: %d", id, age);
            return;
        }
        h = h->next;
    }
}

void delete(LIST *lp, int id)
{
    assert(lp != NULL);
    NODE *p = lp->head->next;
    int i;
    for(i = 0; i < lp->count; i++)
    {
        if(p->id == id)
        {
            p->next->prev = p->prev;
            p->prev->next = p->next; 
            free(p);
            lp->count--;
            printf("Student Deleted.");
            return;
        }
        p = p->next;
    }
    printf("Student Not Found.");
}

void maxAgeGap(LIST *lp)
{
    assert(lp != NULL);
    if(lp->count > 1)
    {
        int minAge = lp->head->next->age;
        int maxAge = lp->head->prev->age;
        int gap = maxAge - minAge;
        printf("\nMax Age Gap: %d\n", gap);
        return;
    }
    printf("\nNot enough students to calculate gap.\n");
}




