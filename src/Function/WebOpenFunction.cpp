#include <iostream>
#include "../include.h"

void startApps(std::string name) {

    system(std::string("start " + name).c_str());

}

void closeApps(std::string closeName) {

    system(std::string("taskkill/im " + closeName).c_str());

}