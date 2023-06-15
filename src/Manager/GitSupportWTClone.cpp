#include "../include.h"
#include <iostream>
#include <windows.h>

HANDLE colorAttribute = GetStdHandle(STD_OUTPUT_HANDLE);

void GitCloneAdding() {

    std::string note = "Note: Added all files to git";

    

    if (S_OK == system("git add .")) {

        SetConsoleTextAttribute(colorAttribute, 2);
        std::cout << note << std::endl;
        SetConsoleTextAttribute(colorAttribute, 15);

    } else {

        SetConsoleTextAttribute(colorAttribute, 12);
        std::cout << "Error: Wrong command or git application isn't installed" << std::endl;
        SetConsoleTextAttribute(colorAttribute, 15);

    }


}