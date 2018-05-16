#ifndef __SUBARU_T_H__
#define __SUBARU_T_H__

#include "car_t.h"

class subaru_t:public car_t
{
public:
	subaru_t();
	subaru_t(const cap capacity);   //CTOR from known capacity
	subaru_t(const car_t &car1);   //copy CTOR
	~subaru_t();
};

#endif /*#ifndef __SUBARU_H__*/

