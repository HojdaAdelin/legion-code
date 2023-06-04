#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <windows.h>
#include "../include.h"

void displayArchiveContent(const std::string& archivePath) {
    std::string command = "unzip -l \"" + archivePath + "\"";
    std::cout << "Archive Contents:\n";

    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Error executing command: " << command << std::endl;
        return;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line(buffer);
        std::istringstream iss(line);

        std::string entryType;
        std::string entryPath;
        if (iss >> entryType >> entryPath) {
            if (entryType == "file:") {
                HANDLE colorCode = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(colorCode, 2);
                std::cout << "File: ";
                SetConsoleTextAttribute(colorCode, 15);
                std::cout << entryPath << std::endl;
                
            } else if (entryType == "folder:") {
                HANDLE colorCode = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(colorCode, 2);
                std::cout << "Folder: ";
                SetConsoleTextAttribute(colorCode, 15);
                std::cout << entryPath << std::endl;
            }
        }
    }

    pclose(pipe);
}

