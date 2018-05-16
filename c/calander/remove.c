#include <stdio.h>
#include "array.h"




void rmv(array_t *calander)
{
int start;
int i;
int j;
        puts("Enter start time of meeting to remove");
	scanf("%d",&start);
        getchar();

	
	for (i=0;calander->arr[i]->m_Start !=start  ;i++);
	for (j=0; j < calander->numOfElements-i  ;j++){

		calander->arr[i+j]=calander->arr[i+1+j];
	}
        calander->numOfElements--;

	printCalander(calander);
}	
