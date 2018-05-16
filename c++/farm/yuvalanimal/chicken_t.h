#ifndef __CHICKEN_T_H__
#define __CHICKEN_T_H__

class chicken_t:public animal_t
{
public:
	chicken_t();
	chicken_t(const chicken_t &chicken1);   //copy CTOR
	virtual ~chicken_t();
	virtual const chicken_t &operator=(const chicken_t &chicken1);
	
	virtual void show() const;
	virtual void makeSound() const;
private:
	static int ch_ID;
	enum 
	{
		MIN_ID=1001,
		MAX_ID=2000
	};
};

#endif /*#ifndef __CHICKEN_T_H__*/