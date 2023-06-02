#include <iostream>
#include <fstream>
#include "../include.h"
#include <windows.h>


void stackLink(std::string stack) {

    std::ofstream storeLink("link.txt");
    storeLink << stack;

    storeLink.close();
    HANDLE stackColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(stackColor, 2);
    std::cout << stack;
    SetConsoleTextAttribute(stackColor, 15);
    std::cout << " was succesfully stored!\n";
}

void openStackedLink() {

    std::string link;
    std::ifstream readLink("link.txt");
    readLink >> link;

    readLink.close();
    
    if (int open = system(std::string("start " + link).c_str()) != 0) {
        open = system(std::string("start https://" + link).c_str());
    } 

}

void viewStackedLink() {

    std::string link;
    std::ifstream readLink("link.txt");

    readLink >> link;

    readLink.close();
    std::cout << "Stored link: ";
    HANDLE storedLink = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(storedLink, 2);
    std::cout << link << std::endl;
    SetConsoleTextAttribute(storedLink, 15);

}

void userOpenLink(std::string inputLink) {

    system(std::string("start " + inputLink).c_str());

}

void userLinkDelete() {

    std::ofstream deleteLink("link.txt");

    deleteLink << " " << std::endl;

    deleteLink.close();
    
    std::cout << "The link was deleted!" << std::endl;

}