#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include "../include.h"
#include <windows.h>

void directoryManager(const std::string& directory) {
    std::filesystem::path path(directory);
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        std::filesystem::current_path(path);
        std::cout << "Changed directory to: " << std::filesystem::current_path() << std::endl;
    } else {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: Could not change directory" << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    }
}

