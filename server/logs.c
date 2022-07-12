#include <stdio.h>

void requestLogging(const char *method, const char *path, const char *host) {
    printf("[INFO] Method: %s, Host: %s, Path: %s\n", method, host, path);
}
