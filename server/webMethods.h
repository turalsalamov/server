#ifndef WEBMETHODS_H
#define WEBMETHODS_H

enum methods {
    GET,
    POST,
    DELETE,
    UPDATE,
    PUT,
    OPTION
};

typedef struct {

    enum methods method;
    char *path;
    char *host;

} request;

#endif