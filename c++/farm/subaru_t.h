#ifndef SUBARU_T_H
#define SUBARU_T_H

#include "animal_t.h"
enum range{MIN_ID=2001,MAX_ID=3000};

class duck_t:public animal_t
{
	public:	
		duck_t();
		duck_t(const int _id);	
		duck_t (const duck_t &car);
		~duck_t();
		
};

#endif


