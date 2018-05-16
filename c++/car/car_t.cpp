#include <iostream>
using namespace std;
#include <string>

#include "car_t.h"
#include "subaru_t.h"
#include "ford_t.h"


	int car_t::s_ID = 0;	
	int car_t::s_capacity = 1500;

car_t::car_t():  
ID(s_ID),capacity(s_capacity)
{
	++s_ID;
}

car_t::~car_t()
{}

car_t::car_t(int _capacity):
ID(s_ID),capacity(_capacity)
{
	++s_ID;
}
	
car_t::car_t(const car_t &car):
name(car.name),gear(car.gear),ID(car.ID),flag(car.flag),capacity(car.capacity)
{}

const car_t& car_t::operator=(const car_t& car)
{
	if (this != &car)
	{
		flag=car.flag;
		capacity=car.capacity;
		gear=car.gear;
		i
	}
	return *this;
}


void car_t::changeSpeed(const Speed& _flag)
{
	flag=_flag;
}
const string car_t::getName()const
{
	return name;
}

bool car_t::compare(const car_t& car) const
{
	return name.(car.name)?false:true;
}

bool car_t::operator<(const car_t& car)const
{
	return capacity<car.capacity?true:false;
}

inline void car_t::print()const
{
		cout << "name:" << name << endl;
		cout << "gear:" << gear << endl;
		cout << "Id:" << ID << endl;
		cout << "speed:" << flag << endl;
		cout << "capacity:" << capacity << endl;

}

