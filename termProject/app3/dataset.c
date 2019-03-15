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
    printf("\nCreating List\n");
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
    printf("List Destroyed\n");
	free(lp);
}

void searchAge(LIST *lp, int age)
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
        return;
    }
    printf("\nNo students with age %d found\n", age);
    return;
}

void searchID(LIST *lp, int id)
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
            return;
        }
        p = p->next;
    }
    printf("\nNo students with id %d found\n", id);
}

void insert(LIST *lp, int id, int age)
{
    assert(lp != NULL);
    NODE *p = malloc(sizeof(NODE));
    p->id = id;
    p->age = age; 

    if(lp->count == 0)
    {
        lp->head->next = p;
        p->prev = lp->head;
        p->next = lp->head;
	    lp->head->prev = p;
        printf("Student inserted\n");
        lp->count++;
        return;
    }


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
            printf("\nStudent Deleted.\n");
            return;
        }
        p = p->next;
    }
    printf("\nStudent Not Found.\n");
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

