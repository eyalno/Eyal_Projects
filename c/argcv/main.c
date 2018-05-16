/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <stdlib.h>

/*local libaries*/
#include "ADTDefs.h"
#include "linkedList.h"

int main(int argc,char** argv)
{
if (argc !=5)
{
	puts("a.out Name FamilyName Age PhoneNumber");
	
}

if(!atoi(argv[3]))
{
	puts("Paramater 4 not a number");
}
printf("The command %s %s %s %s %s\n",argv[0],argv[1],argv[2],argv[3],argv[4]);

return 0;
}
