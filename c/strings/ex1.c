#include <stdio.h>


void swap(int*x,int*y)
{
int temp;
temp = *x;
*x=*y;
*y=temp;
}


void sort(int *arr,int size)
{
int i;
int j;
int pos;
	for(i=0;i < size -1;i++)
        {
		pos = i;
		for (j=i; j<size -1;j++)
			if (arr[j+1] < arr[pos])
				pos = j+1; 	
			
		swap (arr+i,arr+pos);	

       		 
	}
}
int main()
{

int arr[5]={3,2,1,5,4};
int i; 
int size=5;
sort(arr,size);

for (i=0;i<size;)
	printf("%d ",arr[i++]);
putchar('\n');

return 1;

}
