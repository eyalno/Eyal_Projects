#include "ADTDefs.h"
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "linearQueue.h"
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

struct  Queue
{
	Vector* m_Vec;
};



Queue* queueCreate(size_t _size, size_t _blockSize){
	
	return (Queue *)vectorCreate(_size,_blockSize);;
}

void queueDestroy(Queue* _queue){
	vectorDestroy((Vector*)_queue);
}

ADTERR queueInsert(Queue* _queue,int _item){
	return vectorAdd((Vector*)_queue,_item);

}

ADTERR queueRemove(Queue* _queue,int* _item){
int numItems;
ADTERR status= vectorItemsNum((Vector*)_queue,&numItems);
Vector *tmp=(Vector*)queueCreate(numItems-1,8);
int num;
int i;
	if (queueIsEmpty(_queue)){
		return	ERR_NOTINITILIZED;
	}
	for (i=0; i<numItems-1; i++){
		vectorRemove((Vector*)_queue,&num);
		vectorAdd(tmp,num);
	}
	status=vectorRemove((Vector*)_queue,&num);		
	*_item=num;
	
	for (i=0; i<numItems-1; i++){
		vectorRemove(tmp,&num);
		vectorAdd((Vector*)_queue,num);
	}
	vectorDestroy(tmp);
	return status;
}

int queueIsEmpty(Queue* _queue){
	
	return((Vector*)_queue)->m_ItemsNum ? FALSE:TRUE;
}


void queuePrint(Queue* _queue){

	printVector((Vector*)_queue);
		
}
/*
void queueMove(Queue* dst,Queue* src){

	while(!queueIsEmpty(src)){
		
	}
}
*/




