#include <stdio.h>

#define BYTE 8

void BitSet(unsigned int _mask,int _index, int _value)
{
	if(_value >= 1 && _value <= sizeof(int)*BYTE )
	{	

		if (1 == _value)
		{
			*_mask |= (1<<_index-1); 
		}

		else
		{
			*_mask &=(~(1<<_index-1));
		}

	}
}

void PrintReverseStr(char * _string)
{

	if(!_string)
	{
		return;
	}
	PrintReverseStr(_string + 1);
	putchar(_string);

}
//return null or struct



SecinsPkgInfo* Secins_read_pkglist_entry ( SecinsPkgInfo* pkginfo,int pkginfosize )

//when to call closedont call close if ???	
Secins_close_pkglist() 


void printPkgList()
{
	SecinsPkgInfo* current;
	
	Lock();
	while ((current=Secins_read_pkglist_entry()) )
	{
		puts(current->name);
		puts(current->version);
		puts(current->user);
		puts(current->signer);
		puts(current->type);
	}
	UnLock();
	
}
atomic int g_counter=0;


int getPkgVersion(char* _name,char* _version,int _size)
{
	SecinsPkgInfo* tmp;
	Lock();
	while (tmp=Secins_read_pkglist_entry() )
	{
		if (!strcmp(_name,tmp->name))
		{
			Secins_close_pkglist(); 
				
			if (_size  strlen(tmp->version)) 
			{	strncpy(_version,tmp->version, _size);
				++g_counter; 	
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}
	UnLock();
	return -1;
}

//aditional notes?
int getPkgVersionUsageCounter()
{
	
	return g_counter;
	
}



void main()
{

}





