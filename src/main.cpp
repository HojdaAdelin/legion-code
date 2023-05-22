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
            std::cout << "\n";
            std::string filename = command.substr(8);
            displayFileSize(filename);
            std::cout << "\n";

        } else if (command.substr(0, 7) == "info -f") {
            std::cout << "\n";
            std::string filename = command.substr(8);
            displayFileDetails(filename);
            std::cout << "\n";

        } else if (command.substr(0, 6) == "del -f") {
            std::cout << "\n";
            std::string filename = command.substr(7);
            deleteFile(filename);
            std::cout << "\n";
            
        } else if (command.substr(0, 3) == "cd ") {
            std::cout << "\n";
            std::string directory = command.substr(3);
            directoryManager(directory);
            std::cout << "\n";

        } else if (command == "del dir") {
            std::cout << "\n";
            deleteDirectory();
            std::cout << "\n";
            
        } else if (command == "cls") {

            system("cls");
            main();

        } else if (command == "help") {
            std::cout << "\n";
            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == ".git") {
            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == ".source") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == ".bug") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == "version") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == "dir view") {
            std::cout << "\n";
            viewDirectoryContents();
            std::cout << "\n";

        } else if (command == "log") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command.substr(0, 2) == "-r") {
            std::cout << "\n";
            size_t firstSpacePos = command.find(' ');
            if (firstSpacePos != std::string::npos) {
                size_t secondSpacePos = command.find(' ', firstSpacePos + 1);
                if (secondSpacePos != std::string::npos) {
                    std::string filename = command.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
                    std::string newname = command.substr(secondSpacePos + 1);
                    renameFile(filename, newname);
                } else {
                    std::cout << "Invalid command" << std::endl;
                }
            } else {
                std::cout << "Invalid command" << std::endl;
            }
            std::cout << "\n";
        } else {

            std::cout << "\nWrong command\n\n";

        }
    }

    return 0;

}