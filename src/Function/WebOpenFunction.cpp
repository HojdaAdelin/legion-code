#include <iostream>
#include "../include.h"

void startApps(std::string name) {

    system(std::string("start " + name).c_str());

}