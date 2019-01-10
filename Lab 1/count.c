/*********************************************************************/ 
/*  Spencer Goles    COEN 12         9 Jan 2019                      */
/*  Program Function: To count number of words in a text file        */
/*********************************************************************/ 

//Pre-processors
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 30

//Main Function
int main(int argc, char *argv[ ])
{
    FILE *fp;
    char str[MAX_WORD_LENGTH];
    int count = 0; 
    //Check to see if the file is included
    if (argc == 1)
    {
        printf("The name of the file is missing!\n");
        return 1;
    }
    //Opens the file to scan
    fp = fopen(argv[1], "r");
    //Loop to count words in the file
    while(fscanf(fp, "%s", str) == 1) count++;
    fclose(fp);
    printf("\nWord Count: %d\n", count); 
    return 0;
}

