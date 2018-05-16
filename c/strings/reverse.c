#include <stdio.h>
#include <string.h>

void reverse(char * name)
{
char temp;
int i;
int length=strlen(name);
for (i=0; length/2 >i; i++)
	{
		temp =name[i];
		name[i]=name[length-i-1];
		name[length-i-1]=temp;
	}
printf("%s\n",name);


}

       		 
int main()
{

char name[5];

printf("Enter name:");
scanf("%s",name);

reverse(name);
return 1;
}
