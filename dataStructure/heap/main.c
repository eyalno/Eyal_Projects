/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "vector.h"
#include "heap.h"
#include "ADTDefs.h"


int main(){

Vector *tmp;
Heap *heap;
int a;

/*Unitest create vector */
tmp=vectorCreate(5,8);
vectorAdd(tmp,4);
vectorAdd(tmp,9);
vectorAdd(tmp,8);
vectorAdd(tmp,10);
vectorAdd(tmp,1);
vectorAdd(tmp,2);
vectorAdd(tmp,11);
vectorAdd(tmp,12);
vectorAdd(tmp,13);
puts("vector");
printVector(tmp);

/*Unitest building the heap */
heap=HeapBuild(tmp);
puts("build");
HeapPrint(heap);

/*Unitest item to heap */
HeapInsert(heap,20);
puts("insert");
HeapPrint(heap);

/*Unitest max item in heap */
HeapMax(heap,&a);
printf("%d\n",a);
a=5;

/*Unitest extract max item */
HeapExtractMax(heap,&a);
puts("extract max");
HeapPrint(heap);

/*Unitest num of items */
puts("num of items");
printf("%d\n",HeapSize(heap));

return 0;
}
