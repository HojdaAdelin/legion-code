#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "../include.h"

namespace fs = std::filesystem;

std::string selectedFilePath; // Store the selected file path

void SelectFile(const std::string& fileName) {
    // Get the current working directory
    fs::path currentDir = fs::current_path();

    // Search for the file in the current directory
    for (const auto& entry : fs::directory_iterator(currentDir)) {
        if (entry.path().filename() == fileName) {
            selectedFilePath = entry.path().string();
            std::cout << "File '" << fileName << "' selected." << std::endl;
            return;
        }
    }

    std::cout << "File not found in the current directory." << std::endl;
}

void TransferFile() {
    if (!selectedFilePath.empty()) {
        fs::path fileName = fs::path(selectedFilePath).filename();
        fs::path destinationPath = fs::current_path() / fileName;

        // Copy the file to the current directory
        fs::copy_file(selectedFilePath, destinationPath);

        std::cout << "File transferred to the current directory." << std::endl;
    } else {
        std::cout << "No file selected. Use 'select file' first." << std::endl;
    }
}