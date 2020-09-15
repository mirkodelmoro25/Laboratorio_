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

    void setValue (string section, string parameter, int newValue);

    void setValueS (string section, string parameter, string newValue);

    void setValue (string section, string parameter, bool newValue);

    void setValue (string section, string parameter, double newValue);

    void addSection(string newSectionName);

    void removeSection (string section);

    void addParameter (string section, string newParameterName);

    void removeParameter (string section, string parameter);

    void addComments (string section, string commentText);

    void read(string filePath);

    void write(string filePath);

    int numbersOfParameters(string section);

    void end();

    void checkIsOpen() ;

    bool findSection(string section);

    bool findParameter(string section, string parameter);

    void modify(string section, string parameter, string newValue);

    map<string, map<string, string>> getFile ();

    int getNComment();






private:
    string fileName;
    map<string, map<string, string>> file;
    int nComment;
    int nMaxComment;
    fstream fileS;
    string file_text;


};


#endif //LABORATORIO_FILEINI_H

