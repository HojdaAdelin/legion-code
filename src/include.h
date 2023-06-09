#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <stack>
#include <fstream>

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
void userOpenLink(std::string inputLink);
void userLinkDelete();
void TempExecutable();
void displayArchiveContent(const std::string& archivePath);
void GitCloneAdding();
void GitCloneMerge(std::string text);
void GitClonePush();
void GitCloneRepo(std::string project);
void GitClonePull();
void GitCloneStatus();
void GitCloneHistory();
void GitCloneCheckout(std::string name);
void GitCloneBranch(std::string branch);
void OpenDirectoryToFileExplorer();
void GitCloneCheckoutFix();
void SetDefaultTheme();
void SetDarkTheme();
int legionEnv();
int arrow();
void SetVulcanTheme();
void SetOceanTheme();
void TransferFile();
void SelectFile(const std::string& fileName);
std::string GetTime();

//class std::ofstream;
extern std::ofstream logFile;
void LogCommand(const std::string& command);
void GetLog();