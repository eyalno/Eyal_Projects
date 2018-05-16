
#ifndef _memPool_H
#define _memPool_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <list>

#include "memPage.h"

using namespace std;


class memPool_t
{
	public:
		
		memPool_t(int _numPages,int _pageSize = defaultPageSize); //ctor

		memPool_t (const memPool_t &_page); //copy ctor
		
		virtual ~memPool_t(); //dtor

		const memPool_t& operator=(const memPool_t& _page); //assignment operator

		int getDefault(); // page size

		void setDefault(int _pos); //set page size
		
		int get(); //get position

		void set(int _pos); //set position

		bool IsPoolEmpty()const; 
		
		int ActualSize()const;
	

		
		int read(void* _data,int _numBytes,int _pos=0xdeadbeef);
		
		int write(void* _data,int _numBytes,int _pos=0xdeadbeef);
	

	private:
		list<memPage_t*> m_list; //page container
		
		int m_capacity; //total bytes 
		
		int m_currentPosition; //next free pos
		
		
		int copy(void* _data,int _numBytes,int _pos,Mode _mode); //implementation function
		
};


#endif
