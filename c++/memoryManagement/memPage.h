
#ifndef _MEMPAGE_H
#define _MEMPAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

static int defaultPageSize=1024;

typedef enum{READ, WRITE} Mode;

class memPage_t
{
	public:
		memPage_t(int _pageSize = defaultPageSize);

		memPage_t (const memPage_t &_page);
		
		const memPage_t& operator=(const memPage_t& _page);

		int get();

		void set(int _pos);

		bool IsPageEmpty()const;
		
		bool IsPageFull()const;

		int ActualSize()const;
	
		int Capacity()const;

		
		int read(void* _data,int _numBytes,int _pos=0xdeadbeef);
		
		int write(void* _data,int _numBytes,int _pos=0xdeadbeef);
	

	private:
		char* m_page;
		
		int m_capacity; //page size
		
		int m_currentPosition; //next free pos
		
		
		int copy(void* _data,int _numBytes,int _pos,Mode _mode);
		
};

#endif
