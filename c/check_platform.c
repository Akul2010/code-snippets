#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#define OS_NAME "Windows"
#elif __linux__
#define OS_NAME "Linux"
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_MAC
#define OS_NAME "Mac OS X"
#endif
#endif

const char* get_os_name() {
  return OS_NAME;
}

int main() {
  printf("Operating System: %s\n", get_os_name());
  return 0;
}
