#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void addFileToCurrentDirectory(const std::string& filename) {
    fs::path currentPath = fs::current_path() / filename;

    // Check if the file has an extension
    if (currentPath.extension().empty()) {
        // Append a default extension, such as ".txt"
        currentPath += ".txt";
    }

    std::ofstream file(currentPath);
    if (file) {
        std::cout << "File '" << currentPath.filename() << "' created successfully." << std::endl;
    } else {
        std::cout << "Failed to create file '" << currentPath.filename() << "'." << std::endl;
    }
}


void deleteFileFromCurrentDirectory(const std::string& filename) {
    fs::path currentPath = fs::current_path() / filename;

    if (fs::exists(currentPath) && fs::is_regular_file(currentPath)) {
        fs::remove(currentPath);
        std::cout << "File '" << filename << "' deleted successfully." << std::endl;
    } else {
        std::cout << "Failed to delete file '" << filename << "'." << std::endl;
    }
}

void deleteCurrentDirectory() {
    fs::path currentPath = fs::current_path();
    std::error_code ec;
    fs::remove_all(currentPath, ec);

    if (!ec) {
        std::cout << "Current directory deleted successfully." << std::endl;
    } else {
        std::cout << "Failed to delete current directory." << std::endl;
    }
}

int main() {
    std::string currentDirectory = fs::current_path().string();

    std::string input;
    while (true) {
        std::cout << currentDirectory << "> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        } else if (input.substr(0, 9) == "add file") {
            std::string filename = input.substr(10);
            addFileToCurrentDirectory(filename);
        } else if (input.substr(0, 11) == "delete file") {
            std::string filename = input.substr(12);
            deleteFileFromCurrentDirectory(filename);
        } else if (input.substr(0, 6) == "del cd") {
            deleteCurrentDirectory();
            currentDirectory = fs::current_path().string();
        } else if (input.substr(0, 3) == "cd ") {
            std::string path = input.substr(3);
            if (path == "..") {
                fs::path parentPath = fs::current_path().parent_path();
                if (!parentPath.empty()) {
                    fs::current_path(parentPath);
                    currentDirectory = parentPath.string();
                }
            } else {
                fs::path newPath = fs::current_path() / path;
                if (fs::is_directory(newPath)) {
                    fs::current_path(newPath);
                    currentDirectory = newPath.string();
                } else {
                    std::cout << "Invalid directory: " << newPath.string() << std::endl;
                }
            }
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}
