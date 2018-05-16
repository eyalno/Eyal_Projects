/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "ADTDefs.h"
#include "circularQueue.h"

int main(){
int a;
Queue * tmp=queueCreate(6);


queueInsert(tmp,1);
queueInsert(tmp,2);
queuePrint(tmp);
queueInsert(tmp,3);
queuePrint(tmp);
queueInsert(tmp,4);
queueInsert(tmp,5);




queueRemove(tmp,&a);
queuePrint(tmp);
queueRemove(tmp,&a);
queuePrint(tmp);
queueRemove(tmp,&a);
queueInsert(tmp,1);
queuePrint(tmp);
queueRemove(tmp,&a);
queueInsert(tmp,1);
queuePrint(tmp);
return 0;
}
