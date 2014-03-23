// ISBN Processor
// OOP244 - Assignment 2
// ISBNPrefix.h
// Shreyas patel
// June 28 2013
class ISBNPrefix
{
		FILE *fp;
		ISBNPrefix(const ISBNPrefix& source);
	    ISBNPrefix& operator=(const ISBNPrefix& source);

	public:
		ISBNPrefix(const char* filename);
		bool isRegistered(int area) const;
		int minNoDigits(int area) const;
		bool isRegistered(int area, const char* publisher) const;
		~ISBNPrefix();
};

