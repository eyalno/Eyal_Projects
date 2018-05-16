#include <stdio.h>
#include "array.h"
#include <stdlib.h>




int main(){

array_t *calander;
int menu=0;

	/*initilize    */	
	calander=initilizeCalander();	

	do{
		puts("Enter option");
		puts("1.Insert from user");
		puts("2.Insert from file");
		puts("3.remove");
		puts("4.print");
		puts("5.Find neeting");
		puts("6.Write calander to file");
		puts("7.Exit");
		puts("999.delete all");
		scanf("%d",&menu);
		getchar();
		
		switch(menu){
			case 1:
				enterMeeting(calander,1);
				break;	
			case 2:
				enterMeeting(calander,2);
				
				break;
			case 3: 
				rmv(calander);			
				break;		
			case 4:
				printCalander(calander);	
				break;
		
			case 5:
				if (findMeeting(calander))
					puts("found");
				else
					puts("not found");
				break;	
			case 6: 
				
				break;
			case 7: 
				freeArr(calander);
				return 0;
			case 999:
				calander->arr[0]=calander->arr[calander->numOfElements-1];
				calander->numOfElements=1;
				break;
					}	
	}while(1);
}




