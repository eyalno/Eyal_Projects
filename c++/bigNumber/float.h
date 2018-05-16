#ifndef STRING_T_H
#define STRING_T_H

class Float
{
	public:
		Float();
		Float(const char *);	
		Float (const Float &);
		~Float();
		
		const Float& operator=(const Float& );
		const Float& operator=(const int );
		const Float operator+(const Float& )const;	
		void Print()const;
			
		inline bool operator>(const Float& )const;
		inline bool operator<(const Float& )const;
		inline bool operator==(const Float& )const;

		private:
		BigNumber num;	
};

//inline functions

inline bool Float::operator< (const Float & num) const
{
	if(length ==num.length)
	{
		return ( strcmp(number,num.number)<0? true : false );
		
	}
	
	return (length < num.length)?true:false;
}

inline bool Float::operator> (const Float &num) const
{
	if(length ==num.length)
	{
		return ( strcmp(number,num.number)>0? true : false );
		
	}
	
	return (length > num.length)?true:false;
}

inline bool Float::operator== (const Float &num) const
{
	return ( strcmp(number,num.number)==0? true : false );
}



#endif


