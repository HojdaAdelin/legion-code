#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>
#include <fstream>
#include "../include.h"

void displayFileSize(const std::string& filename) {
    std::filesystem::path filePath(filename);
    
    if (std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath)) {
        std::uintmax_t fileSize = std::filesystem::file_size(filePath);
        std::cout << "File size of " << filename << ": ";

        HANDLE fileColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(fileColor, legionEnv());
        std::cout << fileSize << " bytes\n";
        SetConsoleTextAttribute(fileColor, 15);

    } else {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: File does not exist or is not a regular file." << std::endl;
        SetConsoleTextAttribute(errorWin, 15);

    }
}

void displayFileDetails(const std::string& filename) {
    std::filesystem::path filePath(filename);
    
    if (std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath)) {
        std::cout << "File details for: " << filename << std::endl;
        std::cout << "File size: " << std::filesystem::file_size(filePath) << " bytes" << std::endl;

        std::filesystem::file_time_type lastModified = std::filesystem::last_write_time(filePath);
        std::time_t lastModifiedTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now() + (lastModified - std::filesystem::file_time_type::clock::now()));
        std::cout << "Last modified: " << std::ctime(&lastModifiedTime);

        std::filesystem::perms permissions = std::filesystem::status(filePath).permissions();
        std::cout << "Permissions: "
            << ((permissions & std::filesystem::perms::owner_read) != std::filesystem::perms::none ? "r" : "-")
            << ((permissions & std::filesystem::perms::owner_write) != std::filesystem::perms::none ? "w" : "-")
            << ((permissions & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ? "x" : "-")
            << ((permissions & std::filesystem::perms::group_read) != std::filesystem::perms::none ? "r" : "-")
            << ((permissions & std::filesystem::perms::group_write) != std::filesystem::perms::none ? "w" : "-")
            << ((permissions & std::filesystem::perms::group_exec) != std::filesystem::perms::none ? "x" : "-")
            << ((permissions & std::filesystem::perms::others_read) != std::filesystem::perms::none ? "r" : "-")
            << ((permissions & std::filesystem::perms::others_write) != std::filesystem::perms::none ? "w" : "-")
            << ((permissions & std::filesystem::perms::others_exec) != std::filesystem::perms::none ? "x" : "-")
            << std::endl;

    } else {

        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: File does not exist or is not a regular file." << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    }
}


void deleteFile(const std::string& filename) {
    std::filesystem::path filePath(filename);
    
    if (std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath)) {
        std::filesystem::remove(filePath);
        std::cout << "File '" << filename << "' deleted";

        HANDLE winColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(winColor, legionEnv());
        std::cout << " successfully." << std::endl;
        SetConsoleTextAttribute(winColor, 15);

    } else {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: File does not exist or is not a regular file." << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    }
}

void renameFile(const std::string& filename, const std::string& newname) {
    std::filesystem::path filePath(filename);
    std::filesystem::path newFilePath(newname);
    
    if (std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath)) {
        std::filesystem::rename(filePath, newFilePath);
        std::cout << "File '" << filename << "' renamed to '" << newname;

        HANDLE winColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(winColor, legionEnv());
        std::cout << " successfully." << std::endl;
        SetConsoleTextAttribute(winColor, 15);

    } else {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: File does not exist or is not a regular file." << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    }
}

void compressFile(const std::string& file) {
    std::string command = "powershell Compress-Archive -Path " + file + " -DestinationPath compressed.zip";
    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "File compressed";
        HANDLE winColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(winColor, legionEnv());
        std::cout << " successfully." << std::endl;
        SetConsoleTextAttribute(winColor, 15);
    } else {
        HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorWin, 12);
        std::cerr << "Error: Failed to compress file." << std::endl;
        SetConsoleTextAttribute(errorWin, 15);
    }
}

void viewFileContent(const std::string& fileName) {

    HANDLE fileColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(fileColor, legionEnv());
    std::cout << fileName;
    SetConsoleTextAttribute(fileColor, 15);
    std::cout << " content:\n\n";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        HANDLE errorColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(errorColor, 12);
        std::cout << "Failed to open file: " << fileName << std::endl;
        SetConsoleTextAttribute(errorColor, 15);
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        highlightKeywords(line);
        std::cout <<  std::endl;
    }

    file.close();
}
