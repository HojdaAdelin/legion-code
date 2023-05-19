#include <iostream>
#include "../include.h"
#include <string>

void WebOpener(std::string Atribute) {

    std::string git = "https://github.com";
    std::string bug = "https://github.com/HojdaAdelin/legion-code/issues";
    std::string source = "https://github.com/HojdaAdelin/legion-code";

    if (Atribute == ".git") {

        system(std::string("start " + git).c_str());

    } else if (Atribute == ".bug") {

        system(std::string("start " + bug).c_str());

    } else if (Atribute == ".source") {

        system(std::string("start " + source).c_str());

    }
    
}

