#include <string.h>
#include "ADTDefs.h"
#ifndef VECTOR
#define VECTOR

typedef struct Vector{
int * m_Array;
size_t m_SizeArr;
size_t m_ItemsNum;
size_t m_blockSize; 
}Vector;

Vector *vectorCreate(size_t size,size_t blockSize);
void vectorDestroy(Vector *);
ADTERR vectorGet(Vector*,size_t , int*);
ADTERR vectorSet(Vector *,size_t ,int );
ADTERR vectorItemsNum(Vector *,int* );
ADTERR vectorAdd(Vector*,int );
ADTERR vectorRemove(Vector*,int *);
void printVector(Vector*);
#endif
