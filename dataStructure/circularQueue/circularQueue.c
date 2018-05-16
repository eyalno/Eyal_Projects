#include "ADTDefs.h"
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "circularQueue.h"
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

struct  Queue
{
	int* m_Vec;
	size_t m_Head;
	size_t m_Tail;
	size_t m_NumItems;
	size_t m_Size;
};

Queue* queueCreate(size_t _size) 
{
Queue* tmpQ;
		
	if (!_size)
	{
                return NULL;
        }

        if (!(tmpQ=(Queue*)malloc(sizeof(Queue))))
	{
                return NULL;
        }

        if (!(tmpQ->m_Vec=(int*)malloc(sizeof(int)*_size)))
	{
                free(tmpQ);
                return NULL;
        }
	tmpQ->m_Size=_size;
        tmpQ->m_NumItems=0;
	tmpQ->m_Head=tmpQ->m_Tail=0;
        return tmpQ;
}

void queueDestroy(Queue* _queue)
{
	if (_queue)
	{
		free(_queue->m_Vec);	
		free(_queue);
	}
}

ADTERR queueInsert(Queue* _queue,int _item)
{

	if (!_queue )
	{
	        return ERR_ALLOC_FAILED;
	}

	if(_queue->m_NumItems == _queue->m_Size)
	{
		return ERR_INDEX_BOUNDRIES;
	}
	++_queue->m_NumItems;	
        _queue->m_Vec[_queue->m_Tail]=_item;
	++_queue->m_Tail;	
	_queue->m_Tail%=_queue->m_Size;
return ERR_OK;	
}

ADTERR queueRemove(Queue* _queue,int* _item)
{
	if (!_queue )
	{
	        return ERR_ALLOC_FAILED;
	}

	if(!_queue->m_NumItems )
	{
		return ERR_INDEX_BOUNDRIES;
	}
	--_queue->m_NumItems;	
	
       *_item=_queue->m_Vec[_queue->m_Head];
	++_queue->m_Head;
	_queue->m_Head%=_queue->m_Size;
return ERR_OK;
}

int queueIsEmpty(Queue* _queue)
{
	return 0;
}


void queuePrint(Queue* _queue)
{
int i;
	for(i=0;i<_queue->m_NumItems;i++)
	{
		printf("%d \n",_queue->m_Vec[(_queue->m_Head+i)%_queue->m_Size]);	
	}
		
}
/*
void queueMove(Queue* dst,Queue* src){

	while(!queueIsEmpty(src)){
		
	}
}
*/




