#include "ADTDefs.h"
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "stack.h"
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

struct  Stack
{
	Vector* m_Vec;
};



Stack* stackCreate(size_t _size, size_t _blockSize){
	
	return (Stack *)vectorCreate(_size,_blockSize);;
}

void stackDestroy(Stack* _stack){
	vectorDestroy((Vector*)_stack);
}

ADTERR stackPush(Stack* _stack,int _item){
	return vectorAdd((Vector*)_stack,_item);

}

ADTERR stackPop(Stack* _stack,int* _item){
	return vectorRemove((Vector*)_stack,_item);
}

ADTERR stackTop(Stack* _stack,int* _item){
	return vectorGet((Vector*)_stack,((Vector*)_stack)->m_ItemsNum,_item);
}

int stackIsEmpty(Stack* _stack){
	
	return((Vector*)_stack)->m_ItemsNum ? TRUE:FALSE;
}


void stackPrint(Stack* _stack){

	printVector((Vector*)_stack);
		
}







