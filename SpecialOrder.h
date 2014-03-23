// ISBN Processor
// OOP244 - Assignment 4
//SpecialOrder.cpp
//shreyas patel
//aug 9, 2013
#include "Order.h"
class SpecialOrder: public Order
{
      char* instruct;
      public:
             SpecialOrder();
             SpecialOrder(const ISBN& isbn, const char* instr);
             SpecialOrder(const SpecialOrder& source);
             bool add(istream& is);
             void display(ostream& os) const;
             SpecialOrder& operator=(const SpecialOrder& source);
             ~SpecialOrder();
};
