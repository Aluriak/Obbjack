#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED



/*
 * LIBRARIES
 */
// STD LIB
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <ostream>
// LOCAL MODULES
#include "../utils/utils.h"




/*
 * DEFINES
 */




/*
 * PREDECLARATIONS
 */





/*
 * CLASS
 */
class Date {
	public:
	// CONSTRUCTOR
                Date(unsigned int, unsigned int, unsigned int); // given date with day, month and year
		Date(); // Actual date
		~Date();
	// PUBLIC METHODS
                std::string toStdString() const;
	// STATIC METHODS
                static Date from(std::string);
	// OPERATORS
                operator std::string(); // return "JJ/MM/YYYY"
                bool operator<(const Date&);
                bool operator>(const Date&);
	// ACCESSORS
	private:
	// ATTRIBUTES
                struct tm date;
	// PRIVATE METHODS
};


// EXTERN METHODS
std::ostream& operator<<(std::ostream&, const Date&);



#endif
