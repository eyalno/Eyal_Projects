/************************************************************************

		Author: Eyal Noy
		Creation date: 3.9.12
		Last modified date: 5.11.12
		Description: Generich Hash Header file functions forward declerations and macro
		Text Editor:  gVim
***********************************************************************/

#ifndef STACK_H
#define STACK_H

/*struct macro*/
typedef void HashKey;
typedef void HashData;
typedef struct HashMap HashMap;

/*function macro*/
typedef int (*HashFunc) (HashKey *_key,size_t _size); 

typedef int (*IsEqualFunc) (HashKey *_key1,HashKey *_key2);

typedef int (*DoFuncHash)(HashKey* _key,HashData* _data  ,void* _params);

typedef int(*HF)(int key);

/* create hash map and initilize the allocated hash with the parameter */
HashMap* HashCreate(size_t _size,HashFunc _hFunc,IsEqualFunc _isEqual);

/*destroy hash map */ 
void HashDestroy(HashMap* _hash);

/*insert the data to hash after decrypt the position using the key */
ADTErr HashInsert(HashMap* _hash,HashKey* _key,HashData* _data);

/*remove the data to hash after decrypt the position using the key */
HashData* HashRemove(HashMap* _hash,HashKey* _key);

/*search the data after decrypting the key*/
HashData* HashFind(HashMap* _hash,HashKey* _key);

/*returns the number of items in hash*/ 
size_t HashCountItems(HashMap* _hash);

/*returns the number of empty buckets no entries*/
size_t HashCountEmptyBackets(HashMap* _hash);

/*apply the doFunc on all items*/
int HashForEach(HashMap* _hash,DoFuncHash _doFunc,void* _params);

#endif
