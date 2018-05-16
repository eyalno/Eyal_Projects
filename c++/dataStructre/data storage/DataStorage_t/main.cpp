/************************************************************************************************
		Author:             Yair Feldman
		Creation date:      17.10.12
		Data last modified: 
		Description:        Class DataStorage_t - main file (Interactive user test)
*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "dataS.h"
#include "person.h"
using namespace std;

#define MAX_NUM_OF_INPUTS 32


enum types_e 	{case_Cahr=1,case_UnChar,case_Int,case_UnInt,case_sh,
							 case_unSh,case_long,case_unLong,case_Dub,case_Flo,case_Bool,
							 case_string};

void clear()
{
	getchar();
	system("clear");
}

void PrintMenu()
{
	cout << "\n1 : Input char" << endl << "2 : Input unsigned char" << endl << "3 : Input int" << endl;
	cout << "4 : Input unsigned int" << endl << "5 : Input short" << endl << "6 : Input unsigned short" << endl 
			 <<	"7 : Input long" << endl << "8 : Input unsigned long" <<endl<< "9 : Input double"<< endl 
			 <<	"10 : Input float"<<endl << "11 : Input bool" <<"\n12 : Input char*"<< endl <<	"13 : Clear data storage"<<endl
			 << "14 : Reset read"<<endl  <<"15 : Set expened value" <<endl <<"16 : Number of bytes in buffer" << endl 
			 <<"17 : Print buffer" <<endl <<"18 : Concatenation example" <<endl<<"19 : Person example"
			 << "\n20 : Exit"<<endl<<	"Enter num. of operation :";
}


void BuffPrint(DataStorage_t& ds,int arr[],int size)
{
	int i;
	
	system("clear");
	cout << "\nAll the data in buffer:\n";

	if(!ds.NumberOfByte())
	{
		cout << "\nbuffer is empty!\n";
		return;
	}

	ds.Reset();
	for(i=0; i < size ;i++)
	{
		switch (arr[i])
		{
			case case_Cahr:
				char c;
				ds >> c;
				cout << c << endl;
				break;
			case case_UnChar:
				unsigned char uc;
				ds >> uc;
				cout << uc << endl;
				break;
			case case_Int:
				int i;
				ds >> i;
				cout << i << endl;
				break;
			case case_UnInt:
				unsigned int ui;
				ds >> ui;
				cout << ui << endl;
				break;
			case case_sh:
				short s;
				ds >> s;
				cout << s << endl;
				break;
			case case_unSh:
				unsigned short us;
				ds >> us;
				cout << us << endl;
				break;
			case case_long:
				long l;
				ds >> l;
				cout << l << endl;
				break;
			case case_unLong:
				unsigned long ul;
				ds >> ul;
				cout << ul << endl;
				break;
		case case_Dub:
				double d;
				ds >> d;
				cout << d << endl;
				break;
		case case_Flo:
				float f;
				ds >> f;
				cout << f << endl;
				break;
		case case_Bool:
				bool b;
				ds >> b;
				cout << b << endl;
				break;
		case case_string:
				char str[128];
				ds >> str;
				cout << str << endl;
				break;
		}
	}
}


int main()
{	

	enum operation_e {case_inCahr=1,case_inUnChar,case_inInt,case_inUnInt,case_sh,
										case_unSh,case_long,case_unLong,case_inDub,case_inFlo,case_bool,
										case_str,case_clearBuff,case_resetRead,case_setExp,case_numByts,
										case_print,case_con,case_person,case_exit};

	int cont = 1;
		
	DataStorage_t ds;
	DataStorage_t dsA;
	DataStorage_t dsB;

	Person p1;
	Person p2;
	int age;
  string name;

	int arrType[MAX_NUM_OF_INPUTS] = {0};
	int index=0;

	cout << "\nData storage class exercise:\n";

	while (cont) {
		int c;

		PrintMenu();
		scanf("%d", &c);
		switch (c)
		{
			case case_inCahr:
				char c;
				clear();
				cout << "\nEnter char: ";
				cin >> c;
				ds  << c;
				arrType[index++] = case_Cahr;
				break;
			case case_inUnChar:
				unsigned char uc;
				clear();
				cout << "\nEnter unsigned char: ";
				cin >> uc;
				ds  << uc;
				arrType[index++] = case_UnChar;
				break;
			case case_inInt:
				int i;
				clear();
				cout << "\nEnter int: ";
				cin >> i;
				ds  << i;
				arrType[index++] = case_Int;
				break;
			case case_inUnInt:
				unsigned int ui;
				clear();
				cout << "\nEnter unsigned int: ";
				cin >> ui;
				ds  << ui;
				arrType[index++] = case_UnInt;
				break;
			case case_sh:
				short s;
				clear();
				cout << "\nEnter short: ";
				cin >> s;
				ds  << s;
				arrType[index++] = case_sh;
				break;
			case case_unSh:
				unsigned short us;
				clear();
				cout << "\nEnter unsigned short: ";
				cin >> us;
				ds  << us;
				arrType[index++] = case_unSh;
				break;
		case case_long:
				long l;
				clear();
				cout << "\nEnter long: ";
				cin >> l;
				ds  << l;
				arrType[index++] = case_long;
				break;
		case case_unLong:
				unsigned long ul;
				clear();
				cout << "\nEnter unsigned long: ";
				cin >> ul;
				ds  << ul;
				arrType[index++] = case_unLong;
				break;
		case case_inDub:
				double d;
				clear();
				cout << "\nEnter double: ";
				cin >> d;
				ds  << d;
				arrType[index++] = case_Dub;
				break;
		case case_inFlo:
				float f;
				clear();
				cout << "\nEnter float: ";
				cin >> f;
				ds  << f;
				arrType[index++] = case_Flo;
				break;
		case case_bool:
				bool b;
				clear();
				cout << "\nEnter bool value (0 or 1): ";
				cin >> b;
				ds  << b;
				arrType[index++] = case_bool;
				break;
		case case_str:
				char str[128];
				clear();
				cout << "\nEnter string: ";
				cin >> str;
				ds  << str;
				arrType[index++] = case_string;
				break;
		case case_clearBuff:
				clear();
				ds.Clear();
				cout << "\nBuffer is cleard\n";
				index = 0;
				break;
		case case_resetRead:
				clear();
				ds.Reset();
				cout << "\nBuffer read is cleared\n";
				break;
		case case_setExp:
				int exp;
				clear();
				cout << "\nEnter expened size\n";
				cin >> exp;
				ds.XpndValue(exp);
				break;
		case case_numByts:
				clear();
				cout << "\nNumber of bytes in buffer is: " << ds.NumberOfByte() << endl;
				break;
		case case_print:
				BuffPrint(ds,arrType,index);
				break;
	case case_con:
				float ff;char strB[32];int iB;
				clear();
				cout << "\nenter float, string and int:\n";
				cin >> ff >> strB >> iB;
				dsA	<< ff << strB << iB;
				ff=0; iB=0; strB[0] = 0;
 				cout << "\nData in buffer dsA:\n";
				dsA >> ff >> strB >> iB;
				cout << ff <<" ,"<< strB <<" ,"<< iB << endl;
				break;
		case case_person:
				clear();
				dsB.Clear();
				cout << "\nSet name and age for person A: " << endl;
				cin >> name >> age;
				p1.setName(name);
				p1.setAge(age);
				dsB << p1;
				cout << "This is person A\n";
				cout << p1 << endl;
				dsB >> p2;
				cout << "This is person B\n";
				cout << p2 << endl;
				break;
		case case_exit:
				cont = 0;
				break;
				default:
				system("clear");
				printf("\nWrong operation number.\n"); 
				break;
		}
	}

	return 0;
}

