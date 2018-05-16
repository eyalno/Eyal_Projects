/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "sort.h"
#include "ADTDefs.h"
#include "linkedList.h"

extern int counter;



int main()
{
	int  array[]={40,35,75,45,5,25,65,20,60,15,70,50,10,55,30};	
	int  array1[]={75,70,65,60,55,50,45,40,35,30,25,20,15,10,5};		
	int  array2[]={4,1,3,5,6,7,2};
	int  array3[]={7,6,5,4,3,2,1};	
	int  array4[]={1,2,3,4,5,6,7};	
	int  array5[]={2,3,1,3,2,5,3,1,5};
	int  array6[]={2,3,1,3,2,5,3,1,5};
	int *tmp;	
	
	List *list;
	
	Print(array,15);
	counter =0;	
	QuickSort(array,0,14);
	Print(array,15);
	puts("QuickSort , pivot in the middle");
	printf("best case %d\n\n",counter);	
	
	counter =0;	
	Print(array1,15);
	QuickSort(array1,0,14);
	Print(array1,15);
	puts(" pivot in the edge");
	printf("worst case %d\n\n",counter);
	
	counter=0;
	Print(array3,7);
	BubbleSort(array3,7);
	Print(array3,7);
	printf("BubbleSort Worst case %d\n\n",counter);
	
	counter=0;
	Print(array4,7);
	BubbleSort(array4,7);
	Print(array4,7);
	printf("best case %d\n\n",counter);

	counter=0;
	Print(array3,7);
	Insertion(array3,7);
	Print(array3,7);
	printf("InsertionSort %d\n\n",counter);
	
	counter=0;
	Print(array4,7);
	Insertion(array4,7);
	Print(array4,7);
	printf("Insertion %d\n\n",counter);

	counter=0;
	Print(array2,7);
	MergeSort(array2,0,6);
	Print(array2,7);
	printf("merge sort %d\n",counter);

	counter=0;
	Print(array5,9);
	tmp=CountingSort(array5,10,9);
	Print(tmp,9);
	printf("Counting Sort %d\n",counter);

	counter=0;
	Print(array6,9);
	Radixsort(array6,9);
	Print(array6,9);
	printf("radix Sort %d\n",counter);

	list=listCreate();
	listPushHead(list,5);
	listPushHead(list,3);
	listPushHead(list,6);
	listPushHead(list,7);
	listPushHead(list,3);

	
	listPrint(list);
	TranspositionSort(list,6);	
	listPrint(list);
	

	return 0;
}
