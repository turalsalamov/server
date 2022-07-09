#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include "protocols.h"

typedef struct{
    short int               sin_family;
    unsigned short int      sin_port;
    struct in_addr          sin_addr;
    unsigned char           sin_zero[8];
} addressStruct;

#endif