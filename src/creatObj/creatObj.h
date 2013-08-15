#ifndef CREATOBJ_H_INCLUDED
#define CREATOBJ_H_INCLUDED


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
#include <vector>
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
class CreatObj : public QDialog {
        Q_OBJECT
        public:
                // CONSTRUCTORS
                CreatObj(Engine*, QWidget* = NULL);
                ~CreatObj();
                // METHODS
        public slots:
                void sendObjectToEngine();
        private:
        // ATTRIBUTES
                QPushButton* button_cancel;
                QPushButton* button_creat;
                QComboBox*   combo_type;
                QComboBox*   combo_borrower;
                QLineEdit*   line_name;
                // engine (simple ref)
                Engine* engine;
        // PRIVATES METHODS
};








#endif
