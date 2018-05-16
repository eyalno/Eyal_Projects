#ifndef __FORD_T_H__
#define __FORD_T_H__

#include "car_t.h"

class ford_t:public car_t
{
public:
	ford_t();
	ford_t(const cap capacity);   //CTOR from known capacity
	ford_t(const car_t &car1);   //copy CTOR
	~ford_t();
};

#endif /*#ifndef __FORD_H__*/

