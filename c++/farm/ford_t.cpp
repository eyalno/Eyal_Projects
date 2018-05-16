#include <iostream>
using namespace std;
#include <string>

#include "car_t.h"
#include "subaru_t.h"


ford_t::ford_t()
{
	setName("ford");
	setGear(Automatic);	
}

ford_t::~ford_t()
{}		

ford_t::ford_t(const int _capacity):car_t(_capacity)
{
	setName("ford");
	setGear(Automatic);	
}
		
ford_t::ford_t(const ford_t &car):car_t(car)
{}

const ford_t& ford_t::operator=(const ford_t& car)
{
	car_t::operator=car;
	return *this;
}


