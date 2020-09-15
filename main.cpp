#include <iostream>
#include "FileIni.h"
#include "Print.h"

using namespace std;

int main() {

    FileIni file("FirstProgram.ini");
    cout << "File Name: "<< file.getFileName() << endl;

    Print p (&file);


    file.setValue("Sezione A", "Param. 1", true);
    file.setValue ("Sezione A", "Param. 1", 10.34) ;
    file.setValue("Sezione A", "Param. 1", 4);
    file.setValueS("Sezione A", "Param. 1", "Valore 1");
    file.setValue("Sezione A", "Param. 4", 5);


    file.addSection("Sezione D");
    file.addSection("Sezione E");
    p.printAllSections();
    file.addParameter("Sezione B", "Parametro 6");
    file.addComments("Sezione B", " commento 1");

    //p.printAllParameters("Sezione B");
    cout <<"\n" << endl;
    p.printValue("Sezione A", "Param. 4");

    int numOfParameters = file.numbersOfParameters("Sezione A");
    cout << "\nFirst Section has " << numOfParameters << " parameters \n" << endl;

    p.printAllParameters("Sezione B");
    cout <<"\nAll file: "<< endl;
    p.printAllFile();
    file.read("../FileIni.cpp");
    file.write("../prova");

    file.end();

    return 0;
}
