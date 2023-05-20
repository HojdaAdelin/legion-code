#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include "../include.h"


void deleteDirectory() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::error_code ec;
    std::filesystem::remove_all(currentPath, ec);

    if (ec) {
        std::cerr << "Failed to delete directory: " << ec.message() << std::endl;
    } else {
        std::cout << "Directory deleted!\n\n";
    }
}