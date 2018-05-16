#include <string.h>
#include <ctype.h>
#include "string_t.h"

string_t::string_t()
{
	m_String= new char;
	m_String[0]='\0';
	
}


string_t::string_t(const char* _str)
{
	if ((m_String = new char[strlen(_str)+1]))
	{
		strcpy(m_String,_str);
	}	
}
string_t::string_t (const string_t &str)
{
	if ((m_String = new char[strlen(str.m_String)+1]))
	{
		strcpy(m_String,str.m_String);
	}
}

string_t::~string_t()
{
	delete[] m_String;
}


const string_t& string_t::operator=(const string_t& str)
{
	if (this != &str)
	{
		setString(str.m_String);
	}
return *this;
}


int string_t::length( )const
{
	return strlen(m_String);
}

void string_t::setString(const char * str )
{
	delete[] m_String;
	if((m_String = new char[strlen(str)+1]))
	{
		strcpy (m_String,str);
	}
}

const char * string_t::getString()const
{
	return m_String;
}

int string_t::compare(const string_t& str)const
{
if (this !=&str)
{	
	int temp;
	
	
	if (caseSens==false)	
	{
		string_t temp1,temp2;
		temp1=*this;
		temp2=str;
		temp1.convertCase(toupper);
		temp2.convertCase(toupper);
		temp= strcmp(temp1,temp2);
	}
	else			
	{
		temp=strcmp(m_String,str);
	}

	if(temp>0)
	{
		return 2;
	}
	
	if(temp<0)
	{
		return 1;
	}
}	
	return 0;
}

int string_t::contains(const char * str)const
{
	if (caseSens==false)	
	{
		string_t temp1,temp2;
		temp1=*this;
		temp2=str;
		temp1.convertCase(toupper);
		temp2.convertCase(toupper);
		return strstr(temp1,temp2) ? 1:0;
	}
	else			
	{
		return strstr(m_String,str) ? 1:0;
	}
}


void string_t::prepend(const char * str)
{

	
	if (char *temp = new char[ strlen(str) +  length() + 1])
	{	
		*temp='\0';
		strcat(temp,str);
		strcat(temp,m_String);
		delete[] m_String;
		m_String = temp;
	}

}


void string_t::convertCase(int (*foo)(int) )
{
char *tmp=m_String;

while(*tmp)
{
*tmp=foo(*tmp);	
++tmp;
}

}

int string_t::findIndex(const char* (*foo)(const char*,int),const char c)const
{
	const char* ptr= foo(m_String,c);
	return ( (ptr) ? ptr-m_String : -1);
}



const string_t& string_t::operator+=(const char* str)
{
	
	string_t tmp(m_String);
	delete[] m_String;
	m_String= new char[strlen(m_String)+strlen(str)+1];
	strcpy(m_String,tmp.m_String);
	strcat(m_String,str);
	return *this;

}
 
const string_t string_t::operator()(const unsigned int start,const unsigned int len)
{
if (start + len > strlen(m_String))
{
	return NULL ;
}
char *tmp=new char[len+1];

strncpy(tmp,m_String+start,len);
tmp[start+len]='\0';

string_t newStr(tmp);
delete[] tmp;
return newStr;
}

char string_t::operator[] (const int _index) const
{
	
	return	( (_index>=0) && (_index < (int)strlen(m_String)) )? m_String[_index]:'\0';
}






