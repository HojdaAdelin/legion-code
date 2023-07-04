#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "../include.h"

void viewInstalledApps() {
    HANDLE registreColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(registreColor, 2);
    HKEY hUninstallKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hUninstallKey) == ERROR_SUCCESS) {
        DWORD dwIndex = 0;
        WCHAR szDisplayName[1024];
        DWORD dwDisplayNameSize = sizeof(szDisplayName);
        while (RegEnumKeyExW(hUninstallKey, dwIndex, szDisplayName, &dwDisplayNameSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
            HKEY hAppKey;
            if (RegOpenKeyExW(hUninstallKey, szDisplayName, 0, KEY_READ, &hAppKey) == ERROR_SUCCESS) {
                WCHAR szAppName[1024];
                DWORD dwAppNameSize = sizeof(szAppName);
                if (RegQueryValueExW(hAppKey, L"DisplayName", NULL, NULL, (LPBYTE)szAppName, &dwAppNameSize) == ERROR_SUCCESS) {
                    char szAppNameA[1024];
                    WideCharToMultiByte(CP_UTF8, 0, szAppName, -1, szAppNameA, sizeof(szAppNameA), NULL, NULL);
                    std::cout << szAppNameA << std::endl;
                }
                RegCloseKey(hAppKey);
            }
            dwDisplayNameSize = sizeof(szDisplayName);
            dwIndex++;
        }
        RegCloseKey(hUninstallKey);
        SetConsoleTextAttribute(registreColor, 15);
    }
}

std::ofstream logFile;

void LogCommand(const std::string& command) {
    if (logFile.is_open()) {
        logFile << command << std::endl;
        logFile.flush();
    }
}

void GetLog() {

    std::string line;

    std::ifstream readLog("log.txt");

    while (std::getline(readLog, line))
    {
        std::cout << line << "\n";
    }
    

    readLog.close();

}