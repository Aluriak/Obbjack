#ifndef OBBJACK_H_INCLUDED
#define OBBJACK_H_INCLUDED


/****************************************************
 *              LIBRARIES
 ****************************************************/
// Qt
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
// STANDARD
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// LOCAL
#include "../utils/utils.h"
#include "../readFiles/readFiles.h"
#include "../creatObj/creatObj.h"
#include "../borrower/borrower.h"
#include "../creatBor/creatBor.h"


/****************************************************
 *              DEFINES
 ****************************************************/
#define PRGM_NAME "ObbJack Alpha"
#define PRGM_WIDTH 669
#define PRGM_HEIGH 300


void TEST_engine_prod();
void TEST_engine(Engine*);

/****************************************************
 *              PREDECLARATIONS
 ****************************************************/



/****************************************************
 *              PROTOTYPES
 ****************************************************/
class Obbjack : public QWidget {
        Q_OBJECT
        public:
                // CONSTRUCTORS
                Obbjack(std::string, std::string);
                ~Obbjack();
                // PUBLIC METHODS
                void initializeObjectTable();

        public slots:
                void launchCreatObjWindow();
                void launchCreatBorWindow();
                void launchSaving();

        private:
        // ATTRIBUTES
                // Engine
                Engine engine;
                // Strings
                std::string file_borrower;
                std::string file_object;
                // Buttons
                QPushButton* button_quit;
                QPushButton* button_creatobj;
                QPushButton* button_creatbor;
                QPushButton* button_save;
                // Table
                QTableWidget* table_objects;
        // PRIVATES METHODS
                void printObjectsOnTable();
                void buttonCreatObjEnable();
};








#endif



