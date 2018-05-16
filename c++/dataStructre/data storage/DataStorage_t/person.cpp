/************************************************************************************************
		Author:             Yair Feldman
		Creation date:      11.10.12
		Data last modified: 
		Description:        Class Person - cpp file with functions implimentations for class Person
*************************************************************************************************/

#include <string>
#include <iostream>
#include "person.h"
#include "dataS.h"


Person::Person():
	m_name(""),
	m_age(0)
{}

Person::~Person()
{}
	

void Person::setName(string name)
{
	m_name = name;
}


void Person::setAge(int age)
{
	m_age = age;
}


ostream &operator<< (ostream& os, const Person& p)
{
	return os << p.getName() << " " << p.getAge() ;
}

istream &operator>> (istream& is, Person& p)
{
	char name[128];
	int age;

	is >> name >> age;

	p.setName(name);
	p.setAge(age);

	return is;
}


DataStorage_t& operator<< (DataStorage_t& _ds, const Person& p)
{
	const char* str = p.getName().c_str();

	return _ds << str << p.getAge();

}


DataStorage_t& operator>> (DataStorage_t& _ds, Person& p)
{
	char str[30];
	int age;

	_ds >> str >> age;

	p.setName(str);
	p.setAge(age);

	return _ds;
}





