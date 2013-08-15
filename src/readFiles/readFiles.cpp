#include "readFiles.h"

using namespace std;

namespace readFiles {

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
                engine->addObject(value[0], value[1]/*, value[2]*/, value[3]);
                for(unsigned int i = 0; i < 4; i++)
                        value[i] = "";
        }
// ENDING
        }
        f.close();
}



// NAMESPACE END
}



