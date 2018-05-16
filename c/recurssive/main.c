#include <stdio.h>
#include "recurrsive.h"
#include "stack.h"

int main()
{
Stack* from=stackCreate(8,8);
Stack* to=stackCreate(8,8);
Stack* aux=stackCreate(8,8);
int arr[]={8,3,5,7,11};
int arr1[]={1,2,3,4,5,6,7,8,9};

printf("%d\n",fibbonciIter(1));
printf("%d\n",fibbonaciRec(2));
printf("%d\n",fibbonaciRec(3));
printf("%d\n",findMax(arr,5));

printf("%d\n",iterativeBinary(arr1,9,3));
printf("%d\n",iterativeBinary(arr1,9,10));
printf("%d\n",iterativeBinary(arr1,9,8));


printf("%d\n",reccursiveBinary(arr1,0,9,8));
printf("%d\n",reccursiveBinary(arr1,0,9,10));
printf("%d\n",reccursiveBinary(arr1,0,9,5));
	
stackPush(from,1);
stackPush(from,2);
stackPush(from,3);
stackPush(from,4);
hanoi(4,from,to,aux);
stackPrint(to);

return 0;

}
