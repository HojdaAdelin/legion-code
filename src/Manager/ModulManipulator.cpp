#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include "../include.h"
#include <windows.h>

void deleteDirectory() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::error_code ec;
    std::filesystem::remove_all(currentPath, ec);

    if (ec) {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: Failed to delete directory: " << ec.message() << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    } else {
        std::cout << "Directory deleted!";
    }
}

void viewDirectoryContents() {
    std::filesystem::path currentPath = std::filesystem::current_path();

    for (const auto& entry : std::filesystem::directory_iterator(currentPath)) {
        if (entry.is_regular_file()) {

            HANDLE fileColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(fileColor, 2);
            std::cout << "File: ";
            SetConsoleTextAttribute(fileColor, 15);

            std::cout << entry.path().filename();
            std::filesystem::path filePath(entry.path().filename());
            std::uintmax_t fileSize = std::filesystem::file_size(filePath);
            std::cout << " with ";
            SetConsoleTextAttribute(fileColor, 2);
            std::cout << fileSize;
            SetConsoleTextAttribute(fileColor, 15);
            std::cout << " bytes." << std::endl;

        } else if (entry.is_directory()) {

            int fileCount = 0;
            for (const auto& entry : std::filesystem::directory_iterator(entry.path().filename())) {
                if (entry.is_regular_file()) {
                    fileCount++;
                }
            }

            HANDLE fileColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(fileColor, 14);
            std::cout << "Folder: ";
            SetConsoleTextAttribute(fileColor, 15);

            std::cout << entry.path().filename();
            std::cout << " with ";
            SetConsoleTextAttribute(fileColor, 14);
            std::cout << fileCount;
            SetConsoleTextAttribute(fileColor, 15);
            std::cout << " files." << std::endl;
        }
    }
}