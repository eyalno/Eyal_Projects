#include <string.h>
#include "ADTDefs.h"
#ifndef VECTOR
#define VECTOR

typedef struct Vector Vector;

Vector *vectorCreate(size_t size,size_t blockSize);
void vectorDestroy(Vector *);
ADTERR vectorGet(Vector*,size_t , int*);
ADTERR vectorSet(Vector *,size_t ,int );
ADTERR vectorItemsNum(Vector *,int* );
ADTERR vectorAdd(Vector*,int );
ADTERR vectorRemove(Vector*,int *);
void printVector(Vector*);
#endif
