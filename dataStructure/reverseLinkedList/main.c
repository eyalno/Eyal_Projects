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


/* functionality demonstration */
/*******************************/

Node* list=nodeCreate();

/* push Head*/

listPushHead(list,1);
listPushHead(list,2);
listPushHead(list,3);
puts("The List:");
listPrint(list);
reverse(list);
listPrint(list);


return 0;
}
