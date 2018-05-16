/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
***********************************************************************/
/* standard libaries */
#include <stdio.h>

/*local libaries*/
#include "ADTDefs.h"
#include "linkedList.h"

void printPreOrder(TreeNode* _node)
{
	if (!_node)
	{
		return;
	}

	printf("%d ",_node->m_Data);
	printPreOrder(_node->m_left);
	printPreOrder(_node->m_right);
}

int main()
{
List* list;

/* functionality demonstration */
/*******************************/

 list=listCreate();


/* push Head*/

/*listPushHead(list,7);*/
listPushHead(list,6);
listPushHead(list,5);
listPushHead(list,4);

listPushHead(list,3);
listPushHead(list,2);
listPushHead(list,1);


puts("The List:");
listPrint(list);
printPreOrder(List2Tree(list->m_Head.m_Next,listCountItems(list)));








return 0;
}
