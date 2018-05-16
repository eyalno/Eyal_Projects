#ifndef CAR_T_H
#define CAR_T_H


#include <iostream>
#include <string>
using namespace std;

enum Gear{Manual,Automatic};
enum Speed{Twenty=1,Fifthy,Hundred};

class animal_t
{
	public:
		animal_t();
		virtual ~animal_t();
		animal_t(int ,string);	
		animal_t (const animal_t &car);
		const animal_t& operator=(const animal_t& car);	
		
		virtual bool operator>(const animal_t& animal)const;
		virtual bool operator==(const animal_t& animal)const;
		virtual void show()const;
		virtual void makeSound()const;
	protected:


	private:
		string name;
		const int ID;
		static int s_ID;
		string sound;
};

//inline functions



#endif


