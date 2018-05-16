#ifndef STRING_T_H
#define STRING_T_H

class string_t
{
	public:
		string_t();
		string_t(const char *_str);	
		string_t (const string_t &str);
		~string_t();
		const string_t& operator=(const string_t& str);
		
		int length( )const;
		void setString(const char * str );
		const char * getString()const;
		int compare(const string_t& str)const;
		int contains(const char * str)const;
		void prepend(const char *str);
		
		void convertCase(int (*)(int) );
		int findIndex (const char* (*)(const char*,int),const char c)const;
		
		inline bool operator>(const string_t& str)const;
		inline bool operator<(const string_t& str)const;
		inline bool operator>=(const string_t& str)const;
		inline bool operator<=(const string_t& str)const;
		inline bool operator==(const string_t& str)const;
		inline bool operator!=(const string_t& str)const;
		const string_t& operator+=(const char* str);	
		const string_t operator()(const unsigned int start,const unsigned int len);
		char operator[](const int ) const;
	
		inline operator const char*() const;




		private:
		char* m_String;
		static const bool caseSens=false;
};

//inline functions

inline string_t::operator  const char*() const
{
	return m_String;
}

inline bool string_t::operator< (const string_t &str) const
{
	return ( compare(str)==1? true : false );
}

inline bool string_t::operator>= (const string_t &str) const
{
	return ( *this<str? false : true );
}

inline bool string_t::operator> (const string_t &str) const
{
	return ( compare(str)==2? true : false );
}

inline bool string_t::operator<= (const string_t &str) const
{
	return ( *this>str? false : true );
}

inline bool string_t::operator!= (const string_t &str) const
{
	return ( compare(str)==0? false : true );
}

inline bool string_t::operator== (const string_t &str) const
{
	return ( compare(str)==0? true : false );
}



#endif


