#include <iostream>
#include <fstream>
#include "../include.h"


void stackLink(std::string stack) {

    std::ofstream storeLink("link.txt");
    storeLink << stack;

    storeLink.close();
    std::cout << stack << " was successfully stored!\n";
}

void openStackedLink() {

    std::string link;
    std::ifstream readLink("link.ini");
    readLink >> link;

    readLink.close();

    system(std::string("start " + link).c_str());

}