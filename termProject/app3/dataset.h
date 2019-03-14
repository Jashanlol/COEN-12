#ifndef DATASET_H
#define DATASET_H

//typedef struct node NODE;
typedef struct list LIST;

extern LIST *createDataSet();

extern void destroyDataSet(LIST *lp);

extern int searchAge(LIST *lp, int age);

extern int searchID(LIST *lp, int id);

extern void insert(LIST *lp, NODE *p);

extern void delete(LIST *lp, int id);

extern void maxAgeGap(LIST *lp);

#endif 