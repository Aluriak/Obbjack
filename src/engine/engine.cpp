#include "engine.h"

using namespace std;


/***************************************************
 * CONSTRUCTOR
 ***************************************************/
Engine::Engine() {
}




Engine::~Engine() {
        for(list<Object*>::iterator it = list_object.begin();
                        it != list_object.end(); it++) 
                delete *it;
        for(list<Borrower*>::iterator it = list_borrower.begin();
                        it != list_borrower.end(); it++) 
                delete *it;
}


/***************************************************
* PUBLIC METHODS
***************************************************/
/*
* ADD OBJECT
*/
// Add object only if the given name correspond to an existing borrower
void Engine::addObject(std::string name, std::string type, std::string borrower){
        Borrower* p_borrower = name2borrower(borrower);
        if(p_borrower != NULL) {
                list_object.push_back(new Object(name, type, p_borrower));
        }
}


/*
* REMOVE OBJECT
*/
void Engine::rmvObject(Object* object) {
        list_object.remove(object);
        delete object;
}


/*
* ADD BORROWER
*/
void Engine::addBorrower(string name, string mail) {
        list_borrower.push_back(new Borrower(name, mail));
}


/*
* REMOVE BORROWER
*/
void Engine::rmvBorrower(Borrower* bor) {
        list_borrower.remove(bor);
        delete bor;
}



/*
 * NAME TO BORROWER
 */
Borrower* Engine::name2borrower(std::string name) const {
        Borrower* target = NULL;
        for(list<Borrower*>::const_iterator it = list_borrower.begin();
                                target == NULL && it != list_borrower.end(); it++) {
                if((*it)->getName() == name)
                        target = *it;
        }
        return target;
}





/***************************************************
* OPERATORS
***************************************************/
/*
 * OPERATOR =
 */
// When engine is free, borrowers and objects too.
// The affectation method read and recreat theses.
void Engine::operator=(const Engine& eng) {
// BORROWERS
        for(list<Borrower*>::const_iterator it = eng.list_borrower.begin(); 
                        it != eng.list_borrower.end(); it++) {
                addBorrower((*it)->getName(), (*it)->getMail());
        }
// OBJECTS
        for(list<Object*>::const_iterator it = eng.list_object.begin(); 
                        it != eng.list_object.end(); it++) {
                addObject((*it)->getName(), (*it)->getType(), (*it)->getBorrowerName());
        }
}





/***************************************************
* ACCESSORS
***************************************************/
/*
* GET BORROWERS
*/
// return copy of Bor
vector<Borrower> Engine::getBorrowers() {
        vector<Borrower> bor(0);
        for(list<Borrower*>::iterator it = list_borrower.begin();
                                it != list_borrower.end(); it++) {
                        bor.push_back(Borrower((*it)->getName(), 
                                                (*it)->getMail()));
                }
        return bor;
}




/*
* GET OBJECTS
*/
// return copy of Object
vector<Object> Engine::getObjects() {
        vector<Object> obj;
        for(list<Object*>::iterator it = list_object.begin();
                                it != list_object.end(); it++) {
                        obj.push_back(**it);
        }
        return obj;
}



/***************************************************
 * PRIVATE METHODS
 ***************************************************/



