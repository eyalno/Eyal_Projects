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


struct Node 
{
	Node * m_Next;
	int m_Data;
};


Node* nodeCreate() 
{

Node* tmpL;		

        if (!(tmpL=(Node*)malloc(sizeof(Node))))
		{
                return NULL;
        }
	
	
		tmpL->m_Next=NULL;
        return tmpL;
}

void listPushHead(Node* _list,int _data)
{

	
	
	_list->m_Next=nodeCreate();
}

Node* reverse(Node* _node)
{
        Node *tmp=_node->m_Next;
        Node *head;
        if(!_node->m_Next)
        {
                return _node;
        }

        head=reverse(_node->m_Next);
        tmp->m_Next=_node;
        return head;

}


void listPrint(Node *_list)
{
Node *loc;
	for(loc=_list; loc ;loc=loc->m_Next)
	{
		printf("%d\n",loc->m_Data);
	}
}
