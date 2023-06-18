#include <Windows.h>
#include <iostream>
#include "../include.h"


void OpenDirectoryToFileExplorer() {

    try
    {
        system("start .");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}