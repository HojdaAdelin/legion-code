#include <iostream>
#include "../include.h"
#include <windows.h>
#include <string>

void DeleteAllFiles(std::string strPath)
{

  WIN32_FIND_DATA wfd;
  HANDLE hFile;
  DWORD dwFileAttr;
  std::string strFile;
  std::string strSpec = strPath + "*.*";
  std::string strPathFile;

  // find the first file
  hFile = FindFirstFile(strSpec.c_str(), &wfd);

  if(hFile != INVALID_HANDLE_VALUE)
	{
    do
		{
      strFile = wfd.cFileName;
      strPathFile = strPath + strFile;
      // get the file attributes
      dwFileAttr = GetFileAttributes(strPathFile.c_str());

      // see if file is read-only : if so unset read-only
      if (dwFileAttr & FILE_ATTRIBUTE_READONLY)
			{
        dwFileAttr &= ~FILE_ATTRIBUTE_READONLY;
        SetFileAttributes(strPathFile.c_str(), dwFileAttr);
      }

      // see if the file is a directory
      if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
        // make sure it isn't current or parent directory
        if(strFile != "." && strFile != "..")
				{
          strPathFile += "\\";
          // recursively delete all files in this folder
          DeleteAllFiles(strPathFile);
          // remove the directory

          if(RemoveDirectory(strPathFile.c_str()))
					{ 
            HANDLE deleteColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(deleteColor, 14);
            std::cout << "deleted directory : ";
            SetConsoleTextAttribute(deleteColor, 15);
            std::cout << strPathFile.c_str() << std::endl;
          }
					else
					{ 
            HANDLE errorColor = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(errorColor, 12);
            std::cout << "could not delete directory : ";
            SetConsoleTextAttribute(errorColor, 15);
            std::cout << strPathFile.c_str() << std::endl;
          }
        }
      }
			else
			{
        // delete the file
        if(DeleteFile(strPathFile.c_str()))
				{
          HANDLE deleteColor = GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(deleteColor, 2);
          std::cout << "deleted file: " << strPathFile.c_str() << std::endl;
          SetConsoleTextAttribute(deleteColor, 15);
        }
				else
				{
          HANDLE deleteColor = GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(deleteColor, 12);
          std::cout << "could not delete file: " << strPathFile.c_str() << std::endl;
          SetConsoleTextAttribute(deleteColor, 15);
        }
      }
    }
		while(FindNextFile(hFile, &wfd));
  }

  FindClose(hFile);
}

void TempExecutable(){

  char szPath[MAX_PATH];

  GetTempPath(MAX_PATH, szPath);

  DeleteAllFiles(szPath);


}