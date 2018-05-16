#include <string.h>

#include "meeting.h"

string_t::string_t()
{
	m_String= new char;
	m_String[0]='\0';
}


string_t::string_t(const char* _str)
{
	m_String = new char[strlen(_str)+1];
	strcpy(m_String,_str);
		
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
	m_String = new char[strlen(str)+1];
	strcpy (m_String,str);
	
}

const char * string_t::getString()const
{
	return m_String;
}

int string_t::compare(const string_t& str)const
{
	int temp= strcmp(this->m_String,str.m_String);
	
	if(temp>0)
	{
		return 2;
	}
	
	if(temp<0)
	{
		return 1;
	}
	
	return 0;
}

int string_t::contains(const char * str)const
{
	return strstr(this->m_String,str) ? 1:0;
}


void string_t::prepend(const char * str)
{

char *temp = new char[ strlen(str) +  length() + 1];
		
	*temp='\0';
	strcat(temp,str);
	strcat(temp,m_String);
	
	delete[] m_String;
	m_String = temp;
}



void string_t::prepend(const string_t& str)
{

	prepend(str.m_String);
}


