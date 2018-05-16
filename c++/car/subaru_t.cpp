#include <iostream>
using namespace std;
#include <string>

#include "car_t.h"
#include "subaru_t.h"


//***************************	
subaru_t::subaru_t()
{
	setName("subaru");
	setGear(Manual);	
}

subaru_t::~subaru_t()
{}		

subaru_t::subaru_t(const int _capacity):car_t(_capacity)
{
	setName("subaru");
	setGear(Manual);	
}
		
subaru_t::subaru_t(const subaru_t &car):car_t(car)
{}

const subaru_t& subaru_t::operator=(const subaru_t& car)
{
	car_t::operator=car;
	return *this;
}

