#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


/****************************************************
 *              LIBRARIES
 ****************************************************/
// Qt
#include <QString>
// STANDARD
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


/****************************************************
 *              DEFINES
 ****************************************************/
#define FILE_BORROWER "data/borrowers"
#define FILE_OBJECT   "data/objects"



/****************************************************
 *              PREDECLARATIONS
 ****************************************************/


/****************************************************
 *              PROTOTYPES
 ****************************************************/

int pow(int a, int b);             // return a^b
int str2int(std::string);
QString str2qstr(std::string str); 
std::string qstr2str(QString str);     
time_t const_mktime(const struct tm * const); // like mktime, but no argument modification






#endif


