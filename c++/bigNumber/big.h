#ifndef STRING_T_H
#define STRING_T_H

class BigNumber
{
	public:
		BigNumber();
		BigNumber(const char *);	
		BigNumber (const BigNumber &);
		~BigNumber();
		
		const BigNumber& operator=(const BigNumber& );
		const BigNumber& operator=(const int );
		const BigNumber operator+(const BigNumber& )const;	
		void Print()const;
			
		inline bool operator>(const BigNumber& )const;
		inline bool operator<(const BigNumber& )const;
		inline bool operator==(const BigNumber& )const;

		private:
		char* number;
		int length;
		
};

//inline functions

inline bool BigNumber::operator< (const BigNumber & num) const
{
	if(length ==num.length)
	{
		return ( strcmp(number,num.number)<0? true : false );
		
	}
	
	return (length < num.length)?true:false;
}

inline bool BigNumber::operator> (const BigNumber &num) const
{
	if(length ==num.length)
	{
		return ( strcmp(number,num.number)>0? true : false );
		
	}
	
	return (length > num.length)?true:false;
}

inline bool BigNumber::operator== (const BigNumber &num) const
{
	return ( strcmp(number,num.number)==0? true : false );
}



#endif


