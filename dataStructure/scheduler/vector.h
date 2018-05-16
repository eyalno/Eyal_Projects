#ifndef VECTOR
#define VECTOR

#include <stdlib.h>
#include "ADTDefs.h"

typedef struct Vector Vector;
typedef void (*DoFunc)(void*,void* );

struct Vector
{
	void ** m_Array;
	size_t m_SizeArr;
	size_t m_ItemsNum;
	size_t m_blockSize; 
};

Vector *VectorCreate(size_t size,size_t blockSize);

void VectorDestroy(Vector *);

ADTErr VectorGet(Vector*,size_t , void**);

ADTErr VectorSet(Vector *,size_t ,void* );

ADTErr VectorItemsNum(Vector *,int* );

ADTErr VectorAdd(Vector*,void* );

ADTErr VectorRemove(Vector*,void **);

int VectorForEach(Vector*_vec,DoFunc _doFunc,void* _params);
#endif
