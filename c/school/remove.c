#include <stdio.h>
#include "array.h"




void rmv(array_t *class)
{

int seatNum;
int i;	
	printf("Seats avilable to remove 0- %d: \n",class->numOfElements);
        scanf("%d",&seatNum);
        getchar();

	
	for (i=seatNum;class->numOfElements > i;i++)
	class->arr[i]=class->arr[i+1];


        class->numOfElements--;


	puts("class");
	for (i=0; i<class->numOfElements; i++)
		printf("%d ",class->arr[i]);
	puts("");
}	
