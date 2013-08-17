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




