/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "ADTDefs.h"
#include "vector.h"

#include "stack.h"
int main(){

Stack* tmp;
int a=5;
int *b;

b=&a;

/*Unitest stackCreate Fail */
if(!stackCreate(0,0)){
}

/*Unitest stack Create and Destroy*/
tmp=stackCreate(5,8);
stackPrint(tmp);
stackDestroy(tmp);

/*Unitest create add add get destroy */
tmp=stackCreate(5,8);
stackPrint(tmp);
stackPush(tmp,1);
stackPrint(tmp);
stackPush(tmp,3);
stackPrint(tmp);
stackPrint(tmp);
stackTop(tmp,b);
stackPrint(tmp);
stackDestroy(tmp);

/*Unitest Create Add Add remove remove destroy*/
tmp=stackCreate(5,8);
stackPrint(tmp);
stackPush(tmp,1);
stackPrint(tmp);
stackPush(tmp,3);
stackPrint(tmp);
stackPop(tmp,b);
stackPrint(tmp);

stackPop(tmp,b);
stackPrint(tmp);


return 0;
}
