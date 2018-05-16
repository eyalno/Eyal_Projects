#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int any(char* str1, char*str2){

	int i,j,k;	
	for(i=0;str1[i];i++){
	
		for(j=0,k=i; str2[j]==str1[k]&& str2[j] && str1[k];j++,k++);
		if(!str2[j])
			return i; 
	
	}	
	
	return -1;

}

void function1()
{
	char str1[256];
	char str2[256];
	
	printf ("Enter first string :\n");
	gets(str1);

	printf ("Enter second string :\n");
 	gets(str2);
	
	printf("The location is :%d\n",any(str1,str2));	
  	
}

void function2(){
	
	char str1[256];
        char str2[256];
	int a,b;

        printf ("Enter first string :\n");
        gets(str1);
	a=atoi(str1);
        printf ("Enter second string :\n");
        gets(str2);
	b=atoi(str2);
	a+=b;
	itoa(a,str1,10);
	puts(str1);
	
}

void function3()
{
	char str1[256];
        char str2[256];
	char *ptr=str1;
	char *ptr2=str2;
	int counter=0;
	int location;
	int length=0;

        printf ("Enter sentence :\n");
        gets(str1);

        printf ("Enter word :\n");
        gets(str2);
	length=strlen(str2);

	while ((location=any(ptr,ptr2))!= -1){
		counter++;	
		ptr+=location+length;
	}
	printf("Number of occurences:%d\n",counter);

}

int main()
{

	int option;
	printf("Enter Exercise option 1 2 3\n");
	scanf("%d",&option);
	getchar();

	switch(option){

	case 1:
		function1();
		break;
	case 2:
		function2();
		break;
	case 3:
		function3();
		break;	
	
	}

	return 0;
}
