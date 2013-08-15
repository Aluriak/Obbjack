#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED


/****************************************************
 *              LIBRARIES
 ****************************************************/
// STANDARD
#include <iostream>
#include <fstream>
#include <string>
// LOCAL
#include "../utils/utils.h"
#include "../borrower/borrower.h"


/****************************************************
 *              DEFINES
 ****************************************************/
#define OBJECT_DEFAULT_TYPE_1 "CD"
#define OBJECT_DEFAULT_TYPE_2 "DVD"
#define OBJECT_DEFAULT_TYPE_3 "Book"
#define OBJECT_DEFAULT_TYPE_4 "Video Game"
#define OBJECT_DEFAULT_TYPE_5 "Board Game"
#define OBJECT_DEFAULT_TYPE_6 "Mouse"


/****************************************************
 *              PREDECLARATIONS
 ****************************************************/



/****************************************************
 *              PROTOTYPES
 ****************************************************/
class Object {
        public:
                // CONSTRUCTORS
                Object(const std::string, const std::string, 
                                Borrower*);
                ~Object();
                // METHODS
                std::ostream& printIn(std::ostream&) const;
                // ACCESSORS
                std::string getName() const { return name; }
                std::string getType() const { return type; }
                Borrower* getBorrower() const { return borrower; }
                std::string getBorrowerName() const { return borrower->getName(); }
        private:
        // ATTRIBUTES
                std::string name;
                std::string type;
                Borrower* borrower;
        // PRIVATES METHODS
};




// EXTERNAL METHODS
std::ostream& operator<<(std::ostream&, const Object&);




#endif

