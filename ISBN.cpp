// ISBN Processor
// OOP244 - Assignment 4
// ISBN.cpp
// Shreyas patel
//aug 9, 2013
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <ostream>
#include <iomanip> 
#include "ISBNPrefix.h"
#include "ISBN.h"
using namespace std;
 
ISBN::ISBN()//a no-argument constructor that creates an ISBN object in a safe empty state
{
	 isbn[0]='\0';
	 area[0]='\0';
	 publisher[0]='\0';
	 title[0]='\0';
	 registred=false;
	 valid=true;
} 
ISBN::ISBN(const char* str, const ISBNPrefix& list)//a two-argument constructor that creates an ISBN object from a C-style, null-terminated string and checks for registration using a reference to an ISBNPrefix object
{
			if(isValid(str)==1)
			{
				strcpy(isbn,str);
				registred=isRegistered(list);
				valid=false;
			}
			else
			{
				*this = ISBN();
			}

}
bool ISBN::isRegistered(const ISBNPrefix& list)//a private modifier that receives a reference to an ISBNPrefix object and, if possible, decomposes an ISBN string into area, publisher and title components

{
	int i;
	int al=0,pl=0,ia=0;
	for(i=0;i<5;i++)
	{
		area[i]=isbn[i];
		area[i+1]='\0';
		ia=atoi(area);
		if(list.isRegistered(ia))
		{
			i=5;
			al=strlen(area);
		}		
	}
    if(al!=0)
	{
		for(i=0;i<7;i++)
		{
			publisher[i]=isbn[al+i];
			publisher[i+1]='\0';
			if(list.isRegistered(ia,publisher))
			{
				i=7;
				pl=strlen(publisher);
			}
		}
		registred=true;

	}
	else
		registred=false;
    if(pl!=0)
    {
		for(i=0;i<(9-pl-al);i++)
        {
			title[i]=isbn[pl+al+i];
            title[i+1]='\0';
        }
		registred=true;

     }
     else
       	registred=false;
return registred;
}
bool ISBN::empty() const //a query that returns true if the object is in a safe empty state, false otherwise

{ 
	return valid;
}
bool ISBN::isRegistered() const //a query that returns true if the object is registered, false otherwise

{
	 return registred;
}
void ISBN::toStr(char* str) const //a query that passes the ISBN string through the function's parameter in the form of an unformatted, C-style, null-terminated string
{
 
        strcpy(str,isbn);
}
void ISBN::toStrWithStyle(char* str) const //a query that returns the ISBN string through the function's parameter in the form of a formatted C-style null-terminated string
{
	if(registred && str!=NULL) //concate the area, publisher, and title using dash style if string is registred 
	{
				strcpy(str,area);
                strcat(str,"-");
                strcat(str,publisher);
                strcat(str,"-");
                strcat(str,title);
                strcat(str,"-");
				char s[2]={isbn[9],'\0'};
				strcat(str,s);

    }
	else if(!registred && str!=NULL)//pass the sting to tostr() fuction if it's not registred.
	{
		toStr(str);
	}
}
void ISBN::display(ostream & os) const //a query that receives a reference to an ostream object and inserts the ISBN string in the current output style into the output stream os 
{
    if (!registred) 
	{
		os<<isbn;
	}
    else 
	{
		char temp[15];
        toStrWithStyle(temp); 
        os<<temp;
    }
}
bool ISBN::read(istream& is, const ISBNPrefix& list) //a modifier that receives a reference to an istream object along with a reference to an ISBNPrefix object, reads an ISBN string from the input stream and, if possible, stores it in the current object
{
    char str[11];
    bool quit=false;
	bool ck=false;

	do{
        cout<<"ISBN (0 to quit) : ";
        is.getline(str,11); 
		if(strcmp(str,"0")==0)
		{
            quit=true;
		}
		else if(strlen(str)<10)
		{
			cout<<" Too few characters. Try again."<<endl;//display this message if the string is less than 10 character
		}
		else if (isValid(str)==1)
        {
			 *this=ISBN(str,list);// store the isbn into current object if it's valid
				ck=true;//
		}
        else if(isValid(str)==0)
        {
            *this=ISBN();//set the curent object into safe empty state if isbn is not valid
            cout<<" Invalid check digit. Try again."<<endl;
		}
		
    } while(!quit&&!ck);
return strcmp(str, "0");
}
 int isValid(const char* str) //a function that receives the string of a C-style null-terminated string and checks if the string is a valid ISBN
{   
   int sum=0,i,rc=0;
	if(str!=NULL)
	{	
    	for(i=0;i<9;i++)
    	{
                     sum+=(str[i]-48)*(10-i);
    	}
    	if(str[9]=='X')    	
    	{	
                            sum+=10;
                 
   		}
    	else
		{
        sum+=str[9]-48;
        }
    	if(sum%11==0)
		{
                 rc=1;
		}
	}
return rc;
}
bool operator==(const ISBN& left, const ISBN& right) 
{
    char leftisbn[11],rightisbn[11];
	bool rc=false;
	right.toStr(rightisbn);
    left.toStr(leftisbn);
	if (strcmp(leftisbn, rightisbn) == 0)
		rc=true;
return rc;
}
ostream& operator<<(ostream& os, const ISBN& isbn)
{
    isbn.display(os);
    return os;
}



