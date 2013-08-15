#include "utils.h"

using namespace std;

/*
 * POW
 */
// return a^b
int pow(int a, int b) {
    int result = 1;
    while(b)
    {
        result *= a;
        b--;
    }
    return result;
}


/*
 * STR 2 QSTR
 */
QString str2qstr(string str) {
    QString inter("");
    for(unsigned int i = 0; i < str.size(); i++)
        inter += str[i];
    return inter;
}


/*
 * QSTR 2 STR
 */
string qstr2str(QString str) {
    string inter("");
    inter = str.toStdString();
    return inter;
}




