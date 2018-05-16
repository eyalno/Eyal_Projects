#include "ADTDefs.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

struct Vector
{
int * m_Array;
size_t m_SizeArr;
size_t m_ItemsNum;
size_t m_blockSize; 
};



Vector *vectorCreate(size_t _size,size_t _blockSize){

Vector* tmpV;

	if (!_size){
		return NULL;
	}

	if(!_blockSize){
		return NULL;
	}

	
	if (!(tmpV=(Vector*)malloc(sizeof(Vector)))){
		return NULL;
	}	

	if (!(tmpV->m_Array=(int*)malloc(sizeof(int)*_size))){
		free(tmpV);	
		return NULL;		
	}

	tmpV->m_SizeArr= _size;
	tmpV->m_blockSize=_blockSize;
	tmpV->m_ItemsNum=0;

	return tmpV;
}

void vectorDestroy(Vector* _vec){

	if (_vec){
		free(_vec->m_Array);
		free(_vec);
	}
}

ADTERR vectorGet(Vector* _vec,size_t _index,int* _value){

	if (!_vec){
		return ERR_ALLOC_FAILED;
	}
	if (_index >= _vec->m_SizeArr){
		return ERR_OVERFLOW;
	}
	if (_index >= _vec->m_ItemsNum){
		return ERR_INDEX_BOUNDRIES;
	}
	
	if (!_value ){
		return ERR_NOTINITILIZED;
	}
	
	*_value=_vec->m_Array[_index]; 

return ERR_OK;
}

ADTERR vectorSet(Vector *_vec,size_t _index,int _value){

	if (!_vec){
		return ERR_ALLOC_FAILED;
	}
	if (_index >= _vec->m_SizeArr){
		return ERR_OVERFLOW;
	}
	if (_index >= _vec->m_ItemsNum){
		return ERR_INDEX_BOUNDRIES;
	}	

	_vec->m_Array[_index]=_value;

return ERR_OK;
}

ADTERR vectorItemsNum(Vector* _vec,int* _itemsNum){

if (!_vec || !_itemsNum){
	return ERR_ALLOC_FAILED;
}

*_itemsNum=_vec->m_ItemsNum;
return ERR_OK;
}

ADTERR vectorAdd(Vector* _vec,int _value){

int *tmp;

if (!_vec ){
	return ERR_ALLOC_FAILED;
}

if(_vec->m_ItemsNum == _vec->m_SizeArr){
	
	
	tmp=(int*)realloc(_vec->m_Array,(_vec->m_blockSize+_vec->m_SizeArr)*sizeof(int));
	if(!tmp)
	{
		return ERR_REALLOC_FAILED;
	}
	_vec->m_Array=tmp;
	_vec->m_SizeArr+=_vec->m_blockSize;
}
	_vec->m_Array[_vec->m_ItemsNum]=_value;
	_vec->m_ItemsNum++;

return ERR_OK;
}

ADTERR vectorRemove(Vector* _vec,int* _value){

if (!_vec || !_value ){
	return ERR_ALLOC_FAILED;
}

*_value=_vec->m_Array[_vec->m_ItemsNum-1];

_vec->m_ItemsNum--;

return ERR_OK;
}


void printVector(Vector* _vec){
int i;
	for(i=0;i<_vec->m_ItemsNum;i++)
		printf("[%d]",i);
	puts("");
	for(i=0;i<_vec->m_ItemsNum;i++)
		printf("[%d]",_vec->m_Array[i]);
	
	puts("");
	puts("");
}









