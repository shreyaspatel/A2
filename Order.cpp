// ISBN Processor
// OOP244 - Assignment 4
//Order.cpp
//shreyas patel
//aug 9, 2013
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Order.h"
 Order::Order()
{
 
	ISBN empty;
	isbnNo= empty;
	ordered=delivered= 0;
}

Order::Order(const ISBN& isbn)
{
 
	isbnNo= isbn;
	ordered=delivered= 0;
}
bool Order::has(const ISBN& isbn) const
{ 
   if (isbnNo==isbn)
      return true;
   else
      return false;
} 
int Order::outstanding() const
{
	return ordered;
} 
bool Order::add(istream& is)
{
 
    int chk= 0,qty= 0;
	bool rc= false;
  do{
      cout << "Quantity (0 to quit) : ";
      is >> qty;
 
      if(qty<0)
	  {
         cout<< "Invalid characters. Try again." << endl;
    
      }
      else if(qty < 0)
	  {
         cout << "Enter a positive number. Try again." << endl;
      }
      else if(qty == 0)
	  {
         cout << "** No order placed!" << endl;
         chk= 1;
      }
      else
	  {
         rc= true;
         ordered+= qty;
      }
   }while(chk== 0 && !rc);
 
   return rc;
}
bool Order::add(int n)
{
 
   if(n > 0 && !(isbnNo==ISBN()))
   { 
      ordered+= n;
      return true;
   }
   else
      return false;
}
 bool Order::receive(istream& is)
 {
 
	bool rc= false;
	int recieved= 0;
	int chk= 0;
	do{
		cout << "Quantity (0 to quit) : ";
		is >> recieved;
 
		if(recieved<0 && recieved>ordered)
		{
			cout<< "Invalid characters. Try again." << endl;
		}
		else if(recieved > outstanding())
		{
			cout << recieved << " not on order. Only "
              << outstanding() << " are on order.  Try again."
              << endl;      
		}
		else if(recieved < 0)
		{
			cout << "Enter a positive number. Try again." << endl;
		}
		else if(recieved == 0)
		{
			cout << "** No delivery recorded!" << endl;
			chk= 1;
		}
		else
		{
			rc= true;
			delivered+= recieved;
		}
   }while(chk== 0 && !rc);
 
   return rc;
}
void Order::display(ostream& os) const{
 
   os << right << setw(13) << isbnNo
      << setw(9) << ordered
      << setw(11) << delivered;
}
ostream& operator<<(ostream& os, const Order& order)
{
	order.display(os);
   return os;
}
