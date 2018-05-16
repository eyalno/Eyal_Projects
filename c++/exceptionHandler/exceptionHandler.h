/************************************************************************

		Author: Eyal Noy
		Creation date: 5.11.12
		Last modified date: 5.11.12
		Description: exception handler example
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
		TException_t(T _object,string _message,string _fileName,int _lineNumber) throw()
		{
		
			m_fileName=_fileName;
			m_message=_message;
			m_lineNumbr=_lineNumber;

			m_object=_object;
		}

		
		virtual const char* what() const throw()
		{
			return m_message.c_str();
		}
		
		const string& FileName()const
		{
			return m_fileName;
		}
		
		const int LineNumber()const
		{
			return m_lineNumbr;
		}

		~TException_t() throw ()
		{
			
			
		}	
	private:

		T m_object;
		string m_fileName;
		string m_message;
		int m_lineNumbr;
		
};
#endif
