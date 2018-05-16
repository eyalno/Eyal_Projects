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

int main()
{
List* list;

/* functionality demonstration */
/*******************************/

 list=listCreate();

/* push Head*/

listPushHead(list,1);
listPushHead(list,2);
listPushHead(list,3);
puts("The List:");
listPrint(list);

/* push tail*/

listPushTail(list,1);
listPushTail(list,2);
listPushTail(list,3);
puts("The List:");
listPrint(list);

/* counting items*/
puts("Number of Items:");
printf("%d\n",listCountItems(list));


/* pop head and tail*/

listPopTail(list);
listPopHead(list);
puts("The List:");

listPrint(list);



/*Uni-Test                  */
/****************************/

/* Uni-test function listCreate*/
/*fail to allocate  */
if (!listCreate())
{
	handleError(ERR_ALLOC_FAILED,NULL);
}



/* Uni-test function listPushTail\Head*/
/*fail initilize */


	handleError(listPushTail(NULL,4),NULL);
	handleError(listPushHead(NULL,4),NULL);

/* Uni-test function listPopHead\Tail*/
/*fail initilize */

	handleError(listPopHead(NULL),NULL);
	handleError(listPopTail(NULL),NULL);

/*fail boundries*/
list=listCreate();
	handleError(listPopHead(list),NULL);
	handleError(listPopTail(list),NULL);



return 0;
}
