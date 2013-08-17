#include "object.h"

using namespace std;



/****************************************************
 *              CONSTRUCTORS
 ****************************************************/
Object::Object(const std::string name_, const std::string type_, const Date date_, 
                Borrower* borrower_) : 
        name(name_), type(type_), date(date_), borrower(borrower_) {
}



Object::~Object() {
}





/****************************************************
 *              PUBLIC METHODS
 ****************************************************/
ostream& Object::printIn(ostream& stream) const {
        return stream << name << " (" << type << ") by " << borrower->getName();
}


/****************************************************
 *              PRIVATE METHODS
 ****************************************************/



/****************************************************
 *              EXTERNAL METHODS
 ****************************************************/
ostream& operator<<(ostream& stream, const Object& object) {
        return object.printIn(stream);
}



