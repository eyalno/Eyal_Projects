/************************************************************************

		Author: Eyal Noy
		Creation date: 5.11.12
		Last modified date: 5.11.12
		Description: Stack  header file nested class implementation using linkedlist 
		Text Editor:  gVim
***********************************************************************/


#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


template <class T>
class TException_t : public exception 
{
	public:
		TException_t(T _object,const char* _message,const char* _fileName,int _lineNumber) throw()
		{
			m_str.append(_message );

			m_str.append(_fileName);
		//	m_str.append(_lineNumber); 
			m_object=_object;
		}

		
		virtual const char* what() const throw()
		{
			return m_str;
		}
		~TException_t() throw (){}	
	private:

		T m_object;
		string m_str;
		
};
#endif
