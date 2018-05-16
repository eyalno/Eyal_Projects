/************************************************************************************************
		Author:             Yair Feldman
		Creation date:      11.10.12
		Data last modified: 
		Description:        Class DataStorage_t - cpp file with functions implimentations for Class DataStorage_t
*************************************************************************************************/

#include <cstring>
#include <iostream>
#include "dataS.h"


DataStorage_t::DataStorage_t():
	m_size(INIT_SIZE),
	m_extSize(INIT_EXT_SIZE),
	m_readPos(0),
	m_writePos(0)
{
 	m_buff = new char[INIT_SIZE];
}


DataStorage_t::DataStorage_t(size_t _size):
	m_size(_size),
	m_extSize(INIT_EXT_SIZE),
	m_readPos(0),
	m_writePos(0)
{
 	m_buff = new char[_size];
}


DataStorage_t::~DataStorage_t()
{
	delete[] m_buff;
}


void DataStorage_t::WriteData(const void* _src, size_t _numBytes)
{
	if( m_size - m_writePos < _numBytes )
	{
		m_size += m_extSize;
		char* newBuff = new char[m_size];
		memcpy( newBuff , m_buff , m_writePos);
		delete[] m_buff;
		m_buff = newBuff;
	}
	memcpy( &m_buff[m_writePos], _src , _numBytes);
	m_writePos += _numBytes;
}


void DataStorage_t::ReadData(void* _dst, size_t _numBytes)
{
	memcpy( _dst, &m_buff[m_readPos], _numBytes );
	m_readPos += _numBytes;
}


/**********************************************************/
/***** Input/Output operators for all built-in types ******/
/**********************************************************/


DataStorage_t& DataStorage_t::operator>>(char& _data)
{ 
	ReadData( &_data, sizeof(_data) );
	return *this; 
}


DataStorage_t& DataStorage_t::operator>>(unsigned char& _data)
{
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(int& _data)
{ 
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(unsigned int& _data)
{ 
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(short& _data)
{ 
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(unsigned short& _data)
{
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(long& _data)
{
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(unsigned long& _data)
{
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(double& _data)
{
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(float& _data)
{
	ReadData( &_data, sizeof(_data) );
	return *this;
}

DataStorage_t& DataStorage_t::operator>>(bool& _data)
{
	ReadData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator>>(char* _data)
{ 
	int len;
	ReadData( &len, sizeof (len) );
	ReadData( _data, len );
	return *this; 
}



DataStorage_t& DataStorage_t::operator<<(char _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this; 
}


DataStorage_t& DataStorage_t::operator<<(unsigned char _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this; 
}


DataStorage_t& DataStorage_t::operator<<(int _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this; 
}


DataStorage_t& DataStorage_t::operator<<(unsigned int _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this; 
}


DataStorage_t& DataStorage_t::operator<<(short _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator<<(unsigned short _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator<<(long _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator<<(unsigned long _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator<<(double _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator<<(float _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator<<(bool _data)
{ 
	WriteData( &_data, sizeof(_data) );
	return *this;
}


DataStorage_t& DataStorage_t::operator<<(const char* _data)
{ 
	int len = strlen(_data) + 1;
	WriteData( &len, sizeof(len));
	WriteData(_data, len);
	return *this;
}


