/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list h file functions forward declerations
***********************************************************************/



#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node Node; 

Node* nodeCreate() ;
void listPushHead(Node* _list,int _data);
Node* reverse(Node* _node);
void listPrint(Node *_list);




#endif
