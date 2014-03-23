// ISBN Processor
// OOP244 - Assignment 2
// ISBNPrefix.cpp
// Shreyas patel
// June 28 2013
#include<iostream>
#include<stdio.h>
#include <cstring>
#include <stdlib.h>
#include"ISBNPrefix.h"

ISBNPrefix::ISBNPrefix(const char* filename)//a one-argument constructor that receives a C-style, null-terminated string containing the name of a file that holds the prefix table
{
      if(filename != NULL)		
            fp=fopen(filename,"r");
      else
            fp=NULL;
}
ISBNPrefix::ISBNPrefix(const ISBNPrefix& source)
{
		fp=NULL;
        fp=source.fp;
}
ISBNPrefix& ISBNPrefix::operator=(const ISBNPrefix& source)
{
	if(this!=&source)
	{
		if(source.fp!=NULL)
		{
			fp=source.fp;
			return *this;
		}
		else
			fp=NULL;
	}
}
bool ISBNPrefix::isRegistered(int area) const //a query that receives an area identifier and determines if the area is listed

{
	int a, ps, pe;
	bool rc=false;
	if(fp != NULL)
	{
		rewind(fp);
		do
		{
			fscanf(fp,"%d%d%d",&a,&ps,&pe);
			if(a == area)
			{
         		rc = true;
			}
        }while(!feof(fp));
	 }
       return rc;
}   
int ISBNPrefix::minNoDigits(int area) const //a query that receives an area identifier and determines the minimum number of digits in any publisher identifier registered under that area
{
	int a, min=0;
    char ps[10],pe[10];
    if(fp!=NULL)
    {
                rewind(fp);
                while(!feof(fp) && min==0)
                {
                                fscanf(fp,"%d%s%s", &a,ps,pe);
                                if(a==area)
                                {
                                           min=strlen(ps);
                                }
                }
    }
    return min;
}
bool ISBNPrefix::isRegistered(int area, const char* publisher) const //a query that receives an area identifier along with a publisher identifier and determines if the publisher identifier is within a publisher range listed under that area
{
	
    int a,ie,is,ii;
    char ps[10],pe[10];
	bool rc=false;
	
    if(fp!=NULL)
    {
		rewind(fp);	
		do
		{
			fscanf(fp,"%d%s%s", &a, ps ,pe);
			if(a==area)
			{
				is=atoi(ps);
				ie=atoi(pe);
				ii=atoi(publisher);
				if(ii<=ie && ii>=is && strlen(publisher)==strlen(ps))
				{
					rc=true;
				}
			 }
		}while(!feof(fp));
	}   
	return rc;
}
ISBNPrefix::~ISBNPrefix()//a destructor that cleans up before the current object goes out of scope 
{
        if (fp!=NULL) 
		{
			fclose(fp);
		}
}



