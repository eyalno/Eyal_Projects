/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list implementation
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*local libaries*/
#include "ADTDefs.h"
#include "linkedList.h"


typedef struct Node
{
	int m_Data;
	struct Node * m_Next;
	struct Node * m_Prev;
}Node;

struct List
{
	Node m_Head;
	Node m_Tail;
};

List* listCreate() 
{

List* tmpL;		

        if (!(tmpL=(List*)malloc(sizeof(List))))
	{
                return NULL;
        }
	
	
	tmpL->m_Head.m_Next=&tmpL->m_Tail;
	tmpL->m_Tail.m_Prev=&tmpL->m_Head;
        return tmpL;
}

void listDestroy(List* _list)
{
Node * tmp;
Node * loc;

	if (_list)
	{
		for(loc=_list->m_Head.m_Next;loc->m_Data != STUB;)
		{
			tmp=loc->m_Next;
			free(loc);
			loc=tmp;
		}
		free(_list);
	}
}

/* Creates node symitricly to head and tail */
ADTERR nodeCreate(Node * _prev,int _data)
{	
Node* tmp=(Node*)malloc(sizeof(Node));

	if(!tmp)
	{
		return ERR_ALLOC_FAILED;
	}
	
	tmp->m_Data=_data;
	
	tmp->m_Next=_prev->m_Next;
	_prev->m_Next->m_Prev=tmp;
	tmp->m_Prev=_prev;
	_prev->m_Next=tmp;		
return ERR_OK;
}


ADTERR listPushHead(List* _list,int _data)
{

	if (!_list )
	{
	        return ERR_ALLOC_FAILED;
	}
	
return nodeCreate(&_list->m_Head,_data);
}

ADTERR listPushTail(List* _list,int _data)
{

	if (!_list )
	{
	        return ERR_ALLOC_FAILED;
	}
return nodeCreate(_list->m_Tail.m_Prev,_data);
}


/* pop node symitricly to head and tail */
ADTERR pop(Node * _prev,int* _num)
{
Node *tmp;

if (!_prev || !_num)
{
	return ERR_NOTINITILIZED;
}

*_num=_prev->m_Next->m_Data;
tmp=_prev->m_Next;
_prev->m_Next=_prev->m_Next->m_Next;
_prev->m_Next->m_Prev=_prev;
free(tmp);
return ERR_OK;
}	


int listPopHead(List * _list)
{
int num;
	
	if (!_list )
	{
	        return ERR_ALLOC_FAILED;
	}

	if (_list->m_Head.m_Next->m_Data == STUB)
	{
		return ERR_INDEX_BOUNDRIES;
	}
	
	pop(&_list->m_Head,&num);
return num;	
}

int listPopTail(List * _list)
{
int num;
	
	if (!_list )
	{
	        return ERR_ALLOC_FAILED;
	}

	if (_list->m_Tail.m_Prev->m_Data == STUB)
	{
		return ERR_INDEX_BOUNDRIES;
	}

	pop(_list->m_Tail.m_Prev->m_Prev,&num);
	
return num;	
}

int listCountItems(List* _list)
{
int i;
Node *loc;
		if (!_list )
	{
	        return ERR_ALLOC_FAILED;
	}
	for(i=0,loc=_list->m_Head.m_Next; loc != &_list->m_Tail;loc=loc->m_Next,++i);
		
	return i;
}


void listPrint(List *_list)
{
Node *loc;
	for(loc=_list->m_Head.m_Next; loc != &_list->m_Tail;loc=loc->m_Next)
	{
		printf("%d\n",loc->m_Data);
	}
}
