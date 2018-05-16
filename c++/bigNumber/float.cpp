#include <string.h>
#include <ctype.h>
#include "string_t.h"
#include <stdio.h>

//auxiliry functions
static void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

static char* itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0) 
		n = -n;
	
	i = 0;
	do {

		s[i++] = n % 10 + '0'; 
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return s;
}

Float::Float()
{
	BigNumber tmp;
	num=tmp;
}


Float::Float(const char* _obj)
{
	BigNumber tmp(_obj);
	num=tmp;
		
}

Float::Float (const Float &obj)
{
	BigNumber tmp(obj);
	num=tmp;
	
}

Float::~Float()
{
	num.~BigNumber();
}

void Float::Print()const
{
	num.Print();	
}
const Float& Float::operator=(const Float& obj)
{
	if (this != &obj)
	{
		num=obj.num;
	}
return *this;
}

const Float Float::operator+(const Float& obj)const
{
	int loc =-1;
	char *tmp;

	tmp =new char[(num.length >obj.num.length ?num.length:obj.num.length) +1];
	memset(tmp,'0',abs(num.length -obj.num.length));
	strcat(tmp+abs(num.length -obj.num.length),num.length >obj.num.length ? obj.num.number:num.number);

	for (int i=0; i<num.length;++i)
	{
		if (num.number[i]== '.')
		{
			loc =i;
		}
	}

	num.number[i]=obj.num.number[i]='9';
	
	num.number[i]=obj.num.number[i]='.';

}



