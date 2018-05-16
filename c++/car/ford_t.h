#ifndef FORD_T_H
#define FORD_T_H

#include "car_t.h"

class ford_t:public car_t
{
	public:
	
		ford_t();
		~ford_t();
		ford_t (const ford_t &car);
		ford_t(const int _capacity);	
		const ford_t& operator=(const ford_t& car);
	
};



#endif


