/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: Generic linked list implementation,
			     double linked list using stub functions implemented using void * 
			     for the generic data structure
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*local libaries*/
#include "ADTDefs.h"
#include "linkedList.h"


struct Node
{
	ListData* m_Data;
	struct Node * m_Next;
	struct Node * m_Prev;
};

struct List
{
	Node m_Head;
	Node m_Tail;
};

/*creates and initilize list + stub */
List* ListCreate() 
{

	List* tmpL;		
	tmpL=(List*)malloc(sizeof(List));
        assert(tmpL);
		
	tmpL->m_Head.m_Next=&tmpL->m_Tail;
	tmpL->m_Tail.m_Prev=&tmpL->m_Head;
	tmpL->m_Head.m_Data = (int*)STUB;
	tmpL->m_Tail.m_Data = (int*)STUB;
	tmpL->m_Head.m_Prev=NULL;        
	tmpL->m_Tail.m_Next=NULL;        
	return tmpL;
}

/*destroy linked list bottom up*/
void ListDestroy(List* _list)
{
	Node * tmp;
	Node * loc;

	assert(_list);

	if (_list)
	{
		for(loc=_list->m_Head.m_Next;loc->m_Data != (int*)STUB;)
		{
			tmp=loc->m_Next;
			free(loc);
			loc=tmp;
		}
		free(_list);
	}
}

/* Creates node symitricly to head and tail */
ADTErr NodeCreate(Node * _prev,ListData* _data)
{	
	Node* tmp=(Node*)malloc(sizeof(Node));

	if (!tmp)
	{
		return ERR_ALLOC_FAILED;
	}	
	
	/* the new links*/
	tmp->m_Data=_data;
	
	tmp->m_Next=_prev->m_Next;
	_prev->m_Next->m_Prev=tmp;
	tmp->m_Prev=_prev;
	_prev->m_Next=tmp;		
	return ERR_OK;
}

/*create and place data to head of list*/
ADTErr ListPushHead(List* _list,ListData* _data)
{
	if (!_list || !_data)
	{
		return ERR_NOTINITILIZED;
	}

	return NodeCreate(&_list->m_Head,_data);
}

/*create and place data to tail of list*/
ADTErr ListPushTail(List* _list,ListData* _data)
{	
	if (!_list || !_data)
	{
		return ERR_NOTINITILIZED;
	}
	
	return NodeCreate(_list->m_Tail.m_Prev,_data);
}

/* auxiliry func pop node symmetrically to head and tail */
ADTErr Pop(Node * _prev,ListData** _num)
{
	Node *tmp;


	/* the new links*/
	*_num=_prev->m_Next->m_Data;
	tmp=_prev->m_Next;
	_prev->m_Next=_prev->m_Next->m_Next;
	_prev->m_Next->m_Prev=_prev;
	free(tmp);
	return ERR_OK;
}	

/*retrieves the the head data*/
ListData* ListPopHead(List * _list)
{
	ListData* num;

	assert(_list);

	
	
	if (_list->m_Head.m_Next->m_Data == (int*)STUB)
	{
		return NULL;
	}
	
	Pop(&_list->m_Head,&num);
	return num;	
}

/*retrieves the the tail data*/
ListData* ListPopTail(List * _list)
{
	ListData* num;
	
	assert(_list);

	if (ListIsEmpty(_list))
	{
		return NULL;
	}

	Pop(_list->m_Tail.m_Prev->m_Prev,&num);
	
	return num;	
}

/*count the data*/
size_t ListCountItems(List* _list)
{
	int i;
	Node *loc;
	
	if (!_list)
	{
		return 0;
	}	
	for(i=0,loc=_list->m_Head.m_Next; loc != &_list->m_Tail;loc=loc->m_Next,++i);
		
	return i;
}

/*checks if the list is empty*/
int ListIsEmpty(List*_list)
{
	assert(_list);

	return (_list->m_Head.m_Next == &_list->m_Tail) ? TRUE : FALSE;

}

/*generic print function for all data types*/
void ListPrint(List* _list,PrintFunc _printFunc)
{
	Node *loc;
	
	
	for(loc=_list->m_Head.m_Next; loc != &_list->m_Tail;loc=loc->m_Next)
	{
		_printFunc(loc->m_Data);
	}
	puts("");
}


/*returns iterator of the first item in the list tail if NULL*/
ListItr ListBegin(List* _list)
{
	return _list->m_Head.m_Next; 
}

/*returns iterator of tail*/
ListItr ListEnd	(List* _list)
{
	
	return ListIsEmpty(_list)? &_list->m_Head:_list->m_Tail.m_Prev;	
}

/*returns the next iterator */
ListItr ListNext (ListItr _itr)
{
	return _itr->m_Next;
}

/*returns the previous iterator*/
ListItr ListPrev (ListItr _itr)
{
	/*first item in list extreme case*/
	if(!_itr->m_Prev->m_Prev)
	{
		return NULL;
	}
	
	return _itr->m_Prev;
}

/*retrieves the data in iterator*/
ListData* ListGetData(ListItr _itr)
{	
	return _itr->m_Data;
}

/*insert item before the iterator*/
ListItr ListInsertBefore(ListItr _itr,ListData* _data)
{
	NodeCreate(_itr->m_Prev,_data);
	return _itr->m_Prev;	
}

/*search in the given range returns the iterator found*/
ListItr ListFindFirst(ListItr _from, ListItr _to, CompFunc _compFunc, ListData* _data)
{
	while(_from !=_to)
	{
		if(_compFunc(_from->m_Data,_data))
		{
			break;
		}
		_from = _from->m_Next;
	}

	return _from;
}

/*remove iterator and creates new links return the data*/
ListData* ListRemove(ListItr _itr)
{
	ListData* tmp;
	Pop(_itr->m_Prev,&tmp);
	
	return tmp;	
}

/*apply the function on data range*/
ListItr ListForEach(ListItr _from, ListItr _to, DoFunc _doFunc, void* _params)
{
	ListItr tmp=_from;
	while(tmp !=_to)
	{
		_doFunc(tmp->m_Data, _params);
		tmp = tmp->m_Next;
	}

	return _to;

}
