#include "ADTDefs.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>




Vector *VectorCreate(size_t _size,size_t _blockSize){

Vector* tmpV;

	if (!_size){
		return NULL;
	}

	if(!_blockSize){
		return NULL;
	}

	
	if (!(tmpV=(Vector* )malloc(sizeof(Vector)))){
		return NULL;
	}	

	if (!(tmpV->m_Array=(void**)malloc(sizeof(void*)*_size))){
		free(tmpV);	
		return NULL;		
	}

	tmpV->m_SizeArr= _size;
	tmpV->m_blockSize=_blockSize;
	tmpV->m_ItemsNum=0;

	return tmpV;
}

void VectorDestroy(Vector* _vec){

	if (_vec){
		free(_vec->m_Array);
		free(_vec);
	}
}

ADTErr VectorGet(Vector* _vec,size_t _index,void** _value){

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

ADTErr VectorSet(Vector *_vec,size_t _index,void * _value){

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

ADTErr VectorItemsNum(Vector* _vec,int* _itemsNum){

if (!_vec || !_itemsNum){
	return ERR_ALLOC_FAILED;
}

*_itemsNum=_vec->m_ItemsNum;
return ERR_OK;
}

ADTErr VectorAdd(Vector* _vec,void * _value){

void **tmp;

if (!_vec ){
	return ERR_ALLOC_FAILED;
}

if(_vec->m_ItemsNum == _vec->m_SizeArr){
	
	
	tmp=(void**)realloc(_vec->m_Array,(_vec->m_blockSize+_vec->m_SizeArr)*sizeof(void*));
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

ADTErr VectorRemove(Vector* _vec,void ** _value){

if (!_vec || !_value ){
	return ERR_ALLOC_FAILED;
}

*_value=_vec->m_Array[_vec->m_ItemsNum-1];

_vec->m_ItemsNum--;

return ERR_OK;
}


int VectorForEach(Vector*_vec,DoFunc _doFunc,void* _params)
{
	int i;
	
	for(i=0; i <_vec->m_ItemsNum;++i  )
	{
		_doFunc(_vec->m_Array[i],_params);

	}
	return 1;

}









