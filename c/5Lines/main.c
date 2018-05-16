/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 4.9.12
		Description: linked list main function , functionality and test
***********************************************************************/
/* standard libaries */
#include <stdio.h>
#include <stdlib.h>
void linesEnd(int _numLines,char* _fileName)
{
FILE *fp;
char line[100];
int * arr=(int*)malloc(sizeof(int)*_numLines);
int counter=0;
int i;
int flag=0;

if (!(fp=fopen(_fileName,"r")))
{
	puts("Cannot open file");
}

arr[0]=0;
++counter;
while (fgets(line,100,fp) !=NULL  )
{
	if (feof(fp))
		break;
	arr[counter++]=ftell(fp);
	
	if (counter ==_numLines)
		flag=1;
			
	counter%=_numLines;
}

for(i=0;i<counter && !flag; i++)
{
	fseek(fp,arr[i],0);
	fscanf(fp,"%s",line);
	puts(line);
}

for (i=0;flag && i<_numLines ;i++)
{
	counter%=_numLines;
		fseek(fp,arr[counter],0);
		fscanf(fp,"%s",line);
		puts(line);

}



}



int main()
{
char fileName[100];
int num;

puts("Enter file name");
gets(fileName);

puts("Enter number of lines:");
scanf("%d",&num);
getchar();

linesEnd(num,fileName);





	

return 0;
}
