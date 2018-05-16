#ifndef FORD_T_H
#define FORD_T_H

#include "animal_t.h"
enum range{MIN_ID=1,MAX_ID=1000};


class cow_t:public animal_t
{
	public:
	
		cow_t();
		cow_t (const cow_t &car);
		~cow_t();
	
};



#endif


