#include "ADTDefs.h"
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "stack.h"
#include <stdlib.h>

struct  Stack
{
	Vector* m_Vec;
};



Stack* stackCreate(size_t _size, size_t _blockSize){
	Stack* tmp=(Stack*)malloc(sizeof(Stack));
	if (!tmp){
		return NULL;
	}
	tmp->m_Vec= vectorCreate(_size,_blockSize);
	return tmp;
}

void stackDestroy(Stack* _stack){
	vectorDestroy(_stack->m_Vec);
}

ADTERR stackPush(Stack* _stack,int _item){
	return vectorAdd(_stack->m_Vec,_item);

}

ADTERR stackPop(Stack* _stack,int* _item){
	return vectorRemove(_stack->m_Vec,_item);
}

ADTERR stackTop(Stack* _stack,int* _item){
	return vectorGet(_stack->m_Vec,_stack->m_Vec->m_ItemsNum,_item);
}

int stackIsEmpty(Stack* _stack){
	if(_stack->m_Vec->m_ItemsNum){
		return 1;
	}
	return 0;
}


void stackPrint(Stack* _stack){

	printVector(_stack->m_Vec);
		
}







