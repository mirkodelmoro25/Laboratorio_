/
// Created by mirko25 on 13/03/19.
//

#include "FileIni.h"
#include <fstream>
#include "string"


FileIni::FileIni(string name, int nMax) {
   fileName = name;
   nMaxComment = nMax;
   nComment = 0;
   fileS.open(name);
}

FileIni::~FileIni() {
    this->fileS.close();
}

void FileIni::setFileName(string name) {
    fileName = name;
}

string FileIni::getFileName() {
    return fileName;
}

string FileIni::getValue(string section, string parameter){
    return file[section][parameter];
}

void FileIni::setValue (string section, string parameter, int newValue){
    string rightValue = to_string(newValue);
    setValueS(section, parameter, rightValue);
}

void FileIni::setValue(string section, string parameter, bool newValue) {
    if (newValue)
        file[section][parameter]= "true";
    else file[section][parameter]= "false";
}

void FileIni::setValue(string section, string parameter, double newValue) {
    string rightValue = to_string(newValue);
    setValueS(section, parameter, rightValue);
}

void FileIni::setValueS(string section, string parameter, string newValue) {
   auto it = file[section].find(parameter);
   if (it==file[section].end())
     file[section][parameter]=newValue;
   else
     modify(section,parameter,newValue);
}

void FileIni::addSection(string newSectionName) {
    file[newSectionName];
}

void FileIni::removeSection(string section) {
    auto it = file.find(section);
    if (it == file.end())
        throw std::runtime_error( "Error, this section doesn't exist");
    else file.erase(section);
}

void FileIni::addParameter(string section, string newParameterName) {
    file[section][newParameterName] = "null";
}

void FileIni::removeParameter(string section, string parameter) {
    auto it = file[section].find(parameter);
    if (it == file[section].end())
        throw std::runtime_error(" Error, this parameter doesn't exist");
    else file[section].erase(parameter);
}


void FileIni::addComments(string section, string commentText) {
    string parameter;
    nComment += 1;
    parameter = to_string(nComment);
    file[section][parameter] = ";" + commentText;
}


void FileIni::read(string filePath) {
    ifstream f (filePath);
    string line;
    file_text.clear();
    if (f.is_open()) {
        while (getline(f, line)) {
            cout << line << "\n" << endl;
            file_text += line + "\n";
        }

        f.close();
    }
    else {
        throw std::runtime_error( "Unable to open file" );
    }
}

void FileIni::write(string filePath ){
    ofstream f (filePath);
        if (f.is_open()) {

        f << file_text << endl;
        f.close();
    }
    else {
        throw std::runtime_error( "Unable to open file" );
    }
}


int FileIni::numbersOfParameters(string section) {
    int count = 0;
    for (auto &it : file[section])
        count ++;
    return count;
}

void FileIni::end() {
    fileS.close();
}

void FileIni::checkIsOpen() {
    if (!fileS.is_open())
        throw std::runtime_error( "File doesn't exist" ) ;
}

bool FileIni::findSection(string section) {
    bool found = false;
    auto it = file.find(section);
    if (it != file.end())
        found = true;
    return found;
}

bool FileIni::findParameter(string section, string parameter) {
    bool found = false;
    auto it = file[section].find(parameter);
    if (it != file[section].end())
        found = true;
    return found;
}

void FileIni::modify(string section, string parameter, string newValue) {
    cout << "Il parametro " << parameter << " ha già un valore, se vuoi sostituire digita s" << endl;
    string subValue;
    cin >> subValue;
    if (subValue == "s")
        file[section][parameter]= newValue;
}

map<string, map<string, string>> FileIni::getFile () {
    return file;
};

int FileIni::getNComment() {
    return nMaxComment;
}
