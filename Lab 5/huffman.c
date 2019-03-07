/*
*   Spencer Goles   COEN 12    5 March 2019
*   Description: This program applies Huffman Coding to compress files. 
*
*/

//Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "pqueue.h"
#include "pack.h"

//Declares NODE as struct node
typedef struct node NODE;

//Function counts the distance from leaf to the root
//Big-O: O(h)
int hopNum(NODE *leaf)
{
    int hop = 0;
    while(leaf->parent != NULL)
    {
        leaf = leaf->parent;
        hop++;
    }
    return hop;
}

//Function compartes the data in two nodes
//Big-O: O(1)
int compare(NODE *first, NODE *second)
{
    return (first->count < second->count) ? -1 : (first->count > second->count);
}


int main(int argc, char *argv[])
{
    //Opens and reads each char in file assigning use numbers to array
    FILE *fp = fopen(argv[1], "r");
    if(fp != NULL)
        return 0;
    int instants[257] = {0};

    do
    {
        int ch;
        ch = fgetc(fp);
        if(feof(fp))
            break;
        instants[ch]++;
    } while(1);

    //Creates the priority queue
    PQ *pq = createQueue(compare);


    NODE *leaves[257] = {0};
    int i;
    for(i = 0; i < 257; i++)
        leaves[i] = NULL;

    for(i = 0; i < 257; i++)
    {
        if(instants[i] > 0)
        {
            NODE *p = malloc(sizeof(NODE));
            p->count = instants[i];
            p->parent = NULL;
            addEntry(pq, p);
            leaves[i] = p;
        }
    }

    //Add zeroCount Node to last slot
    NODE *zeroCount = malloc(sizeof(NODE));
    zeroCount->count = 0;
    zeroCount->parent = NULL;
    addEntry(pq, zeroCount);
    leaves[256] = zeroCount; 


    //Combines lowest priority trees to one until huffman tree is left
    while(numEntries(pq) > 1)
    {
        NODE *one = removeEntry(pq);
        NODE *two = removeEntry(pq);
        NODE *three = malloc(sizeof(NODE));
        three->count = (one->count + two->count);
        three->parent = NULL;
        one->parent = three; 
        two->parent = three;
        addEntry(pq, three); 
    }


    //Prints out vaild nodes
    for(i = 0; i < 257; i++)
    {
        if(leaves[i] != NULL)
        {
            int numHops = hopNum(leaves[i]);
            if(isprint(i))
            {
                printf("%c: %d x %d bits = %d bits", i, instants[i], numHops, numHops*instants[i]);
            }
            else
            {
                 printf("%03o: %d x %d bits = %d bits", i, instants[i], numHops, numHops*instants[i]);
            }
        }
    }

    //Packs huffman tree 
    pack(argv[1], argv[2], leaves);
}

