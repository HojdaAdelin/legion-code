#include <iostream>
#include <fstream>
#include <Windows.h>
#include "../include.h"

// Arrow are for arrow and folder
// legionEnv are for Legion name, files & bytes

void SetDefaultTheme() {

    int colorTag = 0;

    std::ofstream writeColorTag("config.cfg");

    writeColorTag << colorTag;

    writeColorTag.close();

}

void SetDarkTheme() {

    int colorTag = 1;

    std::ofstream writeColorTag("config.cfg");

    writeColorTag << colorTag;

    writeColorTag.close();

}

void SetVulcanTheme() {

    int colorTag = 2;

    std::ofstream writeColorTag("config.cfg");

    writeColorTag << colorTag;

    writeColorTag.close();

}

void SetOceanTheme() {

    int colorTag = 3;

    std::ofstream writeColorTag("config.cfg");

    writeColorTag << colorTag;

    writeColorTag.close();

}

int legionEnv() {

    int colortag;

    std::ifstream getID("config.cfg");

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

    std::ifstream getID("config.cfg");

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