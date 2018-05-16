#include <iostream>
#include <string>
using namespace std;

#include "animal_t.h"
#include "chicken_t.h"
#include "cow_t.h"
#include "duck_t.h"

int duck_t::d_ID=MIN_ID;
int chicken_t::ch_ID=MIN_ID;
int cow_t::c_ID=MIN_ID;

animal_t::animal_t():ID(0) {}   //constructor

animal_t::animal_t(const string str, const int _ID):ID(_ID)
{
	name=str;
}

duck_t::duck_t() : animal_t("duck", d_ID)
{
	++d_ID;
}

cow_t::cow_t() : animal_t("cow", c_ID)    //constructor
{
	++c_ID;
}

chicken_t::chicken_t() : animal_t("chicken", ch_ID)   //constructor
{
	++ch_ID;
}

animal_t::animal_t(const animal_t &animal1):ID(animal1.ID+1)
{
	name=animal1.name;
}

chicken_t::chicken_t(const chicken_t &chicken1) : animal_t(chicken1)
{
	++ch_ID;
}

cow_t::cow_t(const cow_t &cow1) : animal_t(cow1)
{
	++c_ID;
}

duck_t::duck_t(const duck_t &duck1) : animal_t(duck1)
{
	++d_ID;
}

animal_t::~animal_t() {}  //destructor

chicken_t::~chicken_t() {}

cow_t::~cow_t() {}

duck_t::~duck_t() {}

const animal_t &animal_t::operator=(const animal_t &animal1)
{
	name=animal1.name;
	return *this;
}

const duck_t &duck_t::operator=(const duck_t &duck1) 
{
	animal_t::operator=(duck1);
	++d_ID;
	return *this;
}

const chicken_t &chicken_t::operator=(const chicken_t &chicken1)
{
	animal_t::operator=(chicken1);
	++ch_ID;
	return *this;
}

const cow_t &cow_t::operator=(const cow_t &cow1)
{
	animal_t::operator=(cow1);
	++c_ID;
	return *this;
}

bool animal_t::operator>(const animal_t &animal1) const
{
	return this->ID>animal1.ID;
}

bool animal_t::operator==(const animal_t &animal1) const
{
	return false;
}

const int animal_t::getID() const
{
	return ID;
}

const string animal_t::getName() const
{
	return name;
}

void animal_t::makeSound() const  {}

void duck_t::makeSound() const
{
	cout << "gaa!" << endl;
}

void chicken_t::makeSound() const
{
	cout << "coocooricoo!" << endl;
}

void cow_t::makeSound() const
{
	cout << "mooo!" << endl;
}

void animal_t::show() const 
{
	cout << "this is your animal: ";
}

void duck_t::show() const
{
	animal_t::show();
	cout << "name: duck. ID: " << this->getID() << endl;
}

void chicken_t::show() const
{
	animal_t::show();
	cout << "name: chicken. ID: " << this->getID() << endl;
}

void cow_t::show() const
{
	animal_t::show();
	cout << "name: cow. ID: " << this->getID() << endl;
}