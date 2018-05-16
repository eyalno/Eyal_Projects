#include <stdio.h>
#include "array.h"
#include <stdlib.h>

int findMeeting(array_t* calander)
{
int start;
int end;
int i;

puts("Enter start end time of meeting to find");
scanf("%d%d",&start,&end);
getchar();

for (i=0; i <calander->numOfElements-1;++i)
{
	if (calander->arr[i]->m_Start == start && calander->arr[i]->m_End== end)
		return 1; 
}
return 0;

}



array_t* initilizeCalander()
{

        array_t* calander= (array_t*)malloc(sizeof(array_t));

        calander->capacity=0;
        calander->numOfElements=1;
        calander->expandValue=8;

        resize(calander);
        calander->arr[0]=(Meeting*)malloc(sizeof(Meeting));

        calander->arr[0]->m_Start=24;
        calander->arr[0]->m_End=25;

return calander;

}

void enterMeeting(array_t* calander,int input)
{

Meeting *tmp; 
FILE *fp;
char  fileName[10]; 
char buf;

puts("Enter file name");
gets(fileName);

if (!(fp=fopen(fileName,"r")))
{
        puts("Cannot open file");
}



tmp=(Meeting*)malloc(sizeof(Meeting));
	if(!tmp)
	{
		return;
	}

switch(input)
{
case 1:
	
	
	puts("Enter start time:");
	scanf("%d",&tmp->m_Start);
	getchar();
	
	puts("Enter End time:");
	scanf("%d",&tmp->m_End);
	getchar();
	
	puts("Enter subject:");
	gets(tmp->m_Subject);
	
	insert(calander,tmp);

	break;


case 2:

	do
	{
		fscanf(fp,"%d%d%c%s",&tmp->m_Start,&tmp->m_End,&buf,tmp->m_Subject);
		if (feof(fp))
			break;
		insert(calander,tmp);
		tmp=(Meeting*)malloc(sizeof(Meeting));
		
		if(!tmp)
		{
			return;
		}
	
	}
	while (1);
	
	break;
}


}

void insert(array_t *calander,Meeting* tmp)
{

int i;
int j;
	
		
	for (i=0; i < calander->numOfElements;i++){
		if(calander->arr[i]->m_Start <=tmp->m_Start && tmp->m_Start < calander->arr[i]->m_End){
			puts("Allready scheduled");
			return;
		}
		if (tmp->m_End <= calander->arr[i]->m_Start){
			break;
		}
	}	
	
		
	if (calander->capacity == calander->numOfElements)
		resize(calander);



	for (j=0;j<calander->numOfElements-i  ;j++){
			calander->arr[calander->numOfElements-j]=calander->arr[calander->numOfElements-1-j];
	}
		calander->arr[i]=tmp;
		
	calander->numOfElements++;
	
	printCalander(calander);


}




void printCalander(array_t* calander){
int i;
 
FILE *fp;
   
	if (!(fp=fopen("output","w")))
	{
        	puts("Cannot open file");
	}

	puts("Calander:");
        for (i=0; i<calander->numOfElements-1; i++)
	{
                printf("%d %d %s\n",calander->arr[i]->m_Start,calander->arr[i]->m_End,calander->arr[i]->m_Subject);
                fprintf(fp,"%d\t%d\t%s\n",calander->arr[i]->m_Start,calander->arr[i]->m_End,calander->arr[i]->m_Subject);
        }
	puts("");


	
}

