/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 5.11.12
		Description: Generic Heap implementation
		Text Editor:  gVim
***********************************************************************/

/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*local libaries*/
#include "vector.h"
#include "ADTDefs.h"
#include "heap.h"
#include "logger.h"


struct Heap
{
	Vector* m_vec;
	CmpFunc m_func;
};

/*goes down the tree compare 3 elements in the heap. copy the largest to be the father, after the switch heapify on the replaced son */
static void Heapify(Vector* _vec,int i,CmpFunc _func)
{
	int largest,itemsSum;
	HeapData * left,*right,*largestData,*current;

	
	/*extracting from vector the data on 3 elements*/
	VectorItemsNum(_vec,&itemsSum);

	VectorGet(_vec, 2*i + 1 , &left);
	VectorGet(_vec, 2*i + 2 , &right);
	VectorGet(_vec, i , &current);
	
	largest =(2 * i + 1 <= itemsSum-1 && _func(left , current) ) ? 2 * i + 1 : i;
	VectorGet(_vec, largest, &largestData);

	/*comparing which of the 3 is max*/
	if( 2 * i + 2 <= itemsSum - 1 && _func(right ,largestData))
	{
		largest = 2*i + 2;
		largestData = right;
	}
	
	LogRegister(ERR,"heapify recursive","heap.c","heapify");
	
	/*if the father is not the max switch and heapify*/
	if (largest != i)
	{
		VectorSet(_vec,i,largestData);
		VectorSet(_vec,largest,current);
		Heapify(_vec,largest,_func);
	}
}

/*build heap from a given vector*/
Heap* HeapBuild(Vector* _vec,CmpFunc _func)
{
	int i,itemsSum;
	Heap* heap=(Heap*)malloc(sizeof(Heap));
	VectorItemsNum(_vec,&itemsSum);
	
	/*heapify on all the father nodes */
	for (i= itemsSum / 2; i > ZERO; --i)
	{
		Heapify( _vec,i - 1,_func);
			
	}
	
	heap->m_vec=_vec;
	heap->m_func=_func;
	
	LogRegister(ERR,"build heap succeded","heap.c","Heap Build");
	return heap;	
}

/*destory all alocated memmory vector and heap*/
void HeapDestroy(Heap* _heap)
{
	VectorDestroy(_heap->m_vec);
	free(_heap);
	LogRegister(ERR,"destroy succeded","heap.c","Heap Destroy");
}

/*inesrt new data to heap*/
ADTErr HeapInsert(Heap* _heap,HeapData* _data)
{
	int parentIndex,index;
	HeapData* parent;
	Vector* _heapV=_heap->m_vec;	

	/*add the item to the end of vector extract data from vector */	
	VectorAdd(_heapV,_data);
	VectorItemsNum(_heapV,&index);
	--index;
	parentIndex=(index) / 2;	
	
	VectorGet(_heapV,parentIndex,&parent);	

	/*compare item to his father if bigger switch and check to next father else return*/
	while (_heap->m_func(_data , parent) && index !=ZERO)
	{
		VectorSet(_heapV,index,parent);
		VectorSet(_heapV,parentIndex,_data);
		
		index = parentIndex;
		--parentIndex;
		parentIndex /=2;
		VectorGet(_heapV,parentIndex,&parent);	
	
	}
	LogRegister(ERR,"insert item  succeded","heap.c","Heap Insert");
	
	return ERR_OK;
}

/*shows, returns the max of data root of tree*/
HeapData* HeapMax(Heap* _heap)
{
	HeapData* tmp;
	VectorGet(_heap->m_vec,ZERO,&tmp);
	return tmp;
}


/*extract the max data copy the lowest data to the root and heapify him */
HeapData* HeapExtract(Heap* _heap)
{
	int last;
	HeapData* tmp,*data;
	
	/*extract data from vector and replace max to low*/
	Vector* heapV=_heap->m_vec;	
	
	VectorGet(heapV,ZERO,&tmp);
	
	VectorItemsNum(heapV,&last);

	VectorGet(heapV,last-1,&data);
	VectorSet(heapV,ZERO,data);
	VectorRemove(heapV,&data);
	
	/*heapify lowest at root*/
	Heapify( heapV,ZERO,_heap->m_func);

	
	return tmp;
}

/*runs on heap (vector) and apply do function*/
int HeapForEach(Heap*_heap,DoFunc _doFunc,void* _params)
{
	VectorForEach(_heap->m_vec,_doFunc,_params);		
	
	return 1;
		
}

/*returns size of heap*/
size_t HeapSize(Heap* _heap)
{
	int num;
	VectorItemsNum(_heap->m_vec,&num);
	return num;
	
}









