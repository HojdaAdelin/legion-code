#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include "include.h"
#include <handleapi.h>
#include <windows.h>

int main() {

    std::string command;
    while (true) {
        std::cout << std::filesystem::current_path() << std::endl;

        // Color <<<
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << ">>> ";
        SetConsoleTextAttribute(hConsole, 15);
        
        std::getline(std::cin, command);
        
        if (command == "exit") {

            system("exit");

        } else if (command.substr(0, 3) == "cd ") {

            std::string directory = command.substr(3);
            directoryManager(directory);

        } else if (command == "help" || ".git" || ".source" || ".bug") {

            std::string Service = command;
            help(Service);

        } else {

            std::cout << "Wrong command" << std::endl;

        }
    }

    return 0;

}