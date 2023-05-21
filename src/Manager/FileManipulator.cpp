#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>

void displayFileSize(const std::string& filename) {
    std::filesystem::path filePath(filename);
    
    if (std::filesystem::exists(filePath) && std::filesystem::is_regular_file(filePath)) {
        std::uintmax_t fileSize = std::filesystem::file_size(filePath);
        std::cout << "File size of " << filename << ": ";

        HANDLE fileColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(fileColor, 2);
        std::cout << fileSize << " bytes\n\n";
        SetConsoleTextAttribute(fileColor, 15);
        
    } else {
        std::cerr << "File does not exist or is not a regular file." << std::endl;
    }
}