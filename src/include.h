#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <stack>

// Main header file for Legion Code


void commandHelp();
void WebOpener(std::string Atribute);
void directoryManager(const std::string& directory);
void deleteDirectory();
void help(std::string ServiceString);
void displayFileSize(const std::string& filename);
void displayFileDetails(const std::string& filename);
void deleteFile(const std::string& filename);
void renameFile(const std::string& filename, const std::string& newname);
void viewDirectoryContents();
void goToPreviousDirectory();
void goToLastDirectory(std::stack<std::filesystem::path> lastDirStack);
void generatorNumber(int min, int max);
void compressFile(const std::string& file);
void viewInstalledApps();
void startApps(std::string name);
void closeApps(std::string closeName);
void viewFileContent(const std::string& fileName);
void highlightKeywords(const std::string& line);
void stackLink(std::string stack);
void openStackedLink();
void viewStackedLink();