#include <stdio.h>

void asInfo(char *log, char status, size_t size) {
    printf("[INFO] ");
    for (int i = 0; i < size; i++) {
        printf("%c", log[i]);
    }
    printf(": %c\n", status);
}

void asWarning(char *log, char status, size_t size) {
    printf("[WARNING] ");
    for (int i = 0; i < size; i++) {
        printf("%c", log[i]);
    }
    printf(" %c\n", status);
}
