#ifndef STACK_H
#define STACK_H
#include "ADTDefs.h"
#include "linkedList.h"

/* quick sort decleration*/
void QuickSort(int *_array,int _right,int _left);

void BubbleSort(int *_array, int _size);

void Insertion(int *_array,int _size);

void MergeSort(int* _array,int _p,int _r);

int * CountingSort(int *_A,int _k,int _size);

void Radixsort(int *a, int n);

bolean TranspositionSort(List* _list,int _num);

#ifdef _DEBUG
	void Print(int* _array, int _size);
#endif

#endif
