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


void GitCloneMerge(std::string text) {

    std::string note = "Note: Modifications added";

    try
    {
        
        system(std::string("git commit -m " + text).c_str());

    }
    catch(const std::exception& e)
    {   
        SetConsoleTextAttribute(colorAttribute, 14);
        std::cerr << e.what() << '\n';
        SetConsoleTextAttribute(colorAttribute, 15);
    }
    
}

void GitClonePush() {

    try
    {
        system("git push");
    }
    catch(const std::exception& e)
    {   
        SetConsoleTextAttribute(colorAttribute, 14);
        std::cerr << e.what() << '\n';
        SetConsoleTextAttribute(colorAttribute, 15);
    }
    

}

void GitCloneRepo(std::string project) {

    try
    {
        
        system(std::string("git clone " + project).c_str());

    }
    catch(const std::exception& e)
    {
        SetConsoleTextAttribute(colorAttribute, 14);
        std::cerr << e.what() << '\n';
        SetConsoleTextAttribute(colorAttribute, 15);
    }
    

}

void GitClonePull() {

    try
    {
        system("git pull");
    }
    catch(const std::exception& e)
    {   
        SetConsoleTextAttribute(colorAttribute, 14);
        std::cerr << e.what() << '\n';
        SetConsoleTextAttribute(colorAttribute, 15);
    }
    

}