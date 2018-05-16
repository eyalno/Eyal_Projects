#include <string.h>
#include <ctype.h>
#include "big.h"
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

BigNumber::BigNumber()
{
	number= new char;
	number[0]='\0';
	length=0;
	
}


BigNumber::BigNumber(const char* _obj)
{
	length= strlen(_obj);
	if ((number = new char[length+1]))
	{
		strcpy(number,_obj);
		reverse(number);
	}	
}

BigNumber::BigNumber (const BigNumber &obj)
{
	length=strlen(obj.number);
	if ((number = new char[length+1]))
	{
		strcpy(number,obj.number);
		reverse(number);
	}
}

BigNumber::~BigNumber()
{
	delete[] number;
	length=0;
}

void BigNumber::Print()const
{
	reverse(number);
	puts(number);
	reverse(number);
		
}
const BigNumber& BigNumber::operator=(const BigNumber& obj)
{
	if (this != &obj)
	{
		delete[] number;
		number=new char[obj.length];
		length=obj.length;
		strcpy(number,obj.number);
	}
return *this;
}

const BigNumber& BigNumber::operator=(const int num)
{
	
	char buf[11];
	itoa(num,buf);
	reverse(buf);	
	delete[] number;
	length=strlen(buf);
	number=new char[length+1];
	strcpy(number,buf);
	
return *this;
}

const BigNumber BigNumber::operator+(const BigNumber& obj)const
{
	BigNumber res;
	res.length= 2 + (length >obj.length? length:obj.length);
	
	res.number=new char[ res.length];	
	
	char carry=0;
	int i;
	if (length> obj.length)
	{
		for( i=0;i<obj.length;++i)
		{
			res.number[i]=(carry + obj.number[i] +number[i] -'0' -'0')%10 +'0';
			
			 carry = ((carry + obj.number[i] +number[i] -'0' -'0')/10)?1:0;	
		}
		
		for (;i<length;++i)
		{
			res.number[i]= (carry+number[i] - '0')%10 +'0';
			carry = ((carry + number[i]  -'0')/10)?1:0;	
				
		}
		if (carry)
		{
			res.number[i]='1';
		}
	}	
	else
	{
		for( i=0;i<length;++i)
		{
			res.number[i]=(carry + obj.number[i] +number[i] -'0' -'0')%10 +'0';
			
			carry = ((carry + obj.number[i] +number[i] -'0' -'0')/10)?1:0;	
		}
		
		for (;i<obj.length;++i)
		{
			res.number[i]= (carry+obj.number[i] - '0')%10 +'0';
			carry = ((carry + obj.number[i]  -'0')/10)?1:0;	
				
		}
		if (carry)
		{
			res.number[i]='1';
		}
	}
	
	
	return res;

}



