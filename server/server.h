#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <arpa/inet.h>


typedef struct{
    short int               sin_family;
    unsigned short int      sin_port;
    struct in_addr          sin_addr;
    unsigned char           sin_zero[8];
} addressStruct;

#endif