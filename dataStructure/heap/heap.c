#include "ADTDefs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"
#include "heap.h"

static void Heapify(Vector* _vec,int i)
{
int left,right,largest,largestNum,index,itemsNum;
	

	vectorItemsNum(_vec,&itemsNum);
	vectorGet(_vec,2*i+1,&left);
	vectorGet(_vec,2*i+2,&right);
	vectorGet(_vec,i,&index);
	
	largest =(2*i+1 <= itemsNum-1 && left > index )?2*i+1:i;
	vectorGet(_vec,largest,&largestNum);

	if( 2*i+2 <= itemsNum-1 && right >largestNum)
	{
		largest=2*i+2;
		largestNum=right;
	}

	if (largest != i)
	{
		vectorSet(_vec,i,largestNum);
		vectorSet(_vec,largest,index);
		Heapify(_vec,largest);
	}
}

Heap* HeapBuild(Vector* _vec)
{
	int i,itemsNum;
	vectorItemsNum(_vec,&itemsNum);
	
	for (i= itemsNum/2; i>0;--i)
	{
		Heapify( _vec,i-1);
	}

return (Heap*)_vec;	
}

void HeapDestroy(Heap* _heap)
{
}

ADTERR HeapInsert(Heap* _heap,int _item)
{
int parent,parentIndex,index;
Vector* _heapV=(Vector*)_heap;	
	
	vectorAdd(_heapV,_item);
	vectorItemsNum(_heapV,&index);
	--index;
	parentIndex=(index)/2;	
	
	vectorGet(_heapV,parentIndex,&parent);	
	while (_item > parent && index !=0)
	{
		vectorSet(_heapV,index,parent);
		vectorSet(_heapV,parentIndex,_item);
		
		index = parentIndex;
		--parentIndex;
		parentIndex /=2;
		vectorGet(_heapV,parentIndex,&parent);	
	
	}
return ERR_OK;
}

ADTERR HeapMax(Heap* _heap,int* _item)
{
	vectorGet((Vector *)_heap,0,_item);
return ERR_OK;
}

ADTERR HeapExtractMax(Heap* _heap,int* _item)
{
	int last,num;
	Vector* _heapV=(Vector*)_heap;	
	
	vectorGet(_heapV,0,_item);
	
	vectorItemsNum(_heapV,&last);
	vectorGet(_heapV,last-1,&num);
	vectorSet(_heapV,0,num);
	vectorRemove(_heapV,&num);
	Heapify( _heapV,0);

	
return ERR_OK;
}

int HeapSize(Heap* _heap)
{
	int num;
	vectorItemsNum((Vector*)_heap,&num);
return num;
	
}

void HeapPrint(Heap* _heap)
{
	printVector((Vector*)_heap);
}








