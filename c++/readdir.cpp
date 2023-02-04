#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#else
#include <dirent.h>
#endif

#include <vector>
#include <string>

std::vector<std::string> listDirectoryContents(const char* directoryPath) {
  std::vector<std::string> contents;

#ifdef _WIN32
  WIN32_FIND_DATA ffd;
  HANDLE hFind = FindFirstFile((std::string(directoryPath) + "\\*").c_str(), &ffd);

  if (hFind == INVALID_HANDLE_VALUE) {
    return contents;
  }

  do {
    contents.push_back(ffd.cFileName);
  } while (FindNextFile(hFind, &ffd) != 0);

  FindClose(hFind);
#else
  DIR* dir = opendir(directoryPath);
  if (!dir) {
    return contents;
  }

  struct dirent* ent;
  while ((ent = readdir(dir)) != NULL) {
    contents.push_back(ent->d_name);
  }

  closedir(dir);
#endif

  return contents;
}
