#include "creatObj.h"

using namespace std;


/****************************************************
 *              CONSTRUCTORS
 ****************************************************/
CreatObj::CreatObj(Engine* engine_, QWidget* parent) : 
                        QDialog(parent), engine(engine_) {
        // WINDOW TITLE
        setWindowTitle("Creat an Object"); 

        // COMBO BOXS
                combo_type = new QComboBox(this);
                        combo_type->addItem(str2qstr(OBJECT_DEFAULT_TYPE_1));
                        combo_type->addItem(str2qstr(OBJECT_DEFAULT_TYPE_2));
                        combo_type->addItem(str2qstr(OBJECT_DEFAULT_TYPE_3));
                        combo_type->addItem(str2qstr(OBJECT_DEFAULT_TYPE_4));
                        combo_type->addItem(str2qstr(OBJECT_DEFAULT_TYPE_5));
                        //TODO: item can be added
                combo_borrower = new QComboBox(this);
                        vector<Borrower> borrowers = engine->getBorrowers();
                        for(unsigned int i = 0, count = borrowers.size();
                                        i < count; i++) 
                                combo_borrower->addItem(str2qstr(
                                        borrowers[i].getName()));
        // PUSH BUTTONS
                button_cancel = new QPushButton("Cancel", this);
                        QObject::connect(button_cancel, SIGNAL(clicked(bool)), 
                                        this, SLOT(accept()));
                button_creat = new QPushButton("Creat", this);
                        QObject::connect(button_creat, SIGNAL(clicked(bool)), 
                                        this, SLOT(sendObjectToEngine()));
        // LINE EDIT
                line_name = new QLineEdit("Name, description");

        // LAYOUTS
                // Values layout
                QVBoxLayout* layout_values = new QVBoxLayout;
                        layout_values->addWidget(line_name);
                        layout_values->addWidget(combo_type);
                        layout_values->addWidget(combo_borrower);
                QHBoxLayout* layout_button = new QHBoxLayout;
                        layout_button->addWidget(button_creat);
                        layout_button->addWidget(button_cancel);
                // Button layout
                // Main layout
                QGroupBox* group_values = new QGroupBox(this);
                        group_values->setLayout(layout_values);
                QGroupBox* group_button = new QGroupBox(this);
                        group_button->setLayout(layout_button);  
                QVBoxLayout* layout_main = new QVBoxLayout;
                        layout_main->addWidget(group_values);
                        layout_main->addWidget(group_button);
                this->setLayout(layout_main);
}



CreatObj::~CreatObj() {
}





/****************************************************
 *              PUBLIC METHODS
 ****************************************************/




/****************************************************
 *              PUBLIC SLOTS
 ****************************************************/
void CreatObj::sendObjectToEngine() {
        engine->addObject(
                                line_name->text().toStdString(), 
                                combo_type->currentText().toStdString(),
                                combo_borrower->currentText().toStdString()
                                );
        this->accept();
}




/****************************************************
 *              PRIVATE METHODS
 ****************************************************/





