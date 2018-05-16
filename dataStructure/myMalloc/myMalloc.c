/************************************************************************

		Author: Eyal Noy
		Creation date: 11.11.12
		Last modified date: 13.11.12
		Description: my malloc  implementation memmory management insert and remove
		Text Editor:  gVim
***********************************************************************/



/* standard libaries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/*local libaries*/


/*initilize the memmory, allign the memmory to a word clussters the first word is memmory size 
last word is zero value stub to end memmory */
void MyMallocInit(void * _memBlock,int _nBytes)
{
	/* allign memmory up by a word*/
	int nBytes=_nBytes + -(_nBytes%sizeof(int));
	
		#ifdef DEBUG
			printf("initilize size byte after initilzation   = %d\n",(int)(nBytes - 2*sizeof(int)));
			
		#endif

	/*insert the size to the first word*/
	*(int*)(_memBlock) = _nBytes;
	
	/*the avilable memmory after decrease the first word and last word*/
	*((int*)(_memBlock)+sizeof(int)) = nBytes - 2*sizeof(int) ;
	
	/*memmory initilize stub*/
	*((int*)(_memBlock) + nBytes-sizeof(int)) =0;
	
}


/*allocate a new chunk if avilable*/
void* MyMalloc(void* _memBlock,int _nBytes)
{
	/*the first position*/
	int* pos= (int*)_memBlock +sizeof(int) ;
	
	/*allign the requested bytes up to a word*/
	int nBytes;
	
	assert(_memBlock);
	assert(_nBytes > 0);
	
	if (_nBytes%sizeof(int))
	{
		nBytes=_nBytes + sizeof(int)-(_nBytes%sizeof(int));

	}
	else
	{
		nBytes=_nBytes;
	}
	
		#ifdef DEBUG
			printf("bytes to write = %d\n",nBytes);
			
		#endif 
	
	/*boundry check all memmory smaller than requested*/
	if (*(int*)_memBlock <nBytes)
	{
		return NULL;
	}

	
	/*searchs for the first avilable memmory until reached stub*/
	while(*pos != 0)
	{
	
		#ifdef DEBUG
			printf("status before insert %d\n",*pos);
			
		#endif

		/*value positive means free*/
		if(*pos > 0 )
		{
			/*check is there is enough memmory to insert*/
			if (*pos - sizeof(int) > nBytes )
			{
				/*update the next jump*/	
				*(pos + nBytes/sizeof(int) +sizeof(int))= *pos -(sizeof(int)+ nBytes);
				
				/*update the current position to occuppied*/
				*pos = -(nBytes+sizeof(int));
				
				#ifdef DEBUG
					printf("status after insert %d\n\n",*pos);
					
				#endif
				
				/*return address of the allocated position*/
				return (void*)(pos );
			}
		}
		
		/*next address to search if occuppied or not enough memmory  */
		pos += abs(*pos);
	}

	#ifdef DEBUG
		puts("End of memmory\n");	
	#endif

	return NULL;

}

/*free the memmory only to a valid pointer defrag if there free memmory after the current memmory*/
void MyFree(void* _currAlloc)
{
	/*word size*/
	int* pos= (int*)_currAlloc;
	
	/*counts how much to defrag*/
	int counter=0;

	
	assert(_currAlloc);
	

	/*cant free 0*/
	if (!*pos)
	{
		return ;
	}

	/*free allready*/
	if (*pos>0)
	{
		return ;
	}

	/*changes to positive value means free*/
	*pos*=-1;

	/*counts chunks until memmory is occupied or reached end*/
	while( *(pos+counter/sizeof(int))>0 )
	{
		counter+=*(pos+counter/sizeof(int));
	}
	
	/*updates after defragment*/
	*pos=counter;
	
	#ifdef DEBUG
		printf("status after free %d\n",*pos);
		
	#endif
	
	return ;
}
