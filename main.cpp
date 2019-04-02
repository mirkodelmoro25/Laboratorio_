#include <iostream>
#include "FileIni.h"

using namespace std;

int main() {

    FileIni file("FirstProgram.ini");
    cout << "File Name: "<< file.getFileName() << endl;

    file.setBoolValue("Sez. A", "Param. 1", true);
    file.setFloatValue("Sez. A", "Param. 1", 10.34);
    file.setIntValue("Sez. A", "Param. 1", 4);
    file.setStringValue("Sez. A", "Param. 1", "Val. A1");

    file.checkIsOpen();

    file.addSection("Sez. D");
    file.addParameter("Sez. B", "Param. 6");
    file.addComents("comm. 1", " comm. 2", false);

    file.printAllParameters("Sez. 2");
    file.printAllSections();

    file.printAllFile();

    int numOfParameters = file.numbersOfParameters("Sez. 1");
    cout << "First Section has " << numOfParameters << "parameters" << endl;


    file.end();

    return 0;
}