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

        HANDLE Legion = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(Legion, 2);
        std::cout << "$LegionCode ";
        SetConsoleTextAttribute(Legion, 15);

        std::cout << std::filesystem::current_path() << std::endl;

        // Color <<<
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << ">>> ";
        SetConsoleTextAttribute(hConsole, 15);

        std::getline(std::cin, command);
        
        if (command == "exit") {

            system("exit");

        } else if (command.substr(0, 7) == "size -f") {
            std::string filename = command.substr(8);
            displayFileSize(filename);

        } else if (command.substr(0, 7) == "info -f") {
            std::string filename = command.substr(8);
            displayFileDetails(filename);

        } else if (command.substr(0, 3) == "cd ") {

            std::string directory = command.substr(3);
            directoryManager(directory);

        } else if (command == "del dir") {

            deleteDirectory();
            
        } else if (command == "cls") {

            system("cls");
            main();

        } else if (command == "help") {

            std::string Service = command;
            help(Service);

        } else if (command == ".git") {

            std::string Service = command;
            help(Service);
        } else if (command == ".source") {

            std::string Service = command;
            help(Service);
        } else if (command == ".bug") {

            std::string Service = command;
            help(Service);
        } else if (command == "version") {

            std::string Service = command;
            help(Service);
        } else if (command == "log") {

            std::string Service = command;
            help(Service);
        } else {

            std::cout << "Wrong command\n\n";

        }
    }

    return 0;

}