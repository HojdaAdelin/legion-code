#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include "include.h"

int main() {

    std::string command;
    while (true) {
        std::cout << std::filesystem::current_path() << std::endl;
        std::cout << ">>> ";
        std::getline(std::cin, command);
        
        if (command == "exit") {

            system("exit");

        } else if (command.substr(0, 3) == "cd ") {

            std::string directory = command.substr(3);
            directoryManager(directory);

        } else {

            std::cout << "Wrong command" << std::endl;

        }
    }

    return 0;

}