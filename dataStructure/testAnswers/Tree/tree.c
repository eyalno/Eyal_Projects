/************************************************************************

		Author: Eyal Noy
		Creation date: 19.9.12
		Last modified date: 19.9.12
		Description: Tree data structure implementation
***********************************************************************/

/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*local libaries*/
#include "ADTDefs.h"
#include "Tree.h"

/* structs declerations */
 struct Node
{
	int m_Data;
	struct Node * m_Right;
	struct Node * m_Left;
	struct Node * m_Parent;
	
};



/* functions  */

/* create tree struct */
Tree* treeCreate() 
{

Tree* tmpT;		

        if (!(tmpT=(Tree*)malloc(sizeof(Tree))))
	{
                return NULL;
        }
	
	tmpT->m_Root=NULL;	
	
        return tmpT;
}

/* destroy tree recursivley post order */
void destroyRec(Node* _node)
{
	if(!_node)
	{
		return;
	}

	
	destroyRec(_node->m_Left);
	destroyRec(_node->m_Right);
	free(_node);
}
 	
/* client destroy tree */ 
void treeDestroy(Tree* _tree)
{

	if (!_tree)
	{
		return;
	}
	
	if (!_tree->m_Root)
	{
		return;
	}
	
	destroyRec(_tree->m_Root);	

}

/* find where to insert or locate recursivley return parent */
Node* find(Node* _node ,int _data)
{
	/* break! data found or found where to insert data*/
	if (_node->m_Data == _data || (_node->m_Data < _data && !_node->m_Right) || (_node->m_Data > _data && !_node->m_Left))
	{
		return _node; 
	}
	/* recursion call return node */
	return (_data <_node->m_Data) ? find(_node->m_Left,_data) : find(_node->m_Right,_data);
} 
/* insert the new node and links to parent */
void insert(Node* _node,int _data,Node * _parent)
{
		_node->m_Data=_data;
		_node->m_Left=NULL;
		_node->m_Right=NULL;
		_node->m_Parent=_parent;
}


/* insert  */
ADTERR treeInsert(Tree* _tree,int _data)
{	
Node* found;
Node* newNode;
	
	
	if(!_tree)
	{
		return ERR_NOTINITILIZED;
	}
	
	if (!(newNode=(Node*)malloc(sizeof(Node))))
	{
		return ERR_NOTINITILIZED;
		
	}
	/* first insert */
	if (!_tree->m_Root)
	{
		_tree->m_Root=newNode;
		insert(newNode,_data,NULL);	
		return ERR_OK;
	}
	
	found=find(_tree->m_Root,_data);

	if(_data == found->m_Data)
	{
		return ERR_DUPLICATE_ITEM;
	}
	
	/*insert left or right */
	insert(newNode,_data,found);

	if(_data > found->m_Data)
	{
		found->m_Right=newNode;
	}		
	else
	{
		found->m_Left=newNode;
	}
	
		
return ERR_OK;
}

bolean treeIsDataFound(Tree* _tree,int _data)
{
Node *found;
	
	found=find(_tree->m_Root,_data);
	
	return (found->m_Data == _data) ? TRUE:FALSE;  
}

void printPreOrder(Node* _node)
{
	if (!_node)
	{
		return;
	}

	printf("%d ",_node->m_Data);
	printPreOrder(_node->m_Left);
	printPreOrder(_node->m_Right);
}

void printInOrder(Node* _node)
{
	if (!_node)
	{
		return;
	}
	printInOrder(_node->m_Left);
	printf("%d ",_node->m_Data);
	printInOrder(_node->m_Right);
}

void printPostOrder(Node* _node)
{
	if (!_node)
	{
		return;
	}
	printPostOrder(_node->m_Left);
	printPostOrder(_node->m_Right);
	printf("%d ",_node->m_Data);
}


void treePrint(Tree* _tree,TraverseMode _travMode)
{
	switch(_travMode)
	{
	case PRE_ORDER:
		printPreOrder(_tree->m_Root);
		break;
	case IN_ORDER:
		printInOrder(_tree->m_Root);
		break;
	case POST_ORDER:
		printPostOrder(_tree->m_Root);
		break;
	default:
		break;
	}
}


int AreSimilair(Node* _root1, Node* _root2)
{
	if ((!_root1 && _root2 )|| (_root1 && !_root2 ))
	{
		return 0;
	}
	
	if (!_root1 && !_root2 )
	{
		return 1;
	}
	
	return (AreSimilair(_root1->m_Left,_root2->m_Left) && AreSimilair(_root1->m_Right,_root2->m_Right));
}

