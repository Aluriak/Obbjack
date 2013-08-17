#include "date.h"

using namespace std;


/***************************************************
 * CONSTRUCTOR
 ***************************************************/
// given date with day, month and year
Date::Date(unsigned int day, unsigned int month, unsigned int year) {
        date.tm_mday = day;
        date.tm_mon  = month - 1;
        date.tm_year = year - 1900;
        date.tm_hour = 0;
        date.tm_min  = 0;
        date.tm_sec  = 0;
}

// Current date
Date::Date() {
        time_t t = time(NULL);
        date = *localtime(&t);
}


Date::~Date() {
}


/***************************************************
 * PUBLIC METHODS
 ***************************************************/
std::string Date::toStdString() const {
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", &date);
        return string(buffer);
}





/***************************************************
 * STATIC METHODS
 ***************************************************/
Date Date::from(std::string str) {
// INITIALIZATION
        string value = "";
        int index = 0;
        Date date(0,0,0);
        str += '/';
// TREATMENT
        for(unsigned int i = 0, count = str.size(); i < count; i++) {
                if(str[i] == '/') {
                        if(index == 0)          date.date.tm_mday = str2int(value); 
                        else if(index == 1)     date.date.tm_mon  = str2int(value) - 1;
                        else if(index == 2)     date.date.tm_year = str2int(value) - 1900;
                        index++;
                        value = "";
                } else {
                        value += str[i];
                }
        }
// ENDING
        return date;
}






/***************************************************
 * ACCESSORS
 ***************************************************/





/***************************************************
 * OPERATORS
 ***************************************************/
/*
 * CONVERSION OPERATORS
 */
Date::operator string() {
        return toStdString();
}


/*
 * COMPARISON OPERATORS
 */
bool Date::operator<(const Date& d) {
        return (        difftime(const_mktime(&d.date), const_mktime(&date)) > 0    );
}
bool Date::operator>(const Date& d) {
        return (        difftime(const_mktime(&d.date), const_mktime(&date)) < 0    );
}




/***************************************************
 * PRIVATE METHODS
 ***************************************************/





/***************************************************
 * EXTERN METHODS
 ***************************************************/
ostream& operator<<(ostream& stream, const Date& date) {
        stream << date.toStdString();
        return stream;
}



