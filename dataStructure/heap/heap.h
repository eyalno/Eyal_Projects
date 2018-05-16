#ifndef STACK_H
#define STACK_H

typedef struct  Heap Heap;

Heap* HeapBuild(Vector* _vec);

void HeapDestroy(Heap* _heap);

ADTERR HeapInsert(Heap* _heap,int _item);

ADTERR HeapMax(Heap* _heap,int* _item);

ADTERR HeapExtractMax(Heap* _heap,int* _item);

int HeapSize(Heap* _heap);

void HeapPrint(Heap* _heap);


#endif
