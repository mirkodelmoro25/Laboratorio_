#include <iostream>
#include "FileIni.h"

using namespace std;

int main() {
    FileIni file("FirstProgram.ini");
    cout << "File Name: "<< file.getFileName() << endl;

    file.setBoolValue("Sezione", "Parametro", true);
    file.setFloatValue("Sezione", "Parametro", 10.34);
    file.setIntValue("Sezione", "Parametro", 4);
    file.setStringValue("Sezione", "Parametro", "Valore");

    file.checkIsOpen();



    
    
    return 0;
}