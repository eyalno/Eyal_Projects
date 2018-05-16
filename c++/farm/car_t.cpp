#include <iostream>
using namespace std;
#include <string>

#include "animal_t.h"
#include "subaru_t.h"
#include "ford_t.h"


	int animal_t::s_ID = 0;	

animal_t::animal_t():  
ID(s_ID),capacity(s_capacity)
{
	++s_ID;
}

animal_t::~animal_t()
{}

animal_t::animal_t(int _id,string _name):
ID(_id),name(_name)
{
	++s_ID;
}
	
animal_t::animal_t(const animal_t &car):
ID(car.ID),name(car.name),sound(car.sound)
{}

const animal_t& animal_t::operator=(const animal_t& car)
{
	if (this != &car)
	{
		sound=car.sound;
		name=car.name;	
	}
	return *this;
}


bool animal_t::operator>(const animal_t& animal)const
{
	return ID>animal.ID?true:false;
}

bool animal_t::operator==(const animal_t& animal)const
{
	return ID==animal.ID?true:false;
}

 void animal_t::show()const
{
		cout << "name:" << name << endl;
		cout << "Id:" << ID << endl;
		cout << "sound:" << sound << endl;
}

 void makeSound()const
{
	cout << "sound:" << sound << endl;
}
