#include <stdio.h>
#include "array.h"
#include <stdlib.h>


array_t* initlizeCalander();
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

int main(){

array_t *calander;
int menu=0;

	/*initilize    */	
	calander=initlizeCalander();	

	do{
		puts("Enter option");
		puts("1.Insert");
		puts("2.remove");
		puts("3.print");
		puts("4.Exit");
		puts("999.delete all");
		scanf("%d",&menu);
		getchar();
		
		switch(menu){
			case 1:
				insert(calander);
				break;	
			case 2: 
				rmv(calander);					
				break;
			
			case 4: 
				freeArr(calander);
				return 0;
			case 999:
				calander->arr[0]=calander->arr[calander->numOfElements-1];
				calander->numOfElements=1;
			case 3:
				printCalander(calander);	
				
		}	
	}while(1);
}




