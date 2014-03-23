// ISBN Processor
// OOP244 - Assignment 4
// ISBNP.h
// Shreyas patel
//aug 9, 2013
#include <ostream>
using namespace std;

class ISBNPrefix;
class ISBN
{
	char isbn[11];
	char area[6];
	char publisher[8];
	char title[8];
	bool valid;
	bool registred;
	bool isRegistered(const ISBNPrefix& list);
public:
	ISBN();
	ISBN(const char* str, const ISBNPrefix& 
    list);
	bool empty() const;
	bool isRegistered() const;
	void toStr(char* str) const;
	void toStrWithStyle(char* str) const;
	void display(ostream& os) const;
	bool read(istream& is, const ISBNPrefix& list);

};
int isValid(const char* str);
bool operator==(const ISBN& left, const ISBN& right);
ostream& operator<<(ostream& os, const ISBN& isbn);
