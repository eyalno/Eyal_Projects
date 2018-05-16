
#include <stdio.h>
#include "vector.h"
#include "heap.h"
#include "logger.h"
#include "ADTDefs.h"

/*print function*/
void print(void* _data,void* _params)
{
	printf("%d ",*(int*)_data);
}

/*compare function*/
int Compare(HeapData* _left, HeapData* _right)
{
	

	if (  *(int*)(_left)  > *(int*)(_right) )
	{
		return 1;
	}
	return 0;
	

}


int main()
{	
	Heap *heap; 
	int a=2,b=3,c=1,d=4,e=5,f=6,g=7;
	Vector* vector =VectorCreate(8,8);

	LogCreate(ERR | WARR | DEB | RMN,"Log File");


	LogRegister(ERR,"test","main.c","main");
	VectorAdd(vector,&a);
	VectorAdd(vector,&b);
	VectorAdd(vector,&c);
	
	VectorAdd(vector,&d);
	
	VectorAdd(vector,&e);
	
	heap=HeapBuild(vector,Compare);
	
	HeapForEach(heap,print,&d);		
	putchar('\n');		
	
	HeapInsert(heap,&f);
	HeapInsert(heap,&g);
	
	HeapForEach(heap,print,&d);		
	putchar('\n');		
	
	printf("max %d\n",*(int*)HeapMax(heap));
	HeapExtract(heap);		
	
	HeapForEach(heap,print,&d);		
	putchar('\n');		
	
	HeapForEach(heap,print,&d);		
	putchar('\n');		
	
	
	printf("size %d\n",HeapSize(heap));


return 0;
}
