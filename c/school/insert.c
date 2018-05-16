#include <stdio.h>
#include "array.h"
#include <stdlib.h>


void insert(array_t *calander){

int seatNum;
int min;
int i;
char c;

Meeting tmp; 

	tmp=(Meeting*)malloc(sizeof(Meeting));
	
	puts("Enter start time:");
/*	scanf("%2d%1c%2d",&tmp->m_Start,&c,&min);*/
	scanf("%2d%1c%2d",&tmp->m_Start);
	getchar();
	
	puts("Enter Length:");
	scanf("%d",tmp->m_Length);
	getchar();
		
	if (calander->capacity == calander->numOfElements)
		resize(calander);

	if (!calander->numOfElements){
		calander->arr[0]=tmp;
		return;
	}
	
	for (i=0;class->numOfElements-seatNum > i;i++)
			class->arr[class->numOfElements-i]=class->arr[class->numOfElements-1-i];
	
	class->arr[seatNum]=studentNum;
		
	class->numOfElements++;
	
	puts("class:");
	for (i=0; i<class->numOfElements; i++)
                printf("%d ",class->arr[i]);
	puts("");

}
