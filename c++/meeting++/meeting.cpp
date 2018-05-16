#include <string.h>

#include "meeting.h"

meeting::meeting()
{
	m_start=m_end=0;
	m_subject=0;
}
meeting::~meeting()
{
	delete[] m_subject;
	m_subject=0;/*protection for multiple callings*/
}
void meeting::setStart(int start)
{
	m_start=start;
}
void meeting::setEnd(int end)
{
	m_end=end;
}
void meeting::setSubject(const char* subject)
{
	delete[] m_subject;
	m_subject= new char[strlen(subject)+1];
	strcpy(m_subject,subject);
}
int meeting::getStart()
{
	return m_start;
}
int meeting::getEnd()
{
	return m_end;
}
char* meeting::getSubject()
{
	return m_subject;
}

