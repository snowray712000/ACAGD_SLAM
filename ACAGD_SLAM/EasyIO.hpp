#pragma once
#include <iostream>
#include <string>
#include <Windows.h>    // for GetModuleFileNameA, GetLastError
#include <fstream>
namespace EasyIO {
    //  ¤£§t§À³¡ \ ¦r¤¸
    inline std::string getExeDir()
    {
        char path[MAX_PATH];
        if (GetModuleFileNameA(NULL, path, MAX_PATH) == 0) {
            std::cerr << "Error: GetModuleFileNameA failed, error code = " << GetLastError() << std::endl;
            return "";
        }

        std::string dirPath(path);
        size_t pos = dirPath.find_last_of("\\/");
        if (pos != std::string::npos) {
            dirPath = dirPath.substr(0, pos);
        }

        return dirPath;
    }
    inline bool fileExists(const std::string& filename)
    {
        std::ifstream file(filename);
        return file.good();
    }
}