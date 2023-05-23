#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include "../include.h"
#include <windows.h>
#include <stack>

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

void goToPreviousDirectory() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::filesystem::path parentPath = currentPath.parent_path();

    if (std::filesystem::exists(parentPath) && std::filesystem::is_directory(parentPath)) {
        std::filesystem::current_path(parentPath);
        HANDLE prevDir = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(prevDir, 2);
        std::cout << "New directory(previous): ";
        SetConsoleTextAttribute(prevDir, 15);
        std::cout << parentPath << std::endl;
    } else {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: Cannot move to previous directory." << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    }
}

void goToLastDirectory(std::stack<std::filesystem::path> lastDirStack) {
    if (!lastDirStack.empty()) {
        std::filesystem::path lastDirectory = lastDirStack.top();
        std::filesystem::current_path(lastDirectory);
        lastDirStack.pop();
        HANDLE newDir = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(newDir, 2);
        std::cout << "New directory(last): ";
        SetConsoleTextAttribute(newDir, 15);
        std::cout << lastDirectory << std::endl;
    } else {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: No previous directory found." << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    }
}