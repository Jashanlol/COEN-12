#ifndef DATASET_H
#define DATASET_H

typedef struct set SET;

SET *createDataSet(int max);
void deleteDataSet(SET *sp);
void searchID(SET *sp, int id);
void insert(SET *sp, int id, int age);
void delete(SET *sp, int id);

#endif