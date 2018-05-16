#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;

Queue* queueCreate(size_t _size); 

void queueDestroy(Queue* _queue);

ADTERR queueInsert(Queue* _queue,int _item);

ADTERR queueRemove(Queue* _queue,int* _item);

int queueIsEmpty(Queue* _queue);

void queuePrint(Queue* _queue);

/*
void queueMove(Queue*,Queue*);
*/

#endif
