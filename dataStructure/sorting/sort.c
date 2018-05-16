#include "ADTDefs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"
#include "linkedList.h"


/* global counter complexity*/
int counter=0;

/* print array */
void Print(int* _array, int _size)
{
	int i;
	puts("the array :");
	for (i=0; i<_size; ++i)
	{
		printf("%d ",_array[i]);
	}
	puts("");
}

/*swap 2 items in array */ 
static void Swap(int *_array,int _a,int _b)
{
	int tmp=_array[_a];
	_array[_a]=_array[_b];
	_array[_b]=tmp;
}

/* splits the array smaller < pivot <higher and returns the new pivot */
static int Partition(int * _array,int _left,int _right,int _pivotIndex)
{
	int pivotValue= _array[_pivotIndex];
	int storeIndex;
	int i;
	
	/*pivot to the right of tha array  */	
	Swap(_array,_pivotIndex,_right);
	storeIndex = _left;
	
	/*comapre all items to the pivot and swap smaller accordingly*/
	for (i=_left; i < (_right); ++i)
	{
			++counter;
		if (_array[i] < pivotValue)
		{
			Swap(_array,i,storeIndex);
			++storeIndex;
		}
	}
	/*pivot to its new location */	
	Swap(_array,storeIndex,_right);
	return storeIndex;
}

/*sort algoritem which first sort and splits the array accords to a given pivot. second recursively call   */
void QuickSort(int *_array,int _left,int _right)
{
	int pivotIndex;
	int newPivotIndex;
	
	/* stop condition */
	if (_left < _right)
	{
		/* sorts and tset the pivot*/
		pivotIndex= _left;	
		newPivotIndex=Partition(_array,_left,_right,pivotIndex);
		
		/* split the array*/
		QuickSort(_array,_left,newPivotIndex-1);
		QuickSort(_array,newPivotIndex+1,_right);
		
	}
}

/*compare item to the next loop all the array and swap if needed. runs on every element excelusivlly  */
void BubbleSort(int *_array, int _size)
{
  int i, j ,innerCounter=0;;
 
  /* 2 nestetd for . runs on all array and for each element*/
  for (i = (_size - 1); i > 0; i--)
  {
    for (j = 1; j <= i; j++)
    {
	++counter;
      if (_array[j-1] > _array[j])
      {
        Swap(_array,j-1,j);
	++innerCounter;
      }
    }	
	/* optimize if no swaps made return array is sorted*/
	if (innerCounter ==0)
	{
		return;
	}
	innerCounter=0;
  }
}

/*runs in array if next item is small push it back to is location if bigger runs on him*/
void Insertion(int *_array,int _size)
{
	int i,j,key;
	/* runs on the array*/
	for(j=1;j<_size ;++j)
	{
		key=_array[j];
		i=j-1;
		/* push back the small item*/
		while(i>=0 && _array[i]>key)
		{
			_array[i+1]=_array[i];
			--i;
		}
		_array[i+1]=key;
	}

}

/* merges the 2 sorthed arrays*/
static void Merge(int* _array,int _p,int _q,int _r)
{
int i= _p, j= _q+1 , k= 0;
int *B=(int*)malloc(sizeof(int)*( _r - _p + 1));

	/* comparing the 2 arrays and copies to aux array until 1 array has finished*/ 
	while (i <= _q && j <= _r )
	{
		if(_array[i] < _array[j])
		{
			B[k]=_array[i];
			++i;
		}
		else 
		{	
			B[k]=_array[j];
			++j;
		}
		++k;
	}
	/*copy the rest of the left array */ 
	while (i<=_q)
	{
		B[k]=_array[i];
		++i;
		++k;
	}
	
	/*copy the rest of the right array */ 
	while (j <= _r)
	{
		B[k]=_array[j];
		++j;
		++k;
	}
	
	/* copy back the sorted arrray*/ 
	for (i=0,j=_p; i <= _r - _p  ;++i,++j)
	{
		_array[j]=B[i];
	} 
}


/* splitts the array recursivly to 2 parts in the middle
 each itteration and merge them bottom up */	
void MergeSort(int* _array,int _p,int _r)
{
	int q;
	
	/* stop condition*/
	if (_p < _r)
	{
		q=(_p + _r)/2;
		MergeSort(_array,_p,q);
		MergeSort(_array,q+1,_r);
		Merge(_array,_p,q,_r);
	}
	

}


int * CountingSort(int *_a,int _k,int _size)
{
	int i,j;
	
	int *_b=(int*)calloc(_size,sizeof(int));
	int *_c=(int*)calloc(_k,sizeof(int));
	
	/* counting occurence of each num into c array*/
	for(j=0; j<_size; ++j)
	{
		++_c[_a[j]-1];
	}
	/*adding adjucante items the right item  */
	for (i=1; i<_k; ++i)
	{
		_c[i]+= _c[i-1];
	
	}
	/*scans the A array from rightr to left using each number as an index */ 
	/* for the C array taking the value as index  to insert the original item to b array. decreasng the count in C aarray   */ 	
	for (j=_size-1;j>-1; --j)
	{
		_b[_c[_a[j]-1]-1] =_a[j];
		--_c[_a[j]-1];

	}
	return _b;
}

void Radixsort(int *a, int _size )
{
	int i,  m = a[0], exp = 1;
 	int bucket[10] ={  0 };
	int* b=(int*)malloc(sizeof(int)*_size);	
	
	/* search for the number with the most digits= maximum number*/
	for (i = 0; i < _size; i++)
  	{
		if (a[i] > m)
		m = a[i];
  	}
 
	/* counting sort for each digit*/
	while (m / exp > 0)
  	{
        	for (i = 0; i < _size; i++)
		{
      			/* count instances accord to digit */
			bucket[a[i] / exp % 10]++;
    		}
		for (i = 1; i < 10; i++)
      		{	
			bucket[i] += bucket[i - 1];
    		}
		for (i = _size - 1; i >= 0; i--)
      		{
			/* sorting according to instances*/
			b[--bucket[a[i] / exp % 10]] = a[i];
    		}
		for (i = 0; i < _size; i++)
      		{	
			a[i] = b[i];
    		}
		
		exp *= 10;
	}
}


