#pragma once
#include <iostream>
#include <string>
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