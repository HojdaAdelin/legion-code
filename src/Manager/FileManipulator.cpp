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
        std::cout << fileSize << " bytes\n";
        SetConsoleTextAttribute(fileColor, 15);

    } else {
        std::cerr << "File does not exist or is not a regular file." << std::endl;
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
        std::cerr << "File does not exist or is not a regular file." << std::endl;
    }
}
