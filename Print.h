//
// Created by mirko25 on 11/09/20.
//

#ifndef LABORATORIO__PRINT_H
#define LABORATORIO__PRINT_H


#include "FileIni.h"

class Print {
public:
    explicit Print(FileIni* f) {
        ini = f;
    }

    void printAllSections();

    void printAllParameters(string section);

    void printValue(string section, string parameter);

    void printAllFile ();



private: FileIni* ini;
};


#endif //LABORATORIO__PRINT_H
