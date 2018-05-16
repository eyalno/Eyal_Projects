/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list h file functions forward declerations
***********************************************************************/



#ifndef LINKED_LIST_H
#define LINKED_LIST_H



typedef struct List List;

typedef struct Node
{
	int m_Data;
	struct Node * m_Next;
	struct Node * m_Prev;
}Node;

typedef struct TreeNode
{
	int m_Data;
	struct TreeNode * m_right;
	struct TreeNode * m_left;
}TreeNode;

struct List
{
	Node m_Head;
	Node m_Tail;
};

List* listCreate();

void listDestroy(List* _list);


ADTERR listPushHead(List* _list,int _data);
ADTERR listPushTail(List* _list,int _data);


TreeNode* List2Tree(Node* _list,int _listItemsNum);


int listPopHead(List *_list);
int listPopTail(List *_list);
int listCountItems(List *_list);

void listPrint(List* _list);


#endif
