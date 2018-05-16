#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

#include "memPage.h"



memPage_t::memPage_t(int _pageSize):
m_capacity(_pageSize),m_currentPosition(0)
{
	m_page= new char[_pageSize];
}


memPage_t::memPage_t (const memPage_t &_page)
{
	cout<<"forbbiden"<<endl;
}

const memPage_t& memPage_t::operator=(const memPage_t& _page)
{

	cout<<"forbbiden"<<endl;
	return *this;
}
	
bool memPage_t::IsPageEmpty()const
{
	return !m_currentPosition;
}

bool memPage_t::IsPageFull()const
{
	return (m_currentPosition == m_capacity);

}

int memPage_t::ActualSize()const
{
	return m_currentPosition;
}

int memPage_t::Capacity()const
{
	return m_capacity;
}

int memPage_t::copy(void* _data,int _numBytes,int _pos,Mode _mode)
{

	int Bytes;
	int freeBytes = m_capacity - _pos;
	
	//default position
	if(_pos == (signed)0xdeadbeef )
	{
		_pos = m_currentPosition;
	}
	
	//out of boundry
	if (  (_pos<0) || (_pos > m_currentPosition  ) )
	{
		throw _pos;
	}

	// copy bytes and increase cursor
	Bytes = ( _numBytes / freeBytes == 0 ) ? _numBytes : freeBytes;

	(_mode == WRITE) ? memcpy ((_pos+m_page),_data,Bytes) :memcpy(_data,(_pos+m_page),Bytes);
	
	m_currentPosition = _pos + Bytes;
	return Bytes;
}

int memPage_t::write(void* _data,int _numBytes,int _pos)
{

	return copy(_data,_numBytes,_pos,WRITE);
}

int memPage_t::read(void* _data,int _numBytes,int _pos)
{
	return copy(_data,_numBytes,_pos,READ);
}
		
int memPage_t::get()
{
	return m_currentPosition;
}

void memPage_t::set(int _pos)
{
	if (  (_pos<0) || (_pos > m_currentPosition  ) )
	{
		throw _pos;
	}
	m_currentPosition=_pos;
}



