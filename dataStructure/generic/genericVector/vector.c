/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: generic vector implementation
		Text Editor:  gVim
***********************************************************************/



/* standard libaries */
#include "ADTDefs.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

/*local libaries*/


struct Vector
{
	void ** m_Array;
	size_t m_SizeArr;
	size_t m_ItemsNum;
	size_t m_blockSize; 
};


/*creates vector args initial size and block to realloc*/
Vector *VectorCreate(size_t _size,size_t _blockSize)
{

	Vector* tmpV;

	/*error checks*/
	if (!_size)
	{
		return NULL;
	}

	if(!_blockSize)
	{
		return NULL;
	}

	
	if (!(tmpV=(Vector* )malloc(sizeof(Vector))))
	{
		return NULL;
	}	

	if (!(tmpV->m_Array=(void**)malloc(sizeof(void*)*_size)))
	{
		free(tmpV);	
		return NULL;		
	}

	/*initilize vector*/
	tmpV->m_SizeArr= _size;
	tmpV->m_blockSize=_blockSize;
	tmpV->m_ItemsNum=0;

	return tmpV;
}

/*free vector and allocated memory*/
void VectorDestroy(Vector* _vec)
{

	if (_vec)
	{
		free(_vec->m_Array);
		free(_vec);
	}
}

/*retrieves the generic data from the vector*/
ADTErr VectorGet(Vector* _vec,size_t _index,void** _value)
{
	/*check errors*/
	if (!_vec)
	{
		return ERR_ALLOC_FAILED;
	}
	
	if (_index >= _vec->m_SizeArr)
	{
		return ERR_OVERFLOW;
	}
	
	if (_index >= _vec->m_ItemsNum)
	{
		return ERR_INDEX_BOUNDRIES;
	}
	
	if (!_value )
	{
		return ERR_NOTINITILIZED;
	}
	
	*_value=_vec->m_Array[_index]; 

	return ERR_OK;
}

/*set new data in the vector*/
ADTErr VectorSet(Vector *_vec,size_t _index,void * _value)
{

	/*check errors*/
	if (!_vec)
	{
		return ERR_ALLOC_FAILED;
	}
	
	if (_index >= _vec->m_SizeArr)
	{
		return ERR_OVERFLOW;
	}
	
	if (_index >= _vec->m_ItemsNum)
	{
		return ERR_INDEX_BOUNDRIES;
	}	

	_vec->m_Array[_index]=_value;

	return ERR_OK;
}

/*returns number of items in vector*/
ADTErr VectorItemsNum(Vector* _vec,int* _itemsNum)
{

	if (!_vec || !_itemsNum)
	{
		return ERR_ALLOC_FAILED;
	}

	*_itemsNum=_vec->m_ItemsNum;
	return ERR_OK;
}


/*add data to the end of vector*/
ADTErr VectorAdd(Vector* _vec,void * _value)
{

	void **tmp;

	if (!_vec )
	{
		return ERR_ALLOC_FAILED;
	}
	
	/*reallocate if short*/
	if(_vec->m_ItemsNum == _vec->m_SizeArr)
	{
	
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

/*remove data from vector*/
ADTErr VectorRemove(Vector* _vec,void ** _value)
{

	if (!_vec || !_value )
	{
		return ERR_ALLOC_FAILED;
	}

	*_value=_vec->m_Array[_vec->m_ItemsNum-1];

	_vec->m_ItemsNum--;

	return ERR_OK;
}


/*go through all vector and implement the function on data*/
int VectorForEach(Vector*_vec,DoFunc _doFunc,void* _params)
{
	int i;
	
	for(i=0; i <_vec->m_ItemsNum;++i  )
	{
		_doFunc(_vec->m_Array[i],_params);

	}
	return 1;

}









