#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>

#include <time.h>
#include <iostream>

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

//#include <string.h>





using namespace std;
using namespace xercesc_3_1;

int main(int argc, char **argv)
{
	/*
	   if (argc != 3) {
	   return -1;
	   }
	 */
	try {
		XMLPlatformUtils::Initialize();
	} catch(const XMLException& e) {
		cerr << e.getMessage() << endl;
		return -1;
	}

	XercesDOMParser *parser = new XercesDOMParser;
	try {
		parser->parse(argv[1]);//parsing
	} catch (const OutOfMemoryException& e) {
		cerr << e.getMessage() << endl;
		XMLPlatformUtils::Terminate();
		return -1;
	} catch (const XMLException& e) {
		cerr << e.getMessage() << endl;
		XMLPlatformUtils::Terminate();
		return -1;
	} catch (const DOMException& e) {
		cerr << e.getMessage() << endl;
		XMLPlatformUtils::Terminate();
		return -1;
	} catch (...) {
	}


	/*	
		cout << "Root element tag name: " << XMLString::transcode(root->getTagName()) << endl;//print message

		DOMNodeList *list = root->getElementsByTagName(XMLString::transcode("member")); // list sub memebers 
		for (XMLSize_t i = 0; i < list->getLength(); i++) {
		DOMElement *element = dynamic_cast<DOMElement *>(list->item(i)); 
		DOMNodeList *namelist = element->getElementsByTagName(XMLString::transcode("name"));
		assert(namelist->getLength() == 1);
		cout << "member " << i << " name: " << XMLString::transcode(namelist->item(0)->getTextContent()) << endl;
		}
	 */
	/*
	   if ( clock_gettime( CLOCK_REALTIME, &computerTime) == -1 )
	   {	
	   LogRegister(ERR,"failed to return computer time",__FILE__,__func__)	;
	   free(task);	


	   return ERR_GENERAL;

	   Timespec
#include time.
#include sys/time.h
if (_time1->tv_sec > _time2->tv_sec)
{
return 1;
}
else if (_time1->tv_sec < _time2->tv_sec)
{
return 0;	
}

return (_time1->tv_nsec > _time2->tv_nsec) ? 1:0;
time_t rawtime;

time ( &rawtime );
printf ( "The current local time is: %iss", ctime (&rawtime) );
	 */


string type;
string id;
string clientIp;//connection from
string data1;
string data2;

//rea documataion about exceptions
DOMDocument *doc = parser->getDocument();
DOMElement *root = doc->getDocumentElement();//root

DOMNodeList *list;
//assuming xml file with valid format
list = root->getElementsByTagName(XMLString::transcode("Type")); // list sub memebers 
type = XMLString::transcode(list->item(0)->getTextContent()); 


if( type == "Request")
{
	list = root->getElementsByTagName(XMLString::transcode("RequestedData1")); // list sub memebers 
	if( list->getLength() == 1)
	{
		data1 = XMLString::transcode(list->item(0)->getTextContent()); 
		
		list = root->getElementsByTagName(XMLString::transcode("RequestedData2")); // list sub memebers 
		if (list->getLength() == 1)
		{
			data2 = XMLString::transcode(list->item(0)->getTextContent()); 
		
		}

	}
	
		
}

time_t rawtime;

time ( &rawtime );

int fdc;
struct sockaddr_in  sa;
socklen_t sin_len;


fdc = socket(PF_INET, SOCK_STREAM, 0);
sin_len = sizeof(struct sockaddr);

getsockname(fdc,(struct sockaddr *) &sa, &sin_len);
// i get 0.0.0.0
printf("Local IP address is: %s\n", inet_ntoa(sa.sin_addr));


close (fdc);



XMLCh tempStr[3] = {chLatin_L, chLatin_S, chNull};
DOMImplementation *impl          = DOMImplementationRegistry::getDOMImplementation(tempStr);
DOMLSSerializer   *theSerializer = ((DOMImplementationLS*)impl)->createLSSerializer();
DOMLSOutput       *theOutputDesc = ((DOMImplementationLS*)impl)->createLSOutput();

cout<< XMLString::transcode(theSerializer->writeToString(root))<<endl;
theOutputDesc->release();
theSerializer->release();

list = root->getElementsByTagName(XMLString::transcode("Id")); // list sub memebers 
//list->item(0)->setTextContent();
list = root->getElementsByTagName(XMLString::transcode("TimeArrival")); // list sub memebers 
list->item(0)->setTextContent(XMLString::transcode(ctime (&rawtime)));


list = root->getElementsByTagName(XMLString::transcode("ClientIp")); // list sub memebers 
list->item(0)->setTextContent(XMLString::transcode(ctime (&rawtime)));

//macro define smaller code??	
list = root->getElementsByTagName(XMLString::transcode("ServerIp")); // list sub memebers 



DOMElement* curr;
curr = root->getFirstElementChild();

//curr= curr->getNextElementSibling();

delete parser;
XMLPlatformUtils::Terminate();
return 0;
}
