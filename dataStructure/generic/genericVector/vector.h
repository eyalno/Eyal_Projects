/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.11.12
		Description: Generic vector header file functions forward declerations
		Text Editor:  gVim
***********************************************************************/

#ifndef VECTOR
#define VECTOR

#include <stdlib.h>
typedef struct Vector Vector;
typedef void (*DoFunc)(void*,void* );

/*creates vector args initial size and block to realloc*/
Vector *VectorCreate(size_t size,size_t blockSize);

/*free vector and allocated memory*/
void VectorDestroy(Vector *);

/*retrieves the generic data from the vector*/
ADTErr VectorGet(Vector*,size_t , void**);

/*set new data in the vector*/
ADTErr VectorSet(Vector *,size_t ,void* );

/*returns number of items in vector*/
ADTErr VectorItemsNum(Vector *,int* );

/*add data to the end of vector*/
ADTErr VectorAdd(Vector*,void* );

/*remove data from vector*/
ADTErr VectorRemove(Vector*,void **);

/*go through all vector and implement the function on data*/
int VectorForEach(Vector*_vec,DoFunc _doFunc,void* _params);

#endif
