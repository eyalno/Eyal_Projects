
/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    1.11.12
		Last modified date: 1.11.12
		Description:        data storage header file input output and satistics about the storage implementation of inline
		Text Editor:	    gVim
		File Type:  	    header File
***********************************************************************/
#ifndef _DATA_STORAGE_H
#define _DATA_STORAGE_H


#include <iostream>
#include <cstring>

using namespace std;



class DataStorage_t
{
	public:
		/*default constructor*/
		DataStorage_t();		
		
		/*constuctor with size from user*/
		DataStorage_t(size_t _size);	

		/*destructor*/
		virtual ~DataStorage_t();	
		
		/*set a new expand value*/
		inline void XpndValue(size_t _size);
		
		/*returns number of bytes in buffer*/
		inline const int ByteSize()const;
		
		/*read from begin*/
		inline void Reset();
	
		/*reset cursor*/
		inline void New();
		
		/*variable -> buffer */
		
		inline const DataStorage_t& operator<<(const bool _data);

		inline const DataStorage_t& operator<<(const char _data);

		inline const DataStorage_t& operator<<(const unsigned char _data);

		inline const DataStorage_t& operator<<(const int _data);

		inline const DataStorage_t& operator<<(const unsigned int _data);

		inline const DataStorage_t& operator<<(const short _data);

		inline const DataStorage_t& operator<<(const unsigned short _data);

		inline const DataStorage_t& operator<<(const long _data);
			
		inline const DataStorage_t& operator<<(const unsigned long _data);
			
		inline const DataStorage_t& operator<<(const float _data);
			
		inline const DataStorage_t& operator<<(const double _data);
			
			
		
		/* buffer ->  variable */
			
		inline const DataStorage_t& operator>>( bool& _data);

		inline const DataStorage_t& operator>>( char& _data);

		inline const DataStorage_t& operator>>( unsigned char &_data);

		inline const DataStorage_t& operator>>( int &_data);

		inline const DataStorage_t& operator>>( unsigned int &_data);

		inline const DataStorage_t& operator>>( short &_data);

		inline const DataStorage_t& operator>>( unsigned short &_data);

		inline const DataStorage_t& operator>>( long &_data);
			
		inline const DataStorage_t& operator>>( unsigned long &_data);
			
		inline const DataStorage_t& operator>>( float &_data);
				
		inline const DataStorage_t& operator>>( double &_data);
			
	
	private:
	
		/*copy ctor no need for this */
		DataStorage_t(DataStorage_t& _ptr);
		
		/*assignment operator no need for this */
		const DataStorage_t& operator=(const DataStorage_t& _ptr);

		/*read write functions from buffer*/
		void ReadBuffer(void* _variable,size_t _size);	
		
		void WriteBuffer(const void* _data,size_t _size);	

		int m_size;
		int m_expandValue;
		int m_readCursor;
		int m_writeCursor;
		char* m_buffer;
		
};

/*inline functions*/


/*set a new expand value*/
inline void DataStorage_t::XpndValue(size_t _size)
{
	m_expandValue=_size;
}
		
/*returns number of bytes in buffer*/
inline const int DataStorage_t::ByteSize()const
{
	return m_writeCursor;
}
		
/*read from begin*/
inline void DataStorage_t::Reset()
{
	m_readCursor=0;
}
	
/*reset cursor*/
inline void DataStorage_t::New()
{
	m_readCursor=0;
	m_writeCursor=0;
}

inline const DataStorage_t& DataStorage_t::operator<<(const bool _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator<<(const char _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator<<(const unsigned char _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator<<(const int _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator<<(const unsigned int _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator<<(const short _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator<<(const unsigned short _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator<<(const long _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}
		
inline const DataStorage_t& DataStorage_t::operator<<(const unsigned long _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}
		
inline const DataStorage_t& DataStorage_t::operator<<(const float _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}
		
		
inline const DataStorage_t& DataStorage_t::operator<<(const double _data)
{
	WriteBuffer(&_data,sizeof(_data));
	return *this;
}
		
		
		
/* buffer ->  variable */
			
inline const DataStorage_t& DataStorage_t::operator>>( bool& _data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}
inline const DataStorage_t& DataStorage_t::operator>>( char& _data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator>>( unsigned char &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator>>( int &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator>>( unsigned int &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator>>( short &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator>>( unsigned short &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}

inline const DataStorage_t& DataStorage_t::operator>>( long &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}
		
inline const DataStorage_t& DataStorage_t::operator>>( unsigned long &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}
		
inline const DataStorage_t& DataStorage_t::operator>>( float &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}
		
		
inline const DataStorage_t& DataStorage_t::operator>>( double &_data)
{
	ReadBuffer(&_data,sizeof(_data));
	return *this;
}
		



#endif /*_DATA_STORAGE_H */
