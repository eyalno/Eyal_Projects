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

/*Unitest create add add set get destroy */
tmp=vectorCreate(5,8);
vectorAdd(tmp,4);
vectorAdd(tmp,9);
vectorAdd(tmp,8);
vectorAdd(tmp,10);
vectorAdd(tmp,1);
vectorAdd(tmp,2);
vectorAdd(tmp,11);
vectorAdd(tmp,12);
vectorAdd(tmp,13);
printVector(tmp);

printVector(tmp);


return 0;
}
