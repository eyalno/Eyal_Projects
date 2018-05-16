/*************************************************************8

		Author: Eyal Noy
		Creation date: 28.8.12
		Last modified date: 28.8.12
		Description: Vector functions Stack data base
*************************************************************/

#include <stdio.h>
#include "hash.h"
#include "ADTDefs.h"

/*hash function example*/
int modu(int key)
{
	return key % 5;
}

int main()
{
	/*data  */ 
	int a=1,b=2,c=3,d=4;
	HashMap* hash;
	/*failed to create*/
	if (!(hash=HashMapCreate(modu,6)))
	{
		puts("failed to create");	
	}
	
	/* crates the hase map*/	
	hash=HashMapCreate(modu,6);
	HashMapPrint(hash);
	
	/*failed to insert */
	if(HashMapInsert(NULL,0,NULL) != ERR_OK)
	{
		puts("failed to create");	
	}
	
	/*insert to hash */
	HashMapInsert(hash,0,&a);
	HashMapInsert(hash,1,&b);
	HashMapInsert(hash,2,&c);
	HashMapInsert(hash,3,&d);
	HashMapPrint(hash);

	/*failed to remove */
	if(HashMapRemove(NULL,0,NULL) != ERR_OK)
	{
		puts("failed to remove");	
	}
	
	/* remove c from hash*/
	HashMapRemove(hash,2,&c);
	HashMapPrint(hash);
	
	/* check size func*/
	printf("size %d",(int)HashMapSize(hash));
	return 0;
}
