#include <stdio.h>
#include <string.h>
#include "person.h"
#include <stdlib.h>

int main(){

	int length;
	int num;
	int i;
	person_t *arr;
	
	puts("Enter number of persons");
	scanf("%d",&num);
	getchar();
	arr=(person_t*)malloc(num*sizeof(person_t));

	for(i=0;i<num;i++){
		puts("Enter the person name number of bytes:");
		scanf("%d",&length);
		getchar();
		arr[i].name=(char*)malloc(length+1);
		puts("Enter person's name:");
		gets(arr[i].name);
		
		puts("Enter the person age");
		scanf("%d",&arr[i].age);
		getchar();
	}
	
	sort(num,arr);
	print(num,arr);
	freeArr(num,arr);
return 0;
}
