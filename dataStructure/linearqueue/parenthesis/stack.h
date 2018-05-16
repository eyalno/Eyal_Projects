#include "ADTDefs.h"

#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack* stackCreate(size_t _size, size_t _blockSize);

void stackDestroy(Stack* _stack);

ADTERR stackPush(Stack* _stack,int _item);

ADTERR stackPop(Stack* _stack,int* _item);

ADTERR stackTop(Stack* _stack,int* _item);

int stackIsEmpty(Stack* _stack);

void stackPrint(Stack* _stack);

int checkParenthesis(char *);

#endif
