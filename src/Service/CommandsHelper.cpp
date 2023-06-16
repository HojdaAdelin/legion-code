#include <iostream>
#include "../include.h"
#include <windows.h>

HANDLE colorAtribute = GetStdHandle(STD_OUTPUT_HANDLE);

void help(std::string ServiceString) {

    if (ServiceString == "help") {
        commandHelp();
    } else if (ServiceString == "version") {
        std::cout << "\nVersion: 1.2.1\n";
    } else if (ServiceString == "log") {
        std::cout << "\n-Temp clean\n-Arhive view\n-Modul view update\n-Change colors\n-Git add\n-Note added\n-Git commit command\n-Git push\n-Git clone\n-Git pull\n-Git status\n-Git log\n";
    } else if (ServiceString == ".git" || ".bug" || ".source") {
        WebOpener(ServiceString);
    } 

}

void commandHelp() {

    SetConsoleTextAttribute(colorAtribute, 2);
    std::cout << "MAIN COMMANDS\n";
    SetConsoleTextAttribute(colorAtribute, 15);
    std::cout << "help              Display commands\n";
    std::cout << ".git              Open github\n";
    std::cout << ".source           Open LegionCode source\n";
    std::cout << ".bug              Open bugs website\n";
    std::cout << "cd                Directory change\n";
    std::cout << "cls               Clear terminal\n";
    std::cout << "version           Display current version\n";
    std::cout << "log               Change log\n";
    std::cout << "del dir           Delete current directory\n";
    std::cout << "size -f 'file'    Display file size from a directory\n";
    std::cout << "info -f 'file'    Display file details from a directory\n";
    std::cout << "del -f 'file'     Delete file from a directory\n";
    std::cout << "-r 'file_name' 'new_name'         Rename file from the directory\n";
    std::cout << "dir view          View directory content\n";
    std::cout << "dir -z            Go to previous directory\n";
    std::cout << "dir -x            Go to last directory\n";
    std::cout << "rand 'min' 'max'  Random number between min and max numbers we enter\n";
    std::cout << "compres 'file'    Create a .zip arhive with the file\n";
    std::cout << "code .            Open VS Code on current directory\n";
    std::cout << "apps view         Display all apps that are installed on user PC\n";
    std::cout << "open 'app name'   Open a specific app\n";
    std::cout << "close 'app name'  Close a specific app\n";
    std::cout << "view 'file name'  Display the content of the file\n";
    std::cout << "stack 'link'      Store a link enter by the user\n";
    std::cout << ".web              Open the link was stored\n";
    std::cout << "view stack        Display stored link\n";
    std::cout << "open 'link'       Open a link\n";
    std::cout << "delete stack      Delete stored link\n";
    std::cout << "temp              Clean temp folder\n";
    std::cout << "arh -v 'name'     Display the content of an arhive\n";

    SetConsoleTextAttribute(colorAtribute, 2);
    std::cout << "\nGit supported commands\n";
    SetConsoleTextAttribute(colorAtribute, 15);
    std::cout << "git add .\n";
    std::cout << "git commit -m\n";
    std::cout << "git push\n";
    std::cout << "git clone\n";
    std::cout << "git pull\n";
    std::cout << "git status\n";
    std::cout << "git log\n";

    SetConsoleTextAttribute(colorAtribute, 14);
    std::cout << "\nNote: If archive commands don't work install 7-Zip.\n";
    SetConsoleTextAttribute(colorAtribute, 15);
    
}
