#ifndef READFILES_H_INCLUDED
#define READFILES_H_INCLUDED



/*
 * LIBRARIES
 */
// STD LIB
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
// LOCAL MODULES
#include "../utils/utils.h"
#include "../engine/engine.h"




/*
 * DEFINES
 */




/*
 * PREDECLARATIONS
 */





/*
 * NAMESPACE
 */
namespace readFiles {
        Engine getEngineFrom(
                std::string fileBorrowers_name,
                std::string fileObjects_name
                );
        void readBorrowers(std::string, Engine*);
        void readObjects(std::string, Engine*);
}



#endif
