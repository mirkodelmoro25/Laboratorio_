//
// Created by mirko25 on 11/09/20.
//

#include "Print.h"

void Print::printAllSections() {
    cout<<"\nSections: \n";
    for (auto &it:ini->getFile()){
        std::cout << it.first << std::endl ;
    }
}

void Print::printAllParameters(string section) {
    std::cout << "-" << section << "" << std::endl;
    std::cout << "Parameters:" << std::endl;
    map<string, map<string, string>> s = ini->getFile();
    for (auto &it:s[section])
        std::cout<< it.first << std::endl;
}

void Print::printValue(string section, string parameter){
    cout<< parameter << " = " << ini->getFile()[section][parameter]<<endl;
}

void Print::printAllFile() {
    map<string, map<string, string>> s = ini->getFile();
    for (auto &it : s) {
        if (it.first == "Comments")
            for (auto &it2 : s["Comments"]) {
                cout << it2.second << endl;
            }
        else {
            cout << "Section: " << it.first << endl;
            for (auto &it2 : s[it.first]) {
                int count = 0;
                bool commentFound = false;
                while (count < ini->getNComment() && !commentFound) {
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


