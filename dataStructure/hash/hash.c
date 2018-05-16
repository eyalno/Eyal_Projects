#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "ADTDefs.h"

/*satistical precentage when the array should not be filled */
static const float limit =0.70;

/* cell in the array contain the data */
typedef struct Pair
{
	int m_key;
	int* m_data;/*do not free*/
} Pair;

/*struct hash contatins data + parameters */ 
struct HashMap
{
	HF m_func;
	size_t m_count;
	Pair* m_array;
	size_t m_arraySize;
};

/* create hash map and initilize i witht he func and size */
HashMap* HashMapCreate(HF _func,size_t _size)
{
	HashMap* map;
	
	/* general tests */
	if (!_func || !_size)
	{
		return NULL;
	}

	if(!(map=(HashMap*)malloc(sizeof(HashMap))))
	{
		return NULL;
	}
	
	if(!(map->m_array=(Pair*)calloc(_size,sizeof(Pair))))
	{
		return NULL;
	}
	
	
	/* initlize parameters */
	map->m_arraySize=_size;
	map->m_func=_func;
	map->m_count = 0;
return map;

}

/*destroy hash map */ 
void HashMapDestroy(HashMap* _hash)
{
	if(!_hash)
	{
		return;
	}
	
	free(_hash->m_array);
	free(_hash);
}

/*insert the data to hash after decrypt the position using the key */
ADTERR HashMapInsert(HashMap* _hash,int _key,int * _data)
{
	int index;
	
	/* general tests */
	if (!_hash)
	{
		return ERR_NOTINITILIZED;	
	}
	
	index=_hash->m_func(_key);
	
	if (index >= _hash->m_arraySize)
	{
		return ERR_INDEX_BOUNDRIES;
	}

	if(!_data)
	{
		return ERR_NOTINITILIZED;	
	}

	/* search for avilable place */	
	while(_hash->m_array[index].m_data)
	{
		++index;
	}	
	
	/* insert data */
	_hash->m_array[index].m_data=_data;
	_hash->m_array[index].m_key=_key;
	++_hash->m_count;
	return ERR_OK;
}

/*remove the data to hash after decrypt the position using the key */
ADTERR HashMapRemove(HashMap* _hash,const int _key,int * _data)
{
	int index;
	
	/* general tests */
	if (!_hash)
	{
		return ERR_NOTINITILIZED;	
	}
	
	index=_hash->m_func(_key);
	
	if (index >= _hash->m_arraySize)
	{
		return ERR_INDEX_BOUNDRIES;
	}

	if(!_data)
	{
		return ERR_NOTINITILIZED;	
	}
	/* search what to remove */
	while(_hash->m_array[index].m_data)
	{
		++index;
	}	
	
	/* remove data */
	_data = _hash->m_array[index].m_data;
	_hash->m_array[index].m_data=0;
	--_hash->m_count;
	return ERR_OK;
}

/*retreive the data to hash after decrypt the position using the key */
ADTERR HashMapGetValueByKey(HashMap* _hash,const int _key,int * _data)
{
	int index=_hash->m_func(_key);
	
	/* general tests */
	if (!_hash)
	{
		return ERR_NOTINITILIZED;	
	}

	if (index >= _hash->m_arraySize)
	{
		return ERR_INDEX_BOUNDRIES;
	}

	if(!_data)
	{
		return ERR_NOTINITILIZED;	
	}

	_data = _hash->m_array[index].m_data;
	return ERR_OK;
}

size_t HashMapSize(HashMap* _hash)
{
	if (_hash)
	{
		return 0;
	}
	return _hash->m_count;
}

#ifdef _DEBUG
void HashMapPrint(HashMap* _hash)
{
	int i;
	puts("The hash:");
	for (i=0;i<_hash->m_arraySize;++i)
	{
		if(_hash->m_array[i].m_data)
		{
			printf("key:%d    data:%d\n", _hash->m_array[i].m_key,*_hash->m_array[i].m_data);
		}
	}
}
#endif






