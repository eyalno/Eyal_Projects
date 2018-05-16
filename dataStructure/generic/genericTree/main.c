/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 31.10.12
		Description: Generic linked queue main function , functionality and test
		Text Editor:	    gVim
		File Type:  	    main.c File
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <string.h>

/*local libaries*/
#include "ADTDefs.h"
#include "tree.h"

typedef struct Person
{
	char *name;
	int age;
}Person;


int Compare(TreeData* _left, TreeData* _right)
{
	

	if (  *(int*)(_left)  > *(int*)(_right) )
	{
		return 1;
	}
	return 0;
	

}

void Int(void* _data)
{
	if (!_data)
	{
		return;
	}
		printf("%d ",*(int*)_data);
}

void Do(TreeData* _data,void* _para)
{
	*((int*)_data)+=*(int*)_para;
}

int main()
{

	Tree* tree;
	int a=5,b=7,c=6,d=3,e=8,f=1;
	
	

	/*create and destroy*/
	tree=TreeCreate(Compare);
	
	TreeDestroy(tree);
	tree=TreeCreate(Compare);
	
	/* empty tree*/
	TreeIsEmpty(tree)?puts("empty"):puts("not empty");
	
	/*insert and print*/
	TreeInsert(tree,&a);
	TreeInsert(tree,&b);
	TreeInsert(tree,&c);
	TreeInsert(tree,&d);
	TreeInsert(tree,&e);
	
	puts("the tree");
	TreePrint(tree,Int);
	
	/*remove 5*/
	puts("remove  5 case of 2 sons");
	TreeRemove(TreeFind(tree,&a));
	puts("the tree");	
	TreePrint(tree,Int);
	
	puts("remove  8 case  no sons");
	TreeRemove(TreeFind(tree,&e));
	puts("the tree");	
	TreePrint(tree,Int);
	TreeInsert(tree,&e);
	
	puts("remove  7 case  1 sons");
	TreeRemove(TreeFind(tree,&b));
	puts("the tree");	
	TreePrint(tree,Int);
	puts("the tree");	
	TreePrint(tree,Int);
	
	puts("check again is empty");	
	TreeIsEmpty(tree)?puts("empty"):puts("not empty");
	
	/*add 1 for each*/
	puts("add 1 for each in Order");
	TreeForEach(tree,IN_ORDER,Do,&f);
	puts("the tree");	
	TreePrint(tree,Int);
	
	/*add 1 for each*/
	puts("add 1 for each post Order");
	TreeForEach(tree,POST_ORDER,Do,&f);
	puts("the tree");	
	TreePrint(tree,Int);
	
	/*add 1 for each*/
	puts("add 1 for each ipre Order");
	TreeForEach(tree,PRE_ORDER,Do,&f);
	puts("the tree");	
	TreePrint(tree,Int);
	

	/*find  */
	puts("find:  should print 7");	
	Int(TreeGetData(TreeFind(tree,&c)));
	
	/*count*/
	printf("\nnumber of items: %d\n",TreeCount(tree));
	
	/*prev next*/
	puts("next prev to 7 ");
	Int(TreeGetData(TreeNext(TreeFind(tree,&c))));
	Int(TreeGetData(TreePrev(TreeFind(tree,&c))));
		
	puts("\nnext prev to 8 ");
	Int(TreeGetData(TreeNext(TreeFind(tree,&b))));
	Int(TreeGetData(TreePrev(TreeFind(tree,&b))));
	
	puts("\n begin print ");
	Int(TreeGetData(TreeBegin(tree)));
	
		
	puts("\n remove 9");
	TreeRemove(TreeFind(tree,&e));
	puts("the tree");	
	TreePrint(tree,Int);
	puts("");	
	
	
return 0;
}
