#ifndef BORROWER_H_INCLUDED
#define BORROWER_H_INCLUDED


/****************************************************
 *              LIBRARIES
 ****************************************************/
// STANDARD
#include <iostream>
#include <fstream>
#include <string>
// LOCAL
#include "../utils/utils.h"


/****************************************************
 *              DEFINES
 ****************************************************/



/****************************************************
 *              PREDECLARATIONS
 ****************************************************/



/****************************************************
 *              PROTOTYPES
 ****************************************************/
class Borrower {
        public:
                // CONSTRUCTORS
                Borrower(std::string = "", std::string = "");
                ~Borrower();
                // METHODS
                        std::string getName() const { return name; }
                        std::string getMail() const { return mail; }
        private:
        // ATTRIBUTES
                std::string name;
                std::string mail;
        // PRIVATES METHODS
};








#endif
