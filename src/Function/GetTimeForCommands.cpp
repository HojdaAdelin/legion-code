#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "../include.h"

std::string GetTime() {

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm* timeInfo = std::localtime(&currentTime);
    std::stringstream ss;
    ss << std::put_time(timeInfo, "%H:%M");

    std::string timeString = ss.str();
    std::string finalTime = "[" + timeString + "]";
    return finalTime;

}