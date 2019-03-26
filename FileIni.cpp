//
// Created by mirko25 on 13/03/19.
//

#include "FileIni.h"


FileIni::FileIni(string name, int nMax) {
   fileName = name;
   nMaxComment = nMax;
   nComment = 0;
   newProject.open(name);
}

FileIni::~FileIni() {
    newProject.close();
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

string FileIni::setIntValue (string section, string parameter, int newValue){
    string rightValue = to_string(newValue);
    setStringValue(section, parameter, rightValue);
};

string FileIni::setBoolValue(string section, string parameter, bool newValue) {
    if (newValue)
        file[section][parameter]= "isTrue";
    else file[section][parameter]= "isFalse";
}

string FileIni::setFloatValue(string section, string parameter, float newValue) {
    string rightValue = to_string(newValue);
    setStringValue(section, parameter, rightValue);
}

string FileIni::setStringValue(string section, string parameter, string newValue) {
    file[section][parameter]=newValue;
}

void FileIni::addSection(string newSectionName) {
    file[newSectionName];
}

void FileIni::removeSection(string section) {
    auto it = file.find(section);
    if (it == file.end())
        std::cout<< "Error, this section doesn't exist";
    else file.erase(section);
}

void FileIni::addParameter(string section, string newParameterName) {
    file[section][newParameterName];
}

void FileIni::removeParameter(string section, string parameter) {
    auto it = file[section].find(parameter);
    if (it == file[section].end())
        std::cout<< " Error, this parameter doesn't exist";
    else file[section].erase(parameter);
}

void FileIni::printAllSections() {
    cout<<"Sections: ";
    for (auto &it:file){
        std::cout << it.first << std::endl ;
    }
}

void FileIni::printAllParameters(string section) {
    std::cout<<"Section"<< section <<": "<<std::endl;
    std::cout<< "Parameters" <<std::endl;
    for (auto& it:file[section])
        std::cout<< it.first << std::endl;
}





