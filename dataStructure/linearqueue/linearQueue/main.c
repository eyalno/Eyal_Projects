/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "ADTDefs.h"
#include "linearQueue.h"

int main(){

Queue * tmp=queueCreate(5,8);
int a;


queueInsert(tmp,1);
queueInsert(tmp,2);
queueInsert(tmp,3);
queueInsert(tmp,4);
queueInsert(tmp,5);


queuePrint(tmp);


queueRemove(tmp,&a);
queuePrint(tmp);
queueRemove(tmp,&a);
queuePrint(tmp);
queueRemove(tmp,&a);
queuePrint(tmp);
queueRemove(tmp,&a);
queuePrint(tmp);
return 0;
}
