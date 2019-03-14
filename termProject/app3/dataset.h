#ifndef DATASET_H
#define DATASET_H

typedef struct list LIST;

extern LIST *createDataSet();

extern void destroyDataSet(LIST *lp);

extern int searchAge(LIST *lp, int age);

extern int searchID(LIST *lp, int id);

extern void insert(LIST *lp, int id, int age);

extern void delete(LIST *lp, int id);

extern void maxAgeGap(LIST *lp);

#endif