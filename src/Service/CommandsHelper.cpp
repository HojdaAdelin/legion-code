#include <iostream>
#include "../include.h"
#include <windows.h>

HANDLE colorAtribute = GetStdHandle(STD_OUTPUT_HANDLE);

void help(std::string ServiceString) {

    if (ServiceString == "help") {
        commandHelp();
    } else if (ServiceString == "version") {
        std::cout << "\nVersion: 1.3.4\n";
    } else if (ServiceString == "log") {
        SetConsoleTextAttribute(colorAtribute, legionEnv());
        std::cout << "\n$LegionCode v1.3.4\n";
        SetConsoleTextAttribute(colorAtribute, 15);
        std::cout << "\n-Title set\n";
    } else if (ServiceString == ".git" || ".bug" || ".source") {
        WebOpener(ServiceString);
    } 

}

void commandHelp() {

    SetConsoleTextAttribute(colorAtribute, legionEnv());
    std::cout << "MAIN COMMANDS\n";
    SetConsoleTextAttribute(colorAtribute, 15);
    std::cout << "[ help            All commands                   ]          ";
    std::cout << "[ .git            Open github                  ]\n";
    std::cout << "[ .source         Open LegionCode source         ]          ";
    std::cout << "[ .bug            Open bugs website            ]\n";
    std::cout << "[ cd              Directory change               ]          ";
    std::cout << "[ del dir         Delete directory             ]\n";
    std::cout << "[ dir -z          Previous directory             ]          ";
    std::cout << "[ dir -x          Last directory               ]\n";
    std::cout << "[ dir view        View directory                 ]          ";
    std::cout << "[ dir -o          Open directory in explorer   ]\n";
    std::cout << "[ version         Display version                ]          ";
    std::cout << "[ log             Change log                   ]\n";
    std::cout << "[ cls             Clear terminal                 ]          ";
    std::cout << "[ rand min max    Random number                ]\n";
    std::cout << "[ size -f 'file'  File size                      ]          ";
    std::cout << "[ info -f 'file'  File details                 ]\n";
    std::cout << "[ del -f 'file'   Delete file                    ]          ";
    std::cout << "[ -r 'file_name' 'new_name'  Rename file       ]\n";
    std::cout << "[ view 'name'     Content of the file            ]          ";
    std::cout << "[ temp            Clean temp folder            ]\n";
    std::cout << "[ compres 'file'  Archive file                   ]          ";
    std::cout << "[ arh -v 'name'   Display the archive          ]\n";
    std::cout << "[ code .          Open VS Code                   ]          ";
    std::cout << "[ apps view       Display installed apps on PC ]\n";
    std::cout << "[ open 'app'      Open a specific app            ]          ";
    std::cout << "[ close 'app'     Close a specific app         ]\n";
    std::cout << "[ stack 'link'    Store a link enter by the user ]          ";
    std::cout << "[ .web            Open stored link             ]\n";
    std::cout << "[ view stack      Display stored link            ]          ";
    std::cout << "[ open 'link'     Open a link                  ]\n";
    std::cout << "[ delete stack    Delete stored link             ]          ";
    std::cout << "[ set dark        Dark theme                   ]\n";
    std::cout << "[ set vulcan      Vulcan theme                   ]          ";
    std::cout << "[ set 0           Default theme                ]\n";
    std::cout << "[ set ocean       Ocean theme                    ]          ";
    std::cout << "[ select 'file'   Stock file                   ]\n";
    std::cout << "[ transfer        Transfer selected file         ]          ";
    

    SetConsoleTextAttribute(colorAtribute, legionEnv());
    std::cout << "\n\nGit supported commands\n";
    SetConsoleTextAttribute(colorAtribute, 15);
    std::cout << "[ git add . ]\n";
    std::cout << "[ git commit -m ]\n";
    std::cout << "[ git push ]\n";
    std::cout << "[ git clone ]\n";
    std::cout << "[ git pull ]\n";
    std::cout << "[ git status ]\n";
    std::cout << "[ git log ]\n";
    std::cout << "[ git checkout ]\n";
    std::cout << "[ git branch ]\n";

    SetConsoleTextAttribute(colorAtribute, 14);
    std::cout << "\nNote: If archive commands don't work install 7-Zip.\n";
    SetConsoleTextAttribute(colorAtribute, 15);
    
}
