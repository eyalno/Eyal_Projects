

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "memPool.h"


typedef list<memPage_t*>::iterator Iter;


memPool_t::memPool_t(int _numPages,int _pageSize):
m_capacity(_pageSize * _numPages),m_currentPosition(0)
{
	
	for (int i=0 ; i< _numPages ; ++i)
	{
		m_list.push_back( new memPage_t(_pageSize));
	}	
}

memPool_t::~memPool_t()
{
	Iter it;
	for ( it=m_list.begin() ; it != m_list.end(); it++ )
	{
		delete *it;
	}
}


memPool_t::memPool_t (const memPool_t &_pool)
{
	cout<<"forbbiden"<<endl;
}

const memPool_t& memPool_t::operator=(const memPool_t& _pool)
{

	cout<<"forbbiden"<<endl;
	return *this;
}
	
bool memPool_t::IsPoolEmpty()const
{
	return !m_currentPosition;
}


int memPool_t::ActualSize()const
{
	return m_currentPosition;
}


int memPool_t::copy(void* _data,int _numBytes,int _pos,Mode _mode)
{


	if(_pos == (signed)0xdeadbeef )
	{
		_pos = m_currentPosition;
	}
	
	if (  (_pos<0) || (_pos > m_currentPosition  ) )
	{
		throw _pos;
	}
	
	Iter itr;
	int counter;
	
	//finds iterator of current position
	for( counter=0,itr = m_list.begin() ; (counter +(*itr)->Capacity()) < _pos ; counter+= (*itr)->Capacity(),itr++);
	
	
	//copying from position in middle of page
	int bytes;
	m_currentPosition = _pos + _numBytes;

	bytes = (_mode == WRITE) ? (*itr)->write(_data,_numBytes,_pos) : (*itr)->read(_data,_numBytes,_pos); 
	
	_numBytes-=bytes;
	_data= (char*)_data + bytes;
		
	//copy from next pages create new page if eof	
	while( _numBytes > 0 )
	{

		++itr;
		if (itr == m_list.end() )
		{
			m_list.push_back( new memPage_t());
		}
		
		bytes = (_mode == WRITE) ? (*itr)->write(_data,_numBytes,0) : (*itr)->read(_data,_numBytes,0); 
		
		_numBytes-=bytes;
		_data= (char*)_data + bytes;

	}
	

	return 1;
}

int memPool_t::write(void* _data,int _numBytes,int _pos)
{

	return copy(_data,_numBytes,_pos,WRITE);
}

int memPool_t::read(void* _data,int _numBytes,int _pos)
{
	return copy(_data,_numBytes,_pos,READ);
}
		
int memPool_t::get()
{
	return m_currentPosition;
}

void memPool_t::set(int _pos)
{
	if (  (_pos<0) || (_pos > m_currentPosition  ) )
	{
		throw _pos;
	}
	
	m_currentPosition=_pos;
}


int memPool_t::getDefault()
{
	return defaultPageSize;
}

void memPool_t::setDefault(int _pos)
{
	if (  (_pos <= 0) )
	{
		throw _pos;
	}
	
	defaultPageSize = _pos;
}

