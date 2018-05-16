#include <stdio.h>
#include "recurrsive.h"
#include "stack.h"

size_t fibbonciIter(size_t _n)
{
size_t num1 =0;
size_t num2=1;
size_t tmp;
int i;
	if (_n==1 || _n==0)
	{
		return _n;
	}

	for (i=0;i<_n-1;++i)
	{
		tmp = num2;
		num2+=num1;
		num1=tmp;			
	}

return num2;
}


size_t fibbonaciRec(size_t _n)
{

if(_n<=1)
	return _n;

return fibbonaciRec(_n-1)+fibbonaciRec(_n-2);
}


int findMax(int* _arr,size_t _size)
{
int num;
	
	if( !_size)
	{
		return _arr[_size];
	}
	
	return  ( _arr[_size-1] > (num=findMax(_arr,_size-1)))? _arr[_size-1] : num ;
		
}


int iterativeBinary(int *arr,int size,int num)
{
int low=0,high=size-1,mid;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid] == num)
		{
			return mid;	
		}
		if(num<arr[mid])
		{
			high=mid+1;
		}
		else
		{
			low=mid+1;
		}
	}
return -1;
	
}
int reccursiveBinary(int *arr,int low,int high,int num)
{
	int mid;
	
	if (low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==num)
		{
			return mid;
		}		
		if (num<arr[mid])
		{
			high=mid-1;
			return reccursiveBinary(arr,low,high,num);
		}
		else
		{
			low=mid+1;
			return reccursiveBinary(arr,low,high,num);
		}

	}

return -1;
}

void hanoi(int num,Stack* from,Stack *to,Stack* aux)
{
	int item;
	if (num==1)
	{
		stackPop(from,&item);
		stackPush(to,item);
	}
	else
	{
		hanoi(num-1,from,aux,to);
		hanoi(num-1,aux,to,from);

	}

}