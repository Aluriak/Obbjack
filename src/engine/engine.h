#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED



/*
 * LIBRARIES
 */
// STD LIB
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
// LOCAL MODULES
#include "../utils/utils.h"
#include "../borrower/borrower.h"
#include "../object/object.h"




/*
 * DEFINES
 */




/*
 * PREDECLARATIONS
 */





/*
 * CLASS
 */
// Manage objects, borrowers, linking between both, and mail sending.
class Engine {
	public:
	// CONSTRUCTOR
		Engine();
		~Engine();
	// PUBLIC METHODS
                void addObject(std::string, std::string, std::string);
                void rmvObject(Object*);
                void addBorrower(std::string, std::string);
                void rmvBorrower(Borrower*);
                Borrower* name2borrower(std::string) const;
        // OPERATORS
                void operator=(const Engine&);
	// ACCESSORS
                std::vector<Borrower> getBorrowers(); // return copy of Bor
                std::vector<Object> getObjects(); // return copy of Objects
                unsigned int getBorrowerCount() const {return list_borrower.size(); }
                unsigned int getObjectCount() const { return list_object.size(); }
	private:
	// ATTRIBUTES
                std::list<Borrower*> list_borrower;
                std::list<Object*> list_object;
                
	// PRIVATE METHODS
};



#endif
