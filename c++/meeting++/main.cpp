#include <stdio.h>
#include <string.h>

#include "meeting.h"

int main()
{
	char* subject;
	int start,end;
	meeting m1;
	m1.setStart(1);
	m1.setEnd(3);
	m1.setSubject("kobi");
	start=m1.getStart();
	end=m1.getEnd();
	subject=m1.getSubject();
	printf("start time: %d end time: %d subject: %s\n",start,end,subject);	

	return 1;
}
