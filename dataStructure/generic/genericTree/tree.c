/************************************************************************

		Author: 	    Eyal Noy
		Creation date:      3.9.12
		Last modified date: 31.10.12
		Description:        Generic linked list implementation,
				    double linked list using stub functions implemented using void * 
				    for the generic data structure
		Text Editor:	    gVim
		File Type:  	    c File
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*local libaries*/
#include "ADTDefs.h"
#include "tree.h"
#include "stack.h"

#define PRINT _tree->m_root.m_sons[LEFT],_doFunc,params
struct Node
{
	TreeData* m_data;
	Node * m_parent;
	Node * m_sons[NUM_OF_SONS];
};

struct Tree
{
	Node m_root;
	IsLeftBigger m_isLeftBigger;
};

/*left node right node*/
enum{LEFT=0,RIGHT};

/*creates and initilize tree + stub */
Tree* TreeCreate(IsLeftBigger _isLeftBigger)
{
	Tree* tmpT;		
	int i;
	assert(_isLeftBigger);

	
	if(!( tmpT=(Tree*)malloc(sizeof(Tree))))
	{
		return NULL;
	}
		
	tmpT->m_isLeftBigger=_isLeftBigger;
	
	tmpT->m_root.m_parent = NULL;
	
	tmpT->m_root.m_data = (int*)0xdeadbeef;
	
	/*initilize all sons*/
	for (i=0; i < NUM_OF_SONS;++i)
	{
		tmpT->m_root.m_sons[i]=NULL;
	}
	
	return tmpT;
	
}


/* destroy tree recursivley post order */
static void DestroyRec(Node* _node)
{
	if(!_node)
	{
		return;
	}

	
	DestroyRec(_node->m_sons[LEFT]);
	DestroyRec(_node->m_sons[RIGHT]);
	free(_node);
}
 	

/*destroy tree bottom up*/
void TreeDestroy(Tree* _tree)
{
	
	
	assert(_tree);
	
	DestroyRec(_tree->m_root.m_sons[LEFT]);		
	
	free(_tree);
}

/* Find where to insert or locate recursivley. return parent */
static Node* Find(Node* _node ,TreeData* _data,IsLeftBigger _isLeftBigger)
{
	/* break! data found or found where to insert data*/
	/*1.equal*/
	/* 2. data bigger right node null*/ 
	/*3. data smaller left node null*/
	if ( (!_isLeftBigger(_node->m_data,_data) && !_isLeftBigger(_data,_node->m_data))
	 || (_isLeftBigger(_data,_node->m_data)  && !_node->m_sons[RIGHT]) 
	 || (_isLeftBigger(_node->m_data,_data) && !_node->m_sons[LEFT]))
	{
		return _node; 
	}
	
	/* recursion call return node right node / left node */
	return (_isLeftBigger(_data,_node->m_data)) ? 
	Find(_node->m_sons[RIGHT],_data,_isLeftBigger) : Find(_node->m_sons[LEFT],_data,_isLeftBigger);
} 

/*Find wrapper */
TreeItr TreeFind(Tree* _tree,TreeData* _data)
{
	assert(_tree);
	assert(_data);
	
	return Find(_tree->m_root.m_sons[LEFT],_data,_tree->m_isLeftBigger);
}

/* insert the new node and links to parent */
static void insert(Node* _node,TreeData* _data,Node * _parent)
{
		_node->m_data=_data;
		_node->m_sons[LEFT]=NULL;
		_node->m_sons[RIGHT]=NULL;
		_node->m_parent=_parent;
}

