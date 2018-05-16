/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list implementation
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*local libaries*/
#include "ADTDefs.h"
#include "linkedList.h"

void randomTicket()
{
int arr[6];
int i;
int dst[49]={0};
FILE *fp;

int j=0;

if (!(fp=fopen("text","r+")))
{
	puts("Cannot open file");
}

srand ( time(NULL) );

for (i=0;i<6;i++)
{
	arr[i]=rand()%49+1;
}

fwrite(arr,sizeof(int),6,fp);

for (i=0;i<6;i++)
{
	arr[i]=0;
}
/* check other way */
rewind(fp);

fread(arr,sizeof(int),6,fp);

for (i=0;i<6;i++)
{
	dst[arr[i]-1]=9;
}



printf("  1 2 3 4 5 6 7 9 10");

for(i=0; i<49;++i)
{
	if(!i%10)
	{
		printf("\n%d ",j);
		++j;
	}
	
	if(dst[i]==0)
		printf("- ");
	else 
		printf("+ ");
	

}
fclose(fp);
}
