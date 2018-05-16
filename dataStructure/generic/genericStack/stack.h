#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack* stackCreate(size_t _size, size_t _blockSize);

void stackDestroy(Stack* _stack);

ADTErr stackPush(Stack* _stack,void* _item);

ADTErr stackPop(Stack* _stack,void** _item);

ADTErr stackTop(Stack* _stack,void** _item);

int stackIsEmpty(Stack* _stack);

void stackPrint(Stack* _stack);


#endif
