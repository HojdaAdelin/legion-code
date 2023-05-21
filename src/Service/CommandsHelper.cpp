#include <iostream>
#include "../include.h"


void help(std::string ServiceString) {

    if (ServiceString == "help") {
        commandHelp();
    } else if (ServiceString == "version") {
        std::cout << "\nVersion: 1.0 BETA\n\n";
    } else if (ServiceString == "log") {
        std::cout << "\n-Main deployment\n\n";
    } else if (ServiceString == ".git" || ".bug" || ".source") {
        WebOpener(ServiceString);
    } 

}

void commandHelp() {

    std::cout << "\n";
    std::cout << "help              Display commands\n";
    std::cout << ".git              Open github\n";
    std::cout << ".source           Open LegionCode source\n";
    std::cout << ".bug              Open bugs website\n";
    std::cout << "cd                Directory change\n";
    std::cout << "cls               Clear terminal\n";
    std::cout << "version           Display current version\n";
    std::cout << "log               Change log\n";
    std::cout << "del dir           Delete current directory\n";
    std::cout << "size -f 'file'    Display file size from a directory\n";
    std::cout << "info -f 'file'    Didplay file details from a directory\n";
    std::cout << "\n";
    
}