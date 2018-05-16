/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 5.11.12
		Description: Generic Hash implementation using array of linked lists
			     Generic key Generic data the implementation relies on linked list API
		Text Editor:  gVim
***********************************************************************/



/* standard libaries */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*local libaries*/
#include "ADTDefs.h"
#include "hash.h"
#include "linkedList.h"
#include "logger.h"

struct HashMap
{
	List** m_hashTable;
	size_t m_size;
	HashFunc m_func;
	IsEqualFunc m_isEqual;
	
};

/* cell in the array contain the data */
typedef struct Pair
{
	HashKey* m_key;
	HashData* m_data;
}Pair;





/* create hash map and initilize the allocated hash with the parameter free bottom up if allocation failed */
HashMap* HashCreate(size_t _size,HashFunc _hFunc,IsEqualFunc _isEqual)
{
	HashMap* map;
	int i;
	int j;
		
	assert(_size);
	assert(_hFunc);
	assert(_isEqual);	

	
	if(!(map=(HashMap*)malloc(sizeof(HashMap))))
	{
		return NULL;
	}
			
	if(!(map->m_hashTable = (List**)malloc(_size*sizeof(List*))))
	{
		free(map);
		return NULL;
	}
	
	for( i=0 ; i < _size; ++i)
	{
		if(!(map->m_hashTable[i] = ListCreate()))
		{
			for(j=0;j<i;++j)
			{
				ListDestroy(map->m_hashTable[j]);
			}
			
			free(map->m_hashTable);
			free(map);
			return NULL;
		}
	}
	
	/* initlize parameters */
	map->m_size = _size;
	map->m_func = _hFunc;
	map->m_isEqual = _isEqual;
	
	LogRegister(ERR,"Create succesfully","hash.c","hash create");
	return map;
}

/*destroy hash map deallocate bottom up */ 
void HashDestroy(HashMap* _hash)
{
	int j;
	List* list;
	ListItr node;
	assert(_hash);
	
	for(j=0;j < _hash->m_size ;++j)
	{
		list=_hash->m_hashTable[j];
		node=ListBegin(list);
	
	/*all the data in all list */
		while(node !=ListEnd(list))
		{
			free(ListGetData(node));
			
			node=ListNext(node);		
		}	
		ListDestroy(list);
	}

	free(_hash->m_hashTable);
	free(_hash);
	
	LogRegister(ERR,"Destroy succesfully","hash.c","hash destroyed");
	
}

/*insert the data to hash after decrypt the position using the key */
ADTErr HashInsert(HashMap* _hash,HashKey* _key,HashData* _data)	
{
	int index;
	Pair* pair; 
	
	assert(_hash);
	assert(_key);
	assert(_data);
	
	if(!(pair=(Pair*)malloc(sizeof(Pair))))
	{
		return ERR_ALLOC_FAILED;
	}
	
	/*insert data to struct*/
	pair->m_key=_key;
	pair->m_data=_data;
	
	/*decryprt index*/
	index = _hash->m_func( _key , _hash->m_size);
	
	/*push andreturn err code */
	LogRegister(ERR,"Insert succesfully","hash.c","hash insert");
	return	ListPushHead (_hash->m_hashTable[index],pair);

}


/*remove the data from hash after decrypt the position using the key using list API */
HashData* HashRemove(HashMap* _hash,HashKey* _key)
{
	int index;
	List* list;
	ListItr node;
	HashData* tmp;
	Pair* tmpP;

	assert (_hash);
	assert (_key);

	/*decryprt index*/
	index = _hash->m_func( _key , _hash->m_size);
	list=_hash->m_hashTable[index];
	node=ListBegin(list);
	
	/*searches the data in all list */
	while(node !=ListEnd(list))
	{
		/*return only data delete pair*/
		if (_hash->m_isEqual(((Pair*)ListGetData(node))->m_key,_key))
		{		
			tmpP=ListRemove(node);
			tmp=((Pair*)tmpP)->m_data;
			free(tmpP);
			return tmp;
		}
		node=ListNext(node);		
	}	
	LogRegister(ERR,"remove succesfully","hash.c","hash remove");
	return NULL;	

}

/*search for the data in all lists*/
HashData* HashFind(HashMap* _hash,HashKey* _key)
{
	
	int index;
	List* list;
	ListItr  node;

	assert (_hash);
	assert (_key);
	
	/*decryprt index*/
	index = _hash->m_func( _key , _hash->m_size);
	list=_hash->m_hashTable[index];
	node=ListBegin(list);
	
	while(node !=ListEnd(list))
	{
		if (_hash->m_isEqual(((Pair*)ListGetData(node))->m_key,_key))
		{				
			return ListGetData(node);
		}
		node=ListNext(node);		
	}	
	return NULL;	
	
}

/*returns the number of items in hash go through all lists*/ 
size_t HashCountItems(HashMap* _hash)
{
	int i,counter=0;

	assert (_hash);
	
	/*outer loop all lists*/
	for (i=0; i < _hash->m_size; ++i)
	{
		counter += ListCountItems(_hash->m_hashTable[i]);
			
	}	
	LogRegister(ERR,"size of items","hash.c","hashCountItems");
	return counter;
}

/*each list is referred as a bucket so counts all lists */
size_t HashCountEmptyBackets(HashMap* _hash)
{
	
	int i,counter=0;

	assert (_hash);

	for (i=0; i< _hash->m_size; ++i)
	{
		if(ListIsEmpty(_hash->m_hashTable[i])) 
		{
			++counter;
		}
	}
	LogRegister(ERR,"num Empty buckets","hash.c","hashEmpty buckets");
	
	return counter;
}

/*apply the _doFunc on all items in hash*/
int HashForEach(HashMap* _hash,DoFuncHash _doFunc,void* _params)
{

	int i;
	List* list;
	ListItr  node;


	assert(_hash);
	assert(_doFunc);
	assert(_params);
	
	/*outer loop all lists*/
	for (i=0; i < _hash->m_size; ++i)
	{
		list=_hash->m_hashTable[i];
		node=ListBegin(list);
		
		while(node !=ListEnd(list))
		{
			/*inner loop all nodes in list*/
			_doFunc(((Pair*)ListGetData(node))->m_key,((Pair*)ListGetData(node))->m_data,NULL);	
			node=ListNext(node);		
		}	
	}	
	LogRegister(ERR,"hash for each call","hash.c","hashForEach");
	return 1;	
}



