#include <iostream>
#include <fstream>
#include <string>
#include "../include.h"

// Function to set the text color
void setTextAttribute(int attribute) {
    std::cout << "\033[" << attribute << "m";
}

// Function to reset the text color
void resetTextAttribute() {
    std::cout << "\033[0m";
}

// Function to highlight keywords in the text
void highlightKeywords(const std::string& line) {
    std::string keyword;
    std::string::size_type startPos = 0;
    std::string::size_type endPos = 0;

    while (startPos != std::string::npos) {
        startPos = line.find_first_not_of(" \t\n\r\f\v", endPos);
        if (startPos == std::string::npos)
            break;

        endPos = line.find_first_of(" \t\n\r\f\v", startPos);
        if (endPos == std::string::npos)
            endPos = line.length();

        keyword = line.substr(startPos, endPos - startPos);
        if (keyword == "if") {
            setTextAttribute(32); 
        } else if (keyword == "for") {
            setTextAttribute(33); 
        } else if (keyword == "while") {
            setTextAttribute(34); 
        } else if (keyword == "(") {
            setTextAttribute(34);
        } else if (keyword == ")") {
            setTextAttribute(34);
        } else if (keyword == "{") {
            setTextAttribute(34);
        } else if (keyword == "}") {
            setTextAttribute(34);
        } else if (keyword == "int") {
            setTextAttribute(35);
        } else if (keyword == "string") {
            setTextAttribute(208);
        } else if (keyword == "=") {
            setTextAttribute(208);
        } 

        std::cout << keyword;
        resetTextAttribute();

        if (endPos == line.length())
            break;

        std::cout << line[endPos];
        endPos++;
    }
}