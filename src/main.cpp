#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include "include.h"
#include <handleapi.h>
#include <windows.h>
#include <stack>
std::stack<std::filesystem::path> directoryStack;

int main() {

    std::string command;
    while (true) {

        HANDLE Legion = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(Legion, legionEnv());
        std::cout << "$LegionCode ";
        SetConsoleTextAttribute(Legion, 15);

        std::cout << std::filesystem::current_path() << std::endl;

        // Color <<<
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, arrow());
        std::cout << ">>> ";
        SetConsoleTextAttribute(hConsole, 15);

        std::getline(std::cin, command);
        
        if (command == "exit") {

            system("exit");

        } else if (command.substr(0, 7) == "size -f") {
            std::cout << "\n";
            std::string filename = command.substr(8);
            displayFileSize(filename);
            std::cout << "\n";

        } else if (command.substr(0, 7) == "info -f") {
            std::cout << "\n";
            std::string filename = command.substr(8);
            displayFileDetails(filename);
            std::cout << "\n";

        } else if (command.substr(0, 6) == "del -f") {
            std::cout << "\n";
            std::string filename = command.substr(7);
            deleteFile(filename);
            std::cout << "\n";
            
        } else if (command.substr(0, 7) == "compres") {
            std::cout << "\n";
            std::string filename = command.substr(8);
            compressFile(filename);
            std::cout << "\n";
            
        } else if (command == "code .") {

            system("code .");
            std::cout << "\n";
            
        } else if (command == "git status") {

            std::cout << "\n";
            GitCloneStatus();
            std::cout << "\n";

        } else if (command == "git checkout") {

            std::cout << "\n";
            GitCloneCheckoutFix();
            std::cout << "\n";

        } else if (command == "git log") {

            std::cout << "\n";
            GitCloneHistory();
            std::cout << "\n";

        } else if (command == "dir -o") {

            std::cout << "\n";
            OpenDirectoryToFileExplorer();
            std::cout << "\n";

        } else if (command.substr(0, 12) == "git checkout") {

            std::string name = command.substr(13);
            std::cout << "\n";
            GitCloneCheckout(name);
            std::cout << "\n";

        } else if (command.substr(0, 10) == "git branch") {

            std::string branch = command.substr(11);
            std::cout << "\n";
            GitCloneBranch(branch);
            std::cout << "\n";

        } else if (command == "git push") {

            std::cout << "\n";
            GitClonePush();
            std::cout << "\n";

        } else if (command == "git pull") {

            std::cout << "\n";
            GitClonePull();
            std::cout << "\n";

        } else if (command == "set vulcan") {

            std::cout << "\n";
            SetVulcanTheme();
            arrow();
            legionEnv();

        } else if (command == "set ocean") {

            std::cout << "\n";
            SetOceanTheme();
            arrow();
            legionEnv();

        } else if (command == "set dark") {

            std::cout << "\n";
            SetDarkTheme();
            arrow();
            legionEnv();

        } else if (command == "set 0") {

            std::cout << "\n";
            SetDefaultTheme();
            arrow();
            legionEnv();

        } else if (command.substr(0, 13) == "git commit -m") {

            std::string text = command.substr(14);
            std::cout << "\n";
            GitCloneMerge(text);
            std::cout << "\n";

        } else if (command.substr(0, 9) == "git clone") {

            std::string project = command.substr(10);
            std::cout << "\n";
            GitCloneRepo(project);
            std::cout << "\n";

        } else if (command == "dir -z") {
            std::cout << "\n";
            std::filesystem::path currentPath = std::filesystem::current_path();
            directoryStack.push(currentPath);
            goToPreviousDirectory();
            std::cout << "\n";

        } else if (command == "git add .") {

            std::cout<<"\n";
            GitCloneAdding();
            std::cout<<"\n";

        } else if (command == "dir -x") {
            std::cout << "\n";
            goToLastDirectory(directoryStack);
            std::cout << "\n";
            
        } else if (command.substr(0, 3) == "cd ") {
            std::cout << "\n";
            std::string directory = command.substr(3);
            directoryManager(directory);
            std::cout << "\n";

        } else if (command == "del dir") {
            std::cout << "\n";
            deleteDirectory();
            std::cout << "\n";
            
        } else if (command == "cls") {

            system("cls");
            main();

        } else if (command == "help") {
            std::cout << "\n";
            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == ".git") {
            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == ".source") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == ".bug") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command.substr(0, 5) == "open ") {

            std::string app = command.substr(5);
            startApps(app);
            std::cout << "\n";

        } else if (command.substr(0, 6) == "close ") {

            std::cout << "\n";
            std::string close = command.substr(6);
            closeApps(close);
            std::cout << "\n";

        } else if (command.substr(0, 6) == "stack ") {

            std::cout << "\n";
            std::string link = command.substr(6);
            stackLink(link);
            std::cout << "\n";

        } else if (command.substr(0, 5) =="open ") {

            std::cout << "\n";
            std::string link = command.substr(5);
            userOpenLink(link);

        } else if (command == "temp") {

            std::cout << "\n";
            TempExecutable();
            std::cout << "\n";

        } else if (command == "delete stack") {

            std::cout << "\n";
            userLinkDelete();
            std::cout << "\n";

        } else if (command == ".web") {
            
            openStackedLink();
            std::cout << "\n";

        } else if (command.substr(0, 7) == "arh -v ") {

            std::cout << "\n";
            const std::string& arhive = command.substr(7);
            displayArchiveContent(arhive);
            std::cout << "\n";

        } else if (command == "view stack") {

            std::cout << "\n";

            viewStackedLink();

            std::cout << "\n";
        } else if (command.substr(0, 5) == "view ") {

            std::cout << "\n";
            std::string file = command.substr(5);
            viewFileContent(file);
            std::cout << "\n";

        } else if (command == "version") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command == "dir view") {
            std::cout << "\n";
            viewDirectoryContents();
            std::cout << "\n";

        } else if (command == "apps view") {
            
            std::cout << "\n";
            viewInstalledApps();
            std::cout << "\n";

        } else if (command == "log") {

            std::string Service = command;
            help(Service);
            std::cout << "\n";

        } else if (command.substr(0, 4) == "rand") {
            std::cout << "\n";
            size_t firstSpacePos = command.find(' ');
            if (firstSpacePos != std::string::npos) {
                size_t secondSpacePos = command.find(' ', firstSpacePos + 1);
                if (secondSpacePos != std::string::npos) {
                    std::string minString = command.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
                    std::string maxString = command.substr(secondSpacePos + 1);
                    
                    try {
                        int minim = std::stoi(minString);
                        int maxim = std::stoi(maxString);
                        generatorNumber(minim, maxim);
                        
                    } catch (const std::invalid_argument&) {
                        std::cerr << "Invalid arguments. Please enter integer values for 'min' and 'max'." << std::endl;
                    }
                } else {
                    std::cout << "Invalid command" << std::endl;
                }
            } else {
                std::cout << "Invalid command" << std::endl;
            }
            std::cout << "\n";
        } else if (command.substr(0, 2) == "-r") {
            std::cout << "\n";
            size_t firstSpacePos = command.find(' ');
            if (firstSpacePos != std::string::npos) {
                size_t secondSpacePos = command.find(' ', firstSpacePos + 1);
                if (secondSpacePos != std::string::npos) {
                    std::string filename = command.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
                    std::string newname = command.substr(secondSpacePos + 1);
                    renameFile(filename, newname);
                } else {
                    std::cout << "Invalid command" << std::endl;
                }
            } else {
                std::cout << "Invalid command" << std::endl;
            }
            std::cout << "\n";
        } else {

            HANDLE errorWin = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(errorWin, 12);
            std::cout << "\nError: Wrong command\n\n";
            SetConsoleTextAttribute(errorWin, 15);

        }
    }

    return 0;

}