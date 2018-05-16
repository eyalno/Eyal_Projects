#include <string.h>
#include "ADTDefs.h"
#ifndef VECTOR
#define VECTOR

typedef struct Vector Vector;

Vector *vectorCreate(size_t size,size_t blockSize);

void vectorDestroy(Vector *);

ADTErr vectorGet(Vector*,size_t , int*);

ADTErr vectorSet(Vector *,size_t ,int );

ADTErr vectorItemsNum(Vector *,int* );

ADTErr vectorAdd(Vector*,int );

ADTErr vectorRemove(Vector*,int *);

void printVector(Vector*);
#endif