/*create and place data to head of tree*/
TreeItr TreeInsert(Tree* _tree,TreeData* _data)
{
	Node* found;
	Node* newNode;	

	assert(_tree);
	assert(_data);
	
	
	if (!(newNode=(Node*)malloc(sizeof(Node))))
	{
		return NULL;
		
	}
	
	/* first insert tree is empty*/
	if (!(_tree->m_root.m_sons[LEFT]))
	{
		_tree->m_root.m_sons[LEFT]=newNode;
		insert(newNode,_data,NULL);	
		return newNode;
	}
	
	/*find the item*/
	found=Find(_tree->m_root.m_sons[LEFT],_data,_tree->m_isLeftBigger);

	/*item found return iterator*/
	if (!_tree->m_isLeftBigger(found->m_data,_data) && !_tree->m_isLeftBigger(_data,found->m_data))
	{
		return found;
	}
	
	/*insert to location left or right */
	insert(newNode,_data,found);

	if(_tree->m_isLeftBigger(_data ,found->m_data))
	{
		found->m_sons[RIGHT]=newNode;
	}		
	else
	{
		found->m_sons[LEFT]=newNode;
	}
	return newNode;	
}


void PrintInOrder(Node* _node,PrintFunc _printFunc)
{
	if (!_node)
	{
		return;
	}
	PrintInOrder(_node->m_sons[LEFT],_printFunc);
	_printFunc(_node->m_data);
	PrintInOrder(_node->m_sons[RIGHT],_printFunc);
}

/*generic print function for all data types*/
void TreePrint(Tree* _tree,PrintFunc _printFunc)
{
	assert(_tree);
	assert(_printFunc);

	if(!_tree->m_root.m_sons[LEFT])
	{
		return;
	}
	
	PrintInOrder(_tree->m_root.m_sons[LEFT],_printFunc);	

	puts("");
}


/*count recursivly number of nodes*/
static void count(Node* _node,int *_counter)
{
	if (!_node)
	{
		return;
	}
	count(_node->m_sons[LEFT],_counter);
	++*_counter;
	count(_node->m_sons[RIGHT],_counter);


}

/*count the data*/
int TreeCount(Tree *_tree)
{
	int counter=0;
	assert(_tree);
	count(_tree->m_root.m_sons[LEFT],&counter);
	return counter;	
}

/*checks if the tree is empty*/
int TreeIsEmpty(Tree*_tree)
{
	assert(_tree);
	return (_tree->m_root.m_sons[LEFT]) ? 0:1; 
}

/*returns smallest item*/
static Node* begin(Node* _node)
{
	return (!_node->m_sons[LEFT])? _node: begin(_node->m_sons[LEFT]);
	
}
/*returns iterator of the first item in the tree if NULL*/
TreeItr TreeBegin(Tree* _tree)
{
	assert(_tree);
	
	return begin(&_tree->m_root);
}

/*returns stub */
TreeItr TreeEnd	(Tree* _tree)
{
	assert(_tree);
	return &_tree->m_root;
}

/*Down for next and prev, child is left or right*/
static Node* Down(Node* _node,int _child)
{
	
	 return ((!_node->m_sons[_child])?_node: Down(_node->m_sons[_child],_child));		
}

/*Up for next and prev, child is left or right*/
static Node* Up(Node* _node,int _child)
{
	/*return NULL if at top*/
	if(!_node->m_parent)
	{
		return NULL;
	}
	 return ( _node== _node->m_parent->m_sons[_child])? _node->m_parent: Up(_node->m_parent,_child);
}

/*returns the next iterator -first step right and minimum(left all the way) */
/*Up first parent with left son*/
TreeItr TreeNext (TreeItr _itr)
{
	assert(_itr);
	
	return ( _itr->m_sons[RIGHT] != NULL )?  Down(_itr->m_sons[RIGHT],LEFT): Up(_itr,LEFT);

}

/*symitricly to next. Returns the previous iterator- Down first step left and maximum(right all the way)*/
/*Up first parent with right son*/
TreeItr TreePrev (TreeItr _itr)
{
		
	assert(_itr);
	
	return ( _itr->m_sons[LEFT] != NULL )?  Down(_itr->m_sons[LEFT],RIGHT): Up(_itr,RIGHT);

}

/*retrieves the data in iterator*/
TreeData* TreeGetData(TreeItr _itr)
{
	
	return (_itr) ? _itr->m_data:NULL;
}



