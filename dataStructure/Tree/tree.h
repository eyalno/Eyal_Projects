/************************************************************************

		Author: Eyal Noy
		Creation date: 19.9.12
		Last modified date: 19.9.12
		Description: Tree data structure header file functions forward declerations
***********************************************************************/



#ifndef TREE_H
#define TREE_H


/* macro */
typedef struct Tree Tree;
/***********/


/*functions declerations */
Tree* treeCreate();

void treeDestroy(Tree* _tree);

ADTERR treeInsert(Tree* _tree,int _data);

bolean treeIsDataFound(Tree* _tree,int _data);

void treePrint(Tree* _tree,TraverseMode _travMode);
/**************************/

#endif
