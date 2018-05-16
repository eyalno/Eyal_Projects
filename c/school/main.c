#include <stdio.h>
#include "array.h"
#include <stdlib.h>



int main(){

array_t *calander;
int menu;
int classNum;
int i;	


	calander= (array_t*)malloc(sizeof(array_t));
	
	calander->capacity=0;
	calander->numOfElements=0;
	calander->expandValue=8;
	calander->arr=NULL;
}			

	do{
		puts("Enter option 1 2 3");
		puts("1.Insert");
		puts("2.remove");
		puts("3.Exit");
		scanf("%d",&menu);
		getchar();
		
		switch(menu){
			case 1:
				printf("Enter class num 0-%d:\n",num-1);
        			scanf("%d",&classNum);
      				getchar();
						
				insert(school+classNum);
				break;	
			case 2: 
				printf("Enter class num 0-%d:\n",num-1);
				scanf("%d",&classNum);
				getchar();
				rmv(school+classNum);					
				break;
			
			case 3: 
				freeArr(school,num);
				return 0;
		}	
	}while(1);
}




