/************************************************************************************************
		Author:             Yair Feldman
		Creation date:      17.10.12
		Data last modified: 
		Description:        Class DataStorage_t - header file with functions declerations
*************************************************************************************************/


/* Note: In this implementation copy CTOR and assignment operator are private.
   I don't let user using this functions because I don't think dataStorage should be copied (what if data buffer is to large in size?) */

#include <cstring>
#include <iostream>
using namespace std;


#ifndef __DATA_STORAGE_H__
#define __DATA_STORAGE_H__

#define INIT_SIZE     32
#define INIT_EXT_SIZE 64

class DataStorage_t
{
	public:
		DataStorage_t();															/* dyfault CTOR 									*/
		DataStorage_t(size_t _size);									/* CTOR with predefined dimension */

	 ~DataStorage_t();

		void Reset(){ m_readPos = 0; };								   /* rewinds internal pointer (m_readPos) 			   */
		void Clear(){ m_readPos = 0; m_writePos = 0; };  /* clear object and to prepare it for next usage */
		void XpndValue(size_t _extSize)  {m_extSize = _extSize; }; 	/* internal buffer grow by _extSize when full */
		int NumberOfByte() {return m_writePos; };

	  /* Input/Output operators for all built-in types */

		/* Output operators (buffer to variable) for all built-in types */

		 DataStorage_t& operator>>(char& _data);
		
		 DataStorage_t& operator>>(unsigned char& _data);

		 DataStorage_t& operator>>(int& _data);

		 DataStorage_t& operator>>(unsigned int& _data);

		 DataStorage_t& operator>>(short& _data);

		 DataStorage_t& operator>>(unsigned short& _data);

		 DataStorage_t& operator>>(long& _data);

		 DataStorage_t& operator>>(unsigned long& _data);

 		 DataStorage_t& operator>>(double& _data);

 		 DataStorage_t& operator>>(float& _data);

 		 DataStorage_t& operator>>(bool& _data);

 		 DataStorage_t& operator>>(char* _data);

	 	 /* input operators (variable to buffer) for all built-in types */

		 DataStorage_t& operator<<(char _data);

		 DataStorage_t& operator<<(unsigned char _data);

		 DataStorage_t& operator<<(int _data);

		 DataStorage_t& operator<<(unsigned int _data);

		 DataStorage_t& operator<<(short _data);

		 DataStorage_t& operator<<(unsigned short _data);

		 DataStorage_t& operator<<(long _data);

		 DataStorage_t& operator<<(unsigned long _data);

  	 DataStorage_t& operator<<(double _data);

 	   DataStorage_t& operator<<(float _data);

		 DataStorage_t& operator<<(bool _data);

 		 DataStorage_t& operator<<(const char* _data);

	private:
		
		void WriteData (const void* _src, size_t _numBytes);
		void ReadData  (void* _dst, size_t _numBytes);

		DataStorage_t(const DataStorage_t& _ds);	 		/* private copy CTOR */
		const DataStorage_t& operator=(const DataStorage_t& _ds); /* private assignment operator */

		char*  m_buff;  		// array of chars
		size_t m_size;  		// size of the buffer
		size_t m_extSize;		// size of the extended bytes
		size_t m_readPos;   // read index
		size_t m_writePos;  // write index (number of bytes in buffer)

};

#endif /* __DATA_STORAGE_H__ */
