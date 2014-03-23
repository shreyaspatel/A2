// ISBN Processor
// OOP244 - Assignment 4
//SpecialOrder.h
//shreyas patel
//aug 9, 2013
#include <iostream>
#include <cstring>
using namespace std;
#include "SpecialOrder.h"


/* A no-argument constructor that creates a
   SpecialOrder object in a safe empty state */

SpecialOrder::SpecialOrder()
{
   instruct= NULL;
}

/* A two-argument constructor that creates a
   SpecialOrder object from a reference to an ISBN
   object and the address of a C-style null-terminated
   string containing the special instruct */

SpecialOrder::SpecialOrder(const ISBN& isbn, const char* instr): Order(isbn)
{

   if(instr != NULL)
   {
      instruct= new char[strlen(instr) + 1];
      strcpy(instruct, instr);
   }
   else
      instruct= NULL;
}

/* A copy constructor that receives a
   reference to a SpecialObject object */

SpecialOrder::SpecialOrder(const SpecialOrder& source)
{

   instruct= NULL;
   *this= source;
}

/* A modifier that receives a reference to an istream object
   and adds orders and instruct to the current object */

bool SpecialOrder::add(istream& is)
{

   char Instr[100 + 1];
   bool rc= false;
   Instr[0]= '\0'; 

   if(Order::add(is) == true)
   {
      cout << "instruct : ";
      is.getline(Instr, 100, '\n');
      rc= true;
   }
   if(rc)
   {
      if(instruct != NULL)
         delete [] instruct;

      instruct= new char[strlen(Instr) + 1];
      strcpy(instruct, Instr);
   }

   return rc;
}

/* A query that receives a reference to an output stream
   object and displays a SpecialOrder on output stream os */

void SpecialOrder::display(ostream& os) const
{

   Order::display(os);
   if(instruct != NULL)
      os << " " << instruct;
}

/* An assignment operator that receives a reference to an
   unmodifable SpecialOrder object and copies the information
   in that referenced object into the current object */

SpecialOrder& SpecialOrder::operator=(const SpecialOrder& source)

{

   if(this != &source)
   {
      (Order&)(*this)= source;
      if(instruct != NULL)
         delete [] instruct;
      if(source.instruct != NULL)
      {
         instruct= new char[strlen(source.instruct) + 1];
         strcpy(instruct, source.instruct);
      }s
      else
         instruct= NULL;
   }
   return *this;
}

/* A destructor that cleans up memory before
   the current object goes out of scope */

SpecialOrder::~SpecialOrder()
{

   if(instruct != NULL)
      delete [] instruct;
}
