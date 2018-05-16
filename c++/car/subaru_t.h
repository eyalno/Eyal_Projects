#ifndef SUBARU_T_H
#define SUBARU_T_H

#include "car_t.h"

class subaru_t:public car_t
{
	public:
		subaru_t();
		~subaru_t();
		subaru_t (const subaru_t &car);
		subaru_t(const int _capacity);	
		const subaru_t& operator=(const subaru_t& car);
};
#endif


