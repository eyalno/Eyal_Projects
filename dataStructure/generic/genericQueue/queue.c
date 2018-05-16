/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: Generic linked list implementation,
			     double linked list using stub functions implemented using void * 
			     for the generic data structure
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*local libaries*/
#include "ADTDefs.h"
#include "linkedList.h"
#include "queue.h"

struct Queue
{
	List* m_List;
};

struct Node
{
	ListData* m_Data;
	struct Node * m_Next;
	struct Node * m_Prev;
};

struct List
{
	Node m_Head;
	Node m_Tail;
};

/*linked list wrapper queue*/
Queue* QueueCreate(void)
{
	return (Queue*)ListCreate();

}

/*destroy queue*/
void QueueDestroy (Queue *_queue)
{
	assert(_queue);
	ListDestroy((List*)_queue);
}

/* push to Head and pop from Tail will give us Queue*/
ADTErr QueueInsert(Queue * _queue, void* _item)
{
	assert(_queue);
	assert(_item);
	return ListPushHead((List*)_queue,_item);
	
}

/* push to Head and pop from Tail will give us Queue*/
void* QueueRemove (Queue *_queue)
{
	assert(_queue);
	return ListPopTail((List*)_queue);
}
/*check if queue is empty*/
int QueueIsEmpty(Queue *_queue)
{
	assert(_queue);
	
	return ListIsEmpty((List*)_queue);
}

/*print queue using the list print*/
void QueuePrint(Queue* _queue, void(*_Print)(void*))
{
	assert(_queue);
	assert(_Print);
	
	ListPrint((List*)_queue,_Print);

}



