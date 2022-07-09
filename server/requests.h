#ifndef REQUESTS_H
#define REQUESTS_H

enum methods {
    GET,
    POST,
    DELETE,
    PATCH,
    PUT,
    OPTIONS,
    ERROR
};

typedef struct request{

    enum methods method;
    char *path;
    char *host;

} request;

#endif