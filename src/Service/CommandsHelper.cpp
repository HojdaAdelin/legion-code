#include <iostream>
#include "../include.h"


void help(std::string ServiceString) {

    if (ServiceString == "help") {
        commandHelp();
    } else if (ServiceString == "version") {
        std::cout << "\nVersion: 1.0.5\n";
    } else if (ServiceString == "log") {
        std::cout << "\n-Downloaded apps\n-VS Code command\n-Open app\n";
    } else if (ServiceString == ".git" || ".bug" || ".source") {
        WebOpener(ServiceString);
    } 

}

void commandHelp() {

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
    std::cout << "info -f 'file'    Display file details from a directory\n";
    std::cout << "del -f 'file'     Delete file from a directory\n";
    std::cout << "-r 'file_name' 'new_name'         Rename file from the directory\n";
    std::cout << "dir view          View directory content\n";
    std::cout << "dir -z            Go to previous directory\n";
    std::cout << "dir -x            Go to last directory\n";
    std::cout << "rand 'min' 'max'  Random number between min and max numbers we enter\n";
    std::cout << "compres 'file'    Create a .zip arhive with the file\n";
    std::cout << "code .            Open VS Code on current directory\n";
    std::cout << "apps view         Display all apps that are installed on user PC\n";
    std::cout << "open 'app name'   Open a specific app\n";
    std::cout << "close 'app name'  Close a specific app\n";


    
}