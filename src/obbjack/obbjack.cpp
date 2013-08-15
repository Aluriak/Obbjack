#include "main.h"

using namespace std;



/****************************************************
 *              CONSTRUCTORS
 ****************************************************/
Obbjack::Obbjack(std::string file_borrower_, std::string file_object_) : 
                file_borrower(file_borrower_), file_object(file_object_) {
        // ENGINE
                engine = readFiles::getEngineFrom(file_borrower, file_object);
        // WINDOW
                setWindowTitle(PRGM_NAME);
                setGeometry(0,0,PRGM_WIDTH,PRGM_HEIGH);
        // WIDGETS
                // QPushButton
                button_quit = new QPushButton("Quit", this);
                button_creatbor = new QPushButton("Creat Borrower", this);
                button_creatobj = new QPushButton("Creat Object", this);
                button_save = new QPushButton("Save table", this);
                // QTableWidget
                table_objects = new QTableWidget(this);
                initializeObjectTable();
        // LAYOUTS
                // Group button
                QHBoxLayout* layout_button = new QHBoxLayout;
                        layout_button->addWidget(button_quit);
                        layout_button->addWidget(button_creatbor);
                        layout_button->addWidget(button_creatobj);
                        layout_button->addWidget(button_save);
                QGroupBox* group_button = new QGroupBox(this);
                        group_button->setLayout(layout_button);
                // Group Table
                QHBoxLayout* layout_table = new QHBoxLayout;
                        layout_table->addWidget(table_objects);
                QGroupBox* group_table = new QGroupBox(this);
                        group_table->setLayout(layout_table);
                // Main layout
                QVBoxLayout *layout_main = new QVBoxLayout(this);
                layout_main->addWidget(group_table);
                layout_main->addWidget(group_button);


        // CONNECTS
                QObject::connect(button_quit, SIGNAL(clicked(bool)),
                                qApp, SLOT(quit()));
                QObject::connect(button_creatbor, SIGNAL(clicked(bool)),
                                this, SLOT(launchCreatBorWindow()));
                QObject::connect(button_creatobj, SIGNAL(clicked(bool)),
                                this, SLOT(launchCreatObjWindow()));
                //QObject::connect(button_save, SIGNAL(clicked(bool)),
                                //this, SLOT(launchSaving()));

}




Obbjack::~Obbjack() {
}





/****************************************************
 *              PUBLIC METHODS
 ****************************************************/
/*
 * INITIALIZE OBJECT TABLE
 */
void Obbjack::initializeObjectTable() {
        // TABLE
                table_objects->setRowCount(1);
                table_objects->setColumnCount(3);
                        table_objects->setColumnWidth(0,200);
                        table_objects->setColumnWidth(1,200);
                        table_objects->setColumnWidth(2,200);
        // QBRUSH
                QBrush title_background(QColor(150,100,0));
        // ITEMS
        QTableWidgetItem* item_name = new QTableWidgetItem("Object name");
                item_name->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                item_name->setBackground(title_background);
        QTableWidgetItem* item_type = new QTableWidgetItem("Type");
                item_type->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);
                item_type->setBackground(title_background);
        QTableWidgetItem* item_borrower = new QTableWidgetItem("Borrower");
                item_borrower->setTextAlignment(
                                Qt::AlignCenter | Qt::AlignVCenter);
                item_borrower->setBackground(title_background);
        // ASSIGNMENT
                table_objects->setItem(0,0, item_name);
                table_objects->setItem(0,1, item_type);
                table_objects->setItem(0,2, item_borrower);
        // OBJECTS
                printObjectsOnTable();
        // BUTTONS
                buttonCreatObjEnable();
}






/****************************************************
 *              PUBLIC SLOTS
 ****************************************************/
/*
 * LAUNCH CREAT OBJ WINDOW
 */
void Obbjack::launchCreatObjWindow() {
        CreatObj* w2 = new CreatObj(&engine, this);
        w2->exec(); // show & wait for w2 ending
        initializeObjectTable();
}


/*
 * LAUNCH CREAT BOR WINDOW
 */
void Obbjack::launchCreatBorWindow() {
        CreatBor* w2 = new CreatBor(&engine, this);
        w2->exec(); // show & wait for w2 ending
        buttonCreatObjEnable();
}



/*
 * LAUNCH SAVING
 */
// Save current Engine to files
void Obbjack::launchSaving() {
}




/****************************************************
 *              PRIVATE METHODS
 ****************************************************/
/*
 * BUTTON CREAT OBJECTS ENABLE
 */
void Obbjack::buttonCreatObjEnable() {
        if(engine.getBorrowerCount() != 0) 
                //button_creatobj->setCheckable(true);
                button_creatobj->setEnabled(true);
        else
                //button_creatobj->setCheckable(false);
                button_creatobj->setEnabled(false);
}




/*
 * PRINT OBJECTS ON TABLE
 */
void Obbjack::printObjectsOnTable() {
        vector<Object> objects = engine.getObjects();
        for(unsigned int i = 0, count = objects.size();
                        i < count; i++) {
                // CREAT TABLE ITEMS
                QTableWidgetItem* item_name 
                        = new QTableWidgetItem(
                                                objects[i].getName().
                                                c_str());
                        item_name->setTextAlignment(
                                        Qt::AlignLeft|Qt::AlignVCenter);
                QTableWidgetItem* item_type = new QTableWidgetItem(
                                objects[i].getType().c_str());
                        item_type->setTextAlignment(
                                        Qt::AlignCenter | Qt::AlignVCenter);
                QTableWidgetItem* item_borrower 
                        = new QTableWidgetItem(
                                                objects[i].getBorrowerName().
                                                c_str());
                        item_borrower->setTextAlignment(
                                        Qt::AlignCenter | Qt::AlignVCenter);
                // ASSIGNMENT
                        table_objects->setRowCount(table_objects->rowCount()+1);
                        table_objects->setItem(i+1,0, item_name);
                        table_objects->setItem(i+1,1, item_type);
                        table_objects->setItem(i+1,2, item_borrower);
        }
}






void TEST_engine(Engine* engine) {
        cerr << "OBJECTS" << endl;
        vector<Object> vec = engine->getObjects();
        for(unsigned int i = 0, count = vec.size(); i < count; i++)
                cerr << "\t" << vec[i].getName() << " (" << vec[i].getType() 
                        << ") by " << vec[i].getBorrowerName() << endl;

        cerr << "BORROWERS" << endl;
        vector<Borrower> bec = engine->getBorrowers();
        for(unsigned int i = 0, count = bec.size(); i < count; i++)
                cerr << "\t" << bec[i].getName() << " (" << bec[i].getMail() << ")" << endl;

        cerr << "END" << endl;
}


void TEST_engine_prod() {
        Engine engine = readFiles::getEngineFrom(FILE_BORROWER, FILE_OBJECT);
        TEST_engine(&engine);
        TEST_engine(&engine);
}



