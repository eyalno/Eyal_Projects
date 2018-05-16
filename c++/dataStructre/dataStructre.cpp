
/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    1.11.12
		Last modified date: 1.11.12
		Description:        data storage implentation file input output and satistics about the storage
		Text Editor:	    gVim
		File Type:  	    cpp File
***********************************************************************/
#include <iostream>
#include <cstring>
#include "dataStructre.h"

#define EXPAND_SIZE 8
#define INITILIZE_SIZE 8

/*default constructor*/
DataStorage_t::DataStorage_t()
{
	m_size=INITILIZE_SIZE;
	m_expandValue=EXPAND_SIZE;
	m_readCursor=0;
	m_writeCursor=0;
	m_buffer = new char[m_size];
}		
		
/*constuctor with size from user*/
DataStorage_t::DataStorage_t(size_t _size)
{
	m_size=_size;
	m_expandValue=EXPAND_SIZE;
	m_readCursor=0;
	m_writeCursor=0;
	m_buffer = new char[_size];
}

/*destructor*/
DataStorage_t::~DataStorage_t()
{
	delete[] m_buffer;
}


/*read write functions from buffer*/
void DataStorage_t::ReadBuffer(void* _variable,size_t _size)
{
	memcpy(_variable,m_buffer +m_readCursor,_size);
	m_readCursor+=_size;
}	
		
void DataStorage_t::WriteBuffer(const void* _data,size_t _size)
{
	/*need to realocate?*/
	if ((int)_size > m_size - m_writeCursor)
	{
		char * tmp= new char[m_size + (_size/m_expandValue+1)*m_expandValue];
		memcpy(tmp,m_buffer,m_writeCursor-m_readCursor);
		delete[] m_buffer;
		m_size +=_size;
		m_buffer=tmp;
	}

	memcpy(m_buffer+m_writeCursor,_data,_size);
	m_writeCursor+=_size;

}

