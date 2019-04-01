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

void FileIni::printValue(string section, string parameter){
    cout<< parameter << " = " << file[section][parameter]<<endl;
}

void FileIni::printAllFile() {
    for (auto &it : file) {
        if (it.first == "Comments")
            for (auto &it2 : file["Comments"]) {
                cout << it2.second << endl;
            }
        else {
            cout << "Section: " << it.first << endl;
            for (auto &it2 : file[it.first]) {
                int count = 0;
                bool commentFound = false;
                while (count < nMaxComment && !commentFound) {
                    if (it2.first == to_string(count)) {
                        commentFound = true;
                        cout << it2.second << endl;
                    } else count++;
                }
                if (!commentFound)
                    cout << it2.first << " = " << it2.second << endl;
            }

        }
    }
}

void FileIni::addComents(string section, string commentText, bool isInSection) {
    string parameter;
    nComment += 1;
    parameter = to_string(nComment);
    if (isInSection)
        file[section][parameter] = ";" + commentText;
    else file["Comments"][parameter] = ";" + commentText;
}

void FileIni::reset() {
    cout << "Do you want to delete everything? Yes or No" << endl;
    string answer;
    cin >> answer;
    if (answer == "Yes")
        file.clear();
    else cout << "Good choice" << endl;
}

int FileIni::numbersOfParameters(string section) {
    int count = 0;
    for (auto &it : file[section])
        count ++;
    return count;
}

void FileIni::end() {
    this->newProject.close();
}

void FileIni::checkIsOpen() {
    if (!newProject.is_open())
        cout << "File doesn't exist" << endl ;
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
    cout << "Il parametro" << parameter << "ha già un valore, se vuoi sostituire digita s" << endl;
    string subValue;
    cin >> subValue;
    if (subValue == "s")
        file[section][parameter]= newValue;
}