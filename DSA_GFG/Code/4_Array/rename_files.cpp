#include <iostream>
#include <string>
#include <windows.h>

int main() {
    std::string folderPath;
    std::cout << "Enter folder path: ";
    std::getline(std::cin, folderPath);

    if (folderPath.empty()) {
        std::cerr << "Folder path is empty.\n";
        return 1;
    }

    if (folderPath.back() != '\\')
        folderPath += "\\"; // Ensure trailing backslash

    std::string searchPath = folderPath + "*";

    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Could not open folder.\n";
        return 1;
    }

    const std::string target = "yt1s.com - ";

    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::string filename = findData.cFileName;

            size_t pos = filename.find(target);
            if (pos != std::string::npos) {
                std::string newFilename = filename;
                newFilename.erase(pos, target.length());

                std::string oldPath = folderPath + filename;
                std::string newPath = folderPath + newFilename;

                if (MoveFile(oldPath.c_str(), newPath.c_str())) {
                    std::cout << "Renamed: " << filename << " -> " << newFilename << "\n";
                } else {
                    std::cerr << "Failed to rename: " << filename << "\n";
                }
            }
        }
    } while (FindNextFile(hFind, &findData) != 0);

    FindClose(hFind);
    return 0;
}
