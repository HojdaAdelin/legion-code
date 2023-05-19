#include <iostream>
#include "../include.h"

void help(std::string ServiceString) {

    if (ServiceString == "help") {
        commandHelp();
    } else if (ServiceString == ".git" || ".bug" || ".source") {
        WebOpener(ServiceString);
    }

}

void commandHelp() {

    std::cout << "\n";
    std::cout << "help          Display commands\n";
    std::cout << ".git          Open github\n";
    std::cout << ".source       Open LegionCode source\n";
    std::cout << ".bug          Open bugs website\n";
    std::cout << "cd            Directory change\n";

}