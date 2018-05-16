/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "vector.h"
#include "ADTDefs.h"

/*sdgsdgsd*/

int main(){

Vector *tmp;
int a=5;
int *b;

b=&a;
/*Unitest vectorCreate Fail */
if(!vectorCreate(0,0)){
}

/*Unitest vector Create and Destroy*/
tmp=vectorCreate(5,8);
printVector(tmp);
vectorDestroy(tmp);

/*Unitest create add add set get destroy */
tmp=vectorCreate(5,8);
printVector(tmp);
vectorAdd(tmp,1);
printVector(tmp);
vectorAdd(tmp,3);
printVector(tmp);
vectorSet(tmp,0,8);
printVector(tmp);
vectorGet(tmp,1,b);
printVector(tmp);
vectorDestroy(tmp);

/*Unitest Create Add Add itemNum remove remove destroy*/
tmp=vectorCreate(5,8);
printVector(tmp);
vectorAdd(tmp,1);
printVector(tmp);
vectorAdd(tmp,3);
printVector(tmp);
vectorItemsNum(tmp,b);
vectorRemove(tmp,b);
printVector(tmp);

vectorRemove(tmp,b);
printVector(tmp);


return 0;
}
