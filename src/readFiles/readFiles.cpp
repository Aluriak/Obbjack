#include "readFiles.h"

using namespace std;

namespace readFiles {

/****************************************************
 *              GET ENGINE
 ****************************************************/
/*
 * GET ENGINE FROM files
 */
// return Engine with values read in borrowers and objects files
Engine getEngineFrom(string fileBorrowers_name, string fileObjects_name) {
        Engine engine;
        readBorrowers(fileBorrowers_name, &engine);
        readObjects(fileObjects_name, &engine);
        return engine;
}



/*
 * READ BORROWERS
 */
// built vector of borrowers detected in borrower file
void readBorrowers(string fileBorrowers_name, Engine* engine) {
// INITIALIZATION
        string line, name, mail;
        bool name_done = false;
        ifstream f(fileBorrowers_name.c_str());
        if(f) {
// TREATMENT
        while(getline(f, line)) {
                for(unsigned int i = 0, count = line.size(); i < count; i++) {
                        if(line[i] == ':')
                                name_done = true;
                        else if(name_done)
                                mail += line[i];
                        else
                                name += line[i];
                }
                name_done = false;
                engine->addBorrower(name, mail);
                name = "";
                mail = "";
        }
// ENDING
        }
        f.close();
}



/*
 * READ OBJECTS
 */
// built vector of objects detected in object file
void readObjects(string fileObjects_name, Engine* engine) {
// INITIALIZATION
        string line, value[4];
        unsigned int k = 0;
        ifstream f(fileObjects_name.c_str());
        if(f) {
// TREATMENT
        while(getline(f, line)) {
                for(unsigned int i = 0, count = line.size(); i < count; i++) {
                        if(line[i] == ':') 
                                k++;
                        else
                                value[k] += line[i];
                }
                k = 0;
                engine->addObject(value[0], value[1], value[2], value[3]);
                for(unsigned int i = 0; i < 4; i++)
                        value[i] = "";
        }
// ENDING
        }
        f.close();
}








/****************************************************
 *              SET ENGINE
 ****************************************************/
/*
 * SET ENGINE TO files
 */
// write engine in files with given name
void setEngineTo(Engine* engine, string fileBorrowers_name, string fileObjects_name) {
        writeBorrowers(fileBorrowers_name, engine);
        writeObjects(fileObjects_name, engine);
}



/*
 * WRITE BORROWERS
 */
// Write list of borrower in borrower file
void writeBorrowers(string fileBorrowers_name, Engine* engine) {
// INITIALIZATION
        vector<Borrower> bor = engine->getBorrowers();
        ofstream f(fileBorrowers_name.c_str());
        if(f) {
// TREATMENT
        for(unsigned int i = 0, count = bor.size(); i < count; i++) {
                f << bor[i].getName() 
                        << ":" << bor[i].getMail()
                        << endl;
        }
// ENDING
        }
        f.close();
}


/*
 * WRITE OBJECTS
 */
// Write list of object in object file
void writeObjects(string fileObjects_name, Engine* engine) {
// INITIALIZATION
        vector<Object> obj = engine->getObjects();
        ofstream f(fileObjects_name.c_str());
        if(f) {
// TREATMENT
        for(unsigned int i = 0, count = obj.size(); i < count; i++) {
                f << obj[i].getName() 
                        << ":" << obj[i].getType()
                        << ":" << obj[i].getDate().toStdString()
                        << ":" << obj[i].getBorrowerName()
                        << endl;
        }
// ENDING
        }
        f.close();
}





// NAMESPACE END
}



