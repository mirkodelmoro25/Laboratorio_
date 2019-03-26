//
// Created by mirko25 on 13/03/19.
//

#ifndef LABORATORIO_FILEINI_H
#define LABORATORIO_FILEINI_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class FileIni {
public:
    FileIni(string name, int nMax = 50);

    ~FileIni();

    void setFileName (string name);

    string getFileName();

    string getValue (string section, string parameter);

    string setIntValue (string section, string parameter, int newValue);

    string setStringValue (string section, string parameter, string newValue);

    string setBoolValue (string section, string parameter, bool newValue);

    string setFloatValue (string section, string parameter, float newValue);

    void addSection(string newSectionName);

    void removeSection (string section);

    void addParameter (string section, string newParameterName);

    void removeParameter (string section, string parameter);

    void printAllSections ();

    void printAllParameters (string section);

    void printValue (string section, string parameter);

    void printAllFile ();

    void addComents (string section, string commentText, bool isInSection);

    void reset();





private:
    string fileName;
    map<string, map<string, string>> file;
    int nComment;
    int nMaxComment;
    fstream newProject;

};


#endif //LABORATORIO_FILEINI_H
