#include <iostream>
#include <fstream>
#include <Windows.h>
#include "../include.h"

// Arrow are for arrow and folder
// legionEnv are for Legion name, files & bytes

std::string GetApplicationPath() {

    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string path(buffer);
    size_t lastSeparator = path.find_last_of("\\/");
    if (lastSeparator != std::string::npos) {
        path = path.substr(0, lastSeparator);
    }
    return path;

}

void SetDefaultTheme() {

    int colorTag = 0;

    std::ofstream writeColorTag(std::string(GetApplicationPath() + "config.cfg"));

    writeColorTag << colorTag;

    writeColorTag.close();

}

void SetDarkTheme() {

    int colorTag = 1;

    std::ofstream writeColorTag(std::string(GetApplicationPath() + "config.cfg"));

    writeColorTag << colorTag;

    writeColorTag.close();

}

void SetVulcanTheme() {

    int colorTag = 2;

    std::ofstream writeColorTag(std::string(GetApplicationPath() + "config.cfg"));

    writeColorTag << colorTag;

    writeColorTag.close();

}

void SetOceanTheme() {

    int colorTag = 3;

    std::ofstream writeColorTag(std::string(GetApplicationPath() + "config.cfg"));

    writeColorTag << colorTag;

    writeColorTag.close();

}

int legionEnv() {

    int colortag;

    std::ifstream getID(std::string(GetApplicationPath() + "config.cfg"));

    getID >> colortag;

    getID.close();

    if (colortag == 0) {

        return 2;

    } else if (colortag == 1) {

        return 7;

    } else if (colortag == 2) {

        return 6;

    } else if (colortag == 3) {

        return 9;

    } else {

        return 2;

    }

}

int arrow() {

    int colortag;

    std::ifstream getID(std::string(GetApplicationPath() + "config.cfg"));

    getID >> colortag;

    getID.close();

    if (colortag == 0) {

        return 12;

    } else if (colortag == 1) {

        return 8;

    } else if (colortag == 3) {

        return 1;

    } else if (colortag == 2) {

        return 12;

    } else {

        return 12;

    }

}