#ifndef STACK_H
#define STACK_H
#include "ADTDefs.h"

typedef struct  HashMap HashMap;
typedef int(*HF)(int key);

/* create hash map and initilize i witht he func and size */
HashMap* HashMapCreate(HF func,size_t size);

/*destroy hash map */ 
void HashMapDestroy(HashMap* _hash);

/*insert the data to hash after decrypt the position using the key */
ADTERR HashMapInsert(HashMap* _hash,int _key,int * _data);

/*remove the data to hash after decrypt the position using the key */
ADTERR HashMapRemove(HashMap* _hash,const int _key,int * _data);

/*retreive the data to hash after decrypt the position using the key */
ADTERR HashMapGetValueByKey(HashMap* _hash,const int _key,int * _data);

/*returns the number of items in hash*/ 
size_t HashMapSize(HashMap* _hash);

void HashMapPrint(HashMap* _hash);


#endif
