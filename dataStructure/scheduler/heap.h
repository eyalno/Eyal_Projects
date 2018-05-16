/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 5.11.12
		Description: Generic Heap header file functions forward declerations
		Text Editor:  gVim
***********************************************************************/


#ifndef HEAP_H
#define HEAP_H

#include "vector.h" 

/*macro functions*/
typedef int (*CmpFunc)(void*,void* );

/*struct macro*/
typedef struct Heap Heap;
typedef void HeapData;

/*build heap from a given vector*/
Heap* HeapBuild(Vector* _vec,CmpFunc _func);

/*destory all alocated memmory vector and heap*/
void HeapDestroy(Heap* _heap);

/*inesrt new data to heap*/
ADTErr HeapInsert(Heap* _heap,HeapData* _data);

/*shows, returns the max of data root of tree*/
HeapData* HeapMax(Heap* _heap);

/*extract the max data copy the lowest data to the root and heapify him */
HeapData* HeapExtract(Heap* _heap);

/*runs on heap (vector) and apply do function*/
int HeapForEach(Heap* _heap,DoFunc _doFunc,void* _params);

/*returns size of heap*/
size_t HeapSize(Heap* _heap);



#endif
