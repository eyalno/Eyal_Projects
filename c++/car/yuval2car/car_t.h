#ifndef __CAR_T_H__
#define __CAR_T_H__

typedef enum 
{
    A=1,       // automatic
    M          // manual
} type;

typedef enum 
{
    ZtoT=1,         
    TtoF,          
    FtoH
} speed;

typedef enum 
{
    CC_1500=1,         
    CC_1800
} cap;

class car_t
{
public:
	car_t();
	car_t(const cap _capacity);   //CTOR from known capacity
	car_t(const car_t &car1);   //copy CTOR
	~car_t();
	car_t & operator=(const car_t &car1);
	bool operator<(const car_t &car1) const;
	bool compare_name(const car_t &car1) const;
	void setCapacity(cap _capacity);
	void setSpeed(speed _flag1);
	const cap getCapacity() const;
	const speed getSpeed() const;
	const type getGear() const;
	const int getID() const;
	const char *getName() const;
	void print() const;
protected:
	void setGear(const type _gear);
	void setName(const char *name);
private:
	char *name;
	type gear;
	cap capacity;
	speed flag;
	int ID;
	static int s_ID;
};

#endif /*#ifndef __CAR_H__*/

