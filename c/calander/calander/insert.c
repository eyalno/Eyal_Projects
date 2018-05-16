#include <stdio.h>
#include "array.h"
#include <stdlib.h>


void insert(array_t *calander){

int start;
int end;
int i;
int j;
Meeting *tmp; 
	
	puts("Enter start time:");
	scanf("%d",&start);
	getchar();
	
	puts("Enter End time:");
	scanf("%d",&end);
	getchar();
	
	for (i=0; i < calander->numOfElements;i++){
		if(calander->arr[i]->m_Start <=start && start < calander->arr[i]->m_End){
			puts("Allready scheduled");
			return;
		}
		if (end <= calander->arr[i]->m_Start){
			break;
		}
	}	
	
		
	if (calander->capacity == calander->numOfElements)
		resize(calander);

	tmp=(Meeting*)malloc(sizeof(Meeting));
	if(!tmp){
		return;
	}

	tmp->m_Start=start;
	tmp->m_End=end;		
	for (j=0;j<calander->numOfElements-i  ;j++){
			calander->arr[calander->numOfElements-j]=calander->arr[calander->numOfElements-1-j];
	}
	puts("Enter subject:");
	gets(tmp->m_Subject);

	calander->arr[i]=tmp;
		
	calander->numOfElements++;
	
	printCalander(calander);


}




void printCalander(array_t* calander){
int i;
        puts("Calander:");
        for (i=0; i<calander->numOfElements; i++)
                printf("%d %d %s\n",calander->arr[i]->m_Start,calander->arr[i]->m_End,calander->arr[i]->m_Subject);
        puts("");
}

