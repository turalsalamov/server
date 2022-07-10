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
    const char *path;
    const char *host;

} request;

#endif