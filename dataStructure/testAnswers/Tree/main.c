/************************************************************************

		Author: Eyal Noy
		Creation date: 19.9.12
		Last modified date: 19.9.12
		Description: Tree data structure main function , functionality and test
***********************************************************************/
/* standard libaries */
#include <stdio.h>

/*local libaries*/
#include "ADTDefs.h"
#include "Tree.h"

int main()
{
	Tree * tree1=treeCreate(),*tree2=treeCreate();
	int i;

	for (i=1; i<10;++i)
	{
		treeInsert(tree1,(i*2+2)%5);
		treeInsert(tree2,(i*2+2)%5);
	}

	if (AreSimilair(tree1->m_Root,tree2->m_Root))
	{
		puts("Similar");
	}
	else
	{
		puts("Not Similar");
	
	}

		treeInsert(tree2,7);
	
	if (AreSimilair(tree1->m_Root,tree2->m_Root))
	{
		puts("Similar");
	}
	else
	{
		puts("Not Similar");
	
	}



/* functionality demonstration */
/*******************************/
#ifdef DEMO

/* Create struture */
tree=treeCreate();

/* Insert to tree */

treeInsert(tree,6);
treeInsert(tree,7);
treeInsert(tree,9);
treeInsert(tree,8);
treeInsert(tree,2);
treeInsert(tree,1);
treeInsert(tree,4);
treeInsert(tree,3);
treeInsert(tree,5);

/* Is data found*/
puts("Search 3");

(treeIsDataFound(tree,3)) ? puts("found"):puts("Not found");

puts("Search 12");
(treeIsDataFound(tree,12)) ? puts("found") : puts("Not found");

/* print pre in post*/

puts("Pre order:");
treePrint(tree,PRE_ORDER);

puts("\nIn order");
treePrint(tree,IN_ORDER);

puts("\nPost order");
treePrint(tree,POST_ORDER);

puts("");


/* free structure */ 
treeDestroy(tree);

#endif



/*Unit-Test                  */
/****************************/

#ifdef UTEST

/* Uni-test function treeCreate*/
/*fail to allocate  */
if (!treeCreate())
{
	handleError(ERR_ALLOC_FAILED,NULL);
}



/* Uni-test function insert*/

/*fail initilize */

	handleError(treeInsert(NULL,0),NULL);

/*first insert */
	tree=treeCreate();
	handleError(treeInsert(tree,1),NULL);

	treePrint(tree,POST_ORDER);

/*Duplicate item*/
	handleError(treeInsert(tree,1),NULL);



#endif

return 0;
}
