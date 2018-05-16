/**************************************************************************************
    Author :
    Creation date :      5.9.10
    Date last modified :
    Description : Queue Implementation.
***************************************************************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct Queue Queue;
 
Queue*      QueueCreate (void);
void        QueueDestroy(Queue*	_queue);

ADTErr    QueueInsert (Queue*	_queue, void*  _item);
void*       QueueRemove (Queue*	_queue);
int         QueueIsEmpty(Queue*	_queue);

void        QueuePrint  (Queue*	_queue, void(*_Print)(void*));

#endif /*__QUEUE_H__*/
