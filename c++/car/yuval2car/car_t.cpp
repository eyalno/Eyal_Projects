#include <iostream>
using namespace std;
#include <string.h>

#include "car_t.h"
#include "subaru_t.h"
#include "ford_t.h"

int car_t::s_ID=1000;

car_t::car_t()    //constructor
{
	name=NULL;
	++s_ID;
	ID=s_ID;
}

car_t::car_t(const cap _capacity)
{
	capacity=_capacity;
	name=NULL;
	++s_ID;
	ID=s_ID;
}

car_t::car_t(const car_t &car1)
{
	name=new char[strlen(car1.name)+1];
	strcpy(name, car1.name);
	capacity=car1.capacity;
	flag=car1.flag;
	gear=car1.gear;
	++s_ID;
	ID=s_ID;
}

ford_t::ford_t(const car_t &car1) {}

subaru_t::subaru_t(const car_t &car1) {}

ford_t::ford_t()
{
	const char *str={"ford"};
	this->setName(str);
	this->setGear(M);
}

subaru_t::subaru_t()
{
	const char *str={"subaru"};
	this->setName(str);
	this->setGear(M);
}

ford_t::ford_t(const cap _capacity) : car_t(_capacity)
{
	const char *str={"ford"};
	this->setName(str);
	this->setGear(M);
}

subaru_t::subaru_t(const cap _capacity) : car_t(_capacity)
{
	const char *str={"subaru"};
	this->setName(str);
	this->setGear(M);
}

car_t::~car_t()   //destructor
{
	delete[] name;   //bypass
	name=NULL;
}

subaru_t::~subaru_t() {}

ford_t::~ford_t() {}


car_t & car_t::operator=(const car_t &car1)
{
	if (this!=&car1) //to firbid a=a
	{
		delete[] name;
		name=new char[strlen(car1.name)+1];
		strcpy(name, car1.name);
		capacity=car1.capacity;
		flag=car1.flag;
		gear=car1.gear;
		++s_ID;
		ID=s_ID;
	}
	return *this;
}

bool car_t::operator<(const car_t &car1) const
{
	return this->capacity<car1.capacity;
}

bool car_t::compare_name(const car_t &car1) const
{
	return strcmp(this->name, car1.name)==0 ? true : false;
}

void car_t::setCapacity(cap _capacity)
{
	capacity=_capacity;
}

void car_t::setSpeed(speed _flag)
{
	flag=_flag;
}
	
const cap car_t::getCapacity() const
{
	return capacity;
}
	
const speed car_t::getSpeed() const
{
	return flag;
}

const type car_t::getGear() const
{
	return gear; 
}

const int car_t::getID() const
{
	return ID;
}

const char *car_t::getName() const
{
	return name;
}

void car_t::setGear(const type _gear)
{
	gear=_gear;
}

void car_t::setName(const char *_name)
{
	delete[] name;
	name=new char[strlen(_name)+1];
	strcpy(name, _name);
}

void car_t::print() const
{
	cout << "type: " << name;
	cout << " capacity: " << capacity;
	cout << " gear: " << gear;
	cout << " speed flag: " << flag;
	cout << " ID: " << ID << endl;
}