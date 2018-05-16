#ifndef CAR_T_H
#define CAR_T_H


#include <iostream>
#include <string>
using namespace std;

enum Gear{Manual,Automatic};
enum Speed{Twenty=1,Fifthy,Hundred};

class car_t
{
	public:
		car_t();
		virtual ~car_t();
		car_t(int capacity);	
		car_t (const car_t &car);
		const car_t& operator=(const car_t& car);	
		
		virtual void changeSpeed(const Speed& flag);
		virtual const string getName()const;
		inline Gear getGear()const;
		virtual bool compare(const car_t& car) const;
		inline Speed getSpeed()const;
		virtual bool operator<(const car_t& car)const;
		virtual void print()const;
	protected:
		inline void setGear(Gear _gear);		
		inline void setName(const string name);


	private:
		string name;
		Gear gear;
		const int ID;
		Speed flag;
		int capacity;
		static int s_ID;
		static int s_capacity;
};

//inline functions
 
inline Gear car_t::getGear()const
{
	return gear;
}
		
inline Speed car_t::getSpeed()const
{
	return flag;
}



inline void car_t::setGear(Gear _gear)
{
	gear=_gear;	
}		

inline void car_t::setName(const string _name)
{
	name=_name;	
}


#endif


