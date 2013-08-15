#ifndef CREATBOR_H_INCLUDED
#define CREATBOR_H_INCLUDED


/****************************************************
 *              LIBRARIES
 ****************************************************/
// Qt
#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
// STANDARD
#include <iostream>
#include <fstream>
#include <string>
// LOCAL
#include "../utils/utils.h"
#include "../engine/engine.h"


/****************************************************
 *              DEFINES
 ****************************************************/



/****************************************************
 *              PREDECLARATIONS
 ****************************************************/



/****************************************************
 *              PROTOTYPES
 ****************************************************/
class CreatBor : public QDialog {
        Q_OBJECT
        public:
                // CONSTRUCTORS
                CreatBor(Engine*, QWidget* = NULL);
                ~CreatBor();
                // METHODS
        public slots:
                void sendBorrowerToEngine();
        private:
        // ATTRIBUTES
                QPushButton* button_cancel;
                QPushButton* button_creat;
                QLineEdit*   line_name;
                QLineEdit*   line_mail;
                // engine (simple ref)
                Engine* engine;
        // PRIVATES METHODS
};








#endif

