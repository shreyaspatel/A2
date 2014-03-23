// ISBN Processor
// OOP244 - Assignment 4
//Order.h
//shreyas patel
//aug 9, 2013
#include <cstdio>  
#include <cstdlib>  
#include <cstring>
#include <iostream>
using namespace std;
#include "ISBN.h"

class Order 
{
        int ordered;
		int delivered;
        ISBN isbnNo;

    public:
		Order();
		Order(const ISBN& isbn);
		bool has(const ISBN& isbn) const;
		int outstanding() const;
		virtual bool add(istream& is);
		bool add(int n);
		bool receive(istream& is);
		virtual void display(ostream& os) const;
};
ostream& operator<<(ostream& os, const Order& order);
