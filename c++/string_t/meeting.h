#ifndef __MEETING_H__
#define __MEETING_H__

class string_t
{
	public:
		string_t();
		string_t(const char *_str);	
		~string_t();
		const string_t& operator=(const string_t& str);
		
		int length( )const;
		void setString(const char * str );
		const char * getString()const;
		int compare(const string_t& str)const;
		int contains(const char * str)const;
		void prepend(const char *str);
		void prepend(const string_t& str);
	private:
		char* m_String;
};

#endif
