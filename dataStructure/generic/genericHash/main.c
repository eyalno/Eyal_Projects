/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 5.11.12
		Description: Generic Hasj main function , functionality and test
		Text Editor: 	gVim
***********************************************************************/
/* standard libaries */
#include <stdio.h>

/*local libaries*/
#include "ADTDefs.h"
#include "hash.h"
#include "logger.h"


/*macro*/
#define SIZE 30


/*user hash function */
int modu(HashKey* _key,size_t _size)
{
	return *(int*)_key % _size;
}

/*user compare function */
int IsEqual(HashKey* _key1,HashKey* _key2)
{
	return (*(int*) _key1 ==*(int*) _key2) ? 1 :0; 
}

/*user print function */
int print(HashKey* _key,HashData* _data  ,void* _params) 
{
	printf("key:%-4d   data:%-4d   \n",*(int*)_key,*(int*)_data);
	return 1;
}

/*user print function */
int Add3(HashKey* _key,HashData* _data  ,void* _params) 
{
	*(int*)_data +=3;
	return 1;
}

int main()
{
	int key[]={11,66,33,77,4,5,4}; 
	int data[]={23,44,2,3,42,2,2};
	int i;
	
	HashMap* hash= HashCreate(SIZE,modu,IsEqual);
	
	LogCreate(ERR,"log");
	/*unit test 1 create and destroy*/	
	HashDestroy(hash);
	
	/*unit test 2 creates insert 2 items and print using For each*/
	hash=HashCreate(SIZE,modu,IsEqual);

	puts("enter 7 integers");
	for(i=0;i<7; ++i)
	{
		HashInsert(hash,&key[i],&data[i]);
	
	}
	
	puts("the hash");
	HashForEach(hash,print,NULL);
	putchar('\n');


	/*unit test 3 remove  and print using For each*/
	puts("remove 3 integers");
	for(i=0;i<3; ++i)
	{
		HashRemove(hash,&key[2+i]);
	}	
	puts("the hash after remove");
	HashForEach(hash,print,NULL);
	putchar('\n');
	
	/*unit test 4 print number of items and how many beckets free*/
		
	printf("items num: %d\n",HashCountItems(hash));
	printf("empty buckets num: %d\n",HashCountEmptyBackets(hash));

	/*unitest 5 add 3 to data using for each*/
	HashForEach(hash,Add3,NULL);
	puts("the hash after add 3");
	HashForEach(hash,print,NULL);
	putchar('\n');
	
	for(i=0;i<100; ++i)
	{
		HashRemove(hash,&key[i]);
	}	
	
	puts("the hash after remove go through 100 keys");
	HashForEach(hash,print,NULL);
	putchar('\n');
	return 0;
}
