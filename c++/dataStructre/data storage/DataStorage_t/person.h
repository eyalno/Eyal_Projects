/************************************************************************************************
		Author:             Yair Feldman
		Creation date:      17.10.12
		Data last modified: 
		Description:        Class Person - header file with functions declerations
*************************************************************************************************/

#include <string>
#include <iostream>
#include "dataS.h"
using namespace std;


#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
	public:
		Person();  																								/* CTOR */
	 ~Person();																			/* CTOR with argument */
		
		void setName(string name);
		void setAge(int age);

		string getName() const {return m_name;}
		int    getAge()	 const {return m_age;}

	private:
		string m_name;
		int    m_age;
};

ostream &operator<< (ostream& os, const Person& p);

istream &operator>> (istream& is, Person& p);


DataStorage_t& operator<< (DataStorage_t& _ds, const Person& p);

DataStorage_t& operator>> (DataStorage_t& _ds, Person& p);


#endif /* __PERSON_H__ */
