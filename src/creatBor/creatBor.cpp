#include "creatBor.h"

using namespace std;


/****************************************************
 *              CONSTRUCTORS
 ****************************************************/
CreatBor::CreatBor(Engine* engine_, QWidget* parent) : 
                        QDialog(parent), engine(engine_) {
        // WINDOW TITLE
        setWindowTitle("Creat an Borrower"); 

        // PUSH BUTTONS
                button_cancel = new QPushButton("Cancel", this);
                        QObject::connect(button_cancel, SIGNAL(clicked(bool)), 
                                        this, SLOT(accept()));
                button_creat = new QPushButton("Creat", this);
                        QObject::connect(button_creat, SIGNAL(clicked(bool)), 
                                        this, SLOT(sendBorrowerToEngine()));
        // LINE EDIT
                line_name = new QLineEdit("Name, description");
                line_mail = new QLineEdit("Mail");

        // LAYOUTS
                // Values layout
                QVBoxLayout* layout_values = new QVBoxLayout;
                        layout_values->addWidget(line_name);
                        layout_values->addWidget(line_mail);
                        layout_values->addWidget(button_creat);
                        layout_values->addWidget(button_cancel);
                // Main layout
                QGroupBox* group_values = new QGroupBox(this);
                        group_values->setLayout(layout_values);
                QVBoxLayout* layout_main = new QVBoxLayout;
                        layout_main->addWidget(group_values);
                this->setLayout(layout_main);
}



CreatBor::~CreatBor() {
}





/****************************************************
 *              PUBLIC METHODS
 ****************************************************/




/****************************************************
 *              PUBLIC SLOTS
 ****************************************************/
void CreatBor::sendBorrowerToEngine() {
        engine->addBorrower(line_name->text().toStdString(), 
                        line_mail->text().toStdString());
        this->accept();
}




/****************************************************
 *              PRIVATE METHODS
 ****************************************************/