/*remove iterator and creates new links return the data*/
TreeData* TreeRemove(TreeItr _itr)
{
	TreeItr next;
	TreeData* tmp;

		
	
	/*both leaves NULL*/
	if (!_itr->m_sons[LEFT] && !_itr->m_sons[RIGHT])
	{
		/* checks which node of parent and link*/
		if (_itr->m_parent->m_sons[LEFT] == _itr)
		{
			_itr->m_parent->m_sons[LEFT]=NULL;
		}
		else
		{
			_itr->m_parent->m_sons[RIGHT]=NULL;
		}
		tmp=_itr->m_data;
		free(_itr);
		return tmp;
	}
	
	/* left son only */	
	if (_itr->m_sons[LEFT] && !_itr->m_sons[RIGHT])
	{
		/* checks which node of parent and link*/
		if (_itr->m_parent->m_sons[LEFT] == _itr)
		{
			_itr->m_parent->m_sons[LEFT]=_itr->m_sons[LEFT];
		}
		else
		{
			_itr->m_parent->m_sons[RIGHT]=_itr->m_sons[LEFT];
		}
		/*parent link*/
		_itr->m_sons[LEFT]->m_parent=_itr->m_parent;
		tmp=_itr->m_data;
		free(_itr);
		return tmp;
		
	}
	/* right son only*/	
	if (!_itr->m_sons[LEFT] && _itr->m_sons[RIGHT])
	{
		/* left son of parent*/
		if (_itr->m_parent->m_sons[LEFT] == _itr)
		{
			_itr->m_parent->m_sons[LEFT]=_itr->m_sons[RIGHT];
		}
		else
		{
			_itr->m_parent->m_sons[RIGHT]=_itr->m_sons[RIGHT];
		}
		/*parent link*/
		_itr->m_sons[RIGHT]->m_parent=_itr->m_parent;
		
		tmp=_itr->m_data;
		free(_itr);
		return tmp;
	}
	/*data swap and remove next*/
	next=TreeNext(_itr);	
	_itr->m_data=next->m_data;
	return TreeRemove(next);
	
}


static void printPreOrder(Node* _node, DoFunc _doFunc, void* _params)
{
	if (!_node)
	{
		return;
	}
	_doFunc(_node->m_data,_params);	
	printPreOrder(_node->m_sons[LEFT],_doFunc,_params);
	printPreOrder(_node->m_sons[RIGHT],_doFunc,_params);
}
/*iterative in order*/
static void printInOrder(Node* _node, DoFunc _doFunc, void* _params)
{
	Node * current=_node;
	Stack *stack=stackCreate(8,8);
	
	/*push and pop while stack isnt empty*/	
	while (stackIsEmpty(stack) || current) 
	{ 
		/*inorder going left and push to stack*/
		if (current) 
		{   
			stackPush(stack,current);
			current = current->m_sons[LEFT];     
		}
		/*pop from stack and print and go right*/
		else 
		{
			
			stackPop(stack,(void**)&current); 
			_doFunc(current->m_data,_params);			      
			current = current->m_sons[RIGHT];     
		 }  
	} 		
}

static void printPostOrder(Node* _node, DoFunc _doFunc, void* _params)
{
	if (!_node)
	{
		return;
	}
	printPostOrder(_node->m_sons[LEFT],_doFunc,_params);
	printPostOrder(_node->m_sons[RIGHT],_doFunc,_params);
	_doFunc(_node->m_data,_params);	
}

/*apply the function on data range*/
TreeItr TreeForEach(Tree* _tree, TraverseMode _travMode, DoFunc _doFunc, void* params)
{
	
	/* #define PRINT _tree->m_root.m_sons[LEFT],_doFunc,params*/
	switch(_travMode)
	{
	case PRE_ORDER:	
		printPreOrder(PRINT);
		break;
	case IN_ORDER:
		printInOrder(TreeBegin(_tree),_doFunc,params);
		break;
	case POST_ORDER:
		printPostOrder(PRINT);
		break;
	default:
		break;
	}
	return NULL;
}
