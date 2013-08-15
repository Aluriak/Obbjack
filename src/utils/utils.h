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
QString str2qstr(std::string str); 
std::string qstr2str(QString str);     






#endif


