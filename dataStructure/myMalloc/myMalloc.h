/************************************************************************

		Author: Eyal Noy
		Creation date: 11.11.12
		Last modified date: 13.11.12
		Description: my Malloc h file functions forward declerations
		Text Editor:  gVim
***********************************************************************/



#ifndef LINKED_LIST_H
#define LINKED_LIST_H



/*initilize memmory the actuall memmory is smaller after initilize*/
void MyMallocInit(void * _memBlock,int _nBytes);

/*allocate a new chunk if avilable*/
void* MyMalloc(void* _memBlock,int _nBytes);

/*frees only valid occupied memmory and defrag*/
void MyFree( void* _currAlloc);

#endif
