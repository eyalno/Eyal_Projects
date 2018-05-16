#ifndef __MEETING_H__
#define __MEETING_H__

class meeting
{
	public:
			 meeting();
			 ~meeting();
		void setStart(int start);
		void setEnd(int end);
		void setSubject(const char* subject);
		int getStart();
		int getEnd();
		char* getSubject();
	private:
		int m_start;
		int m_end;
		char* m_subject;
};

#endif
