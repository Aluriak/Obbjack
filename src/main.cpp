#include "main.h"

using namespace std;


/*
 * MAIN
 */
int main(int argc, char *argv[]) {
        QApplication app(argc, argv);

        Obbjack Obbjack(FILE_BORROWER, FILE_OBJECT);
        Obbjack.show();

        return app.exec();
}



//int main([>int argc, char *argv[]<]) {

        
        //Engine engine = readFiles::getEngineFrom(FILE_BORROWER, FILE_OBJECT);

        //vector<Object> objects = engine.getObjects();
        //vector<Borrower> borrowers = engine.getBorrowers();


        //for(vector<Object>::iterator it = objects.begin(); it != objects.end(); it++) {
                //cout << *it << endl;
        //}
        //for(vector<Object>::iterator it = objects.begin(); it != objects.end(); it++) {
                //cout << *it << endl;
        //}
        //for(vector<Borrower>::iterator it = borrowers.begin(); it != borrowers.end(); it++) {
                //cout << it->getMail() << endl;
        //}

        //return EXIT_SUCCESS;
//}


