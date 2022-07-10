#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requests.h"
#include "../include/dynamicArray.h"
#include "../include/dynamicArray.c"



// Initializing global variables for use
int methodCount = 0; // It is the size of the request method
int pathCount = 0; // It is the size of the request method

const char* methodNameStringify(enum methods method) {
    if (method == 0) {
        return "GET";
    } else if (method == 1) {
        return "POST";
    } else if (method == 2) {
        return "DELETE";
    } else if (method == 3) {
        return "PATCH";
    } else if (method == 4) {
        return "PUT";
    } else if (method  == 5) {
        return "OPTIONS";
    }

    return "The method have not set properly!";
}

request constructRequest(const char *methodName, const char *requestedPath) {
    enum methods method;
    if (strcmp(methodName, "GET") == 0) {
        method = GET;
    }
    else if (strcmp(methodName, "POST") == 0) {
        method = POST;
    }
    else if (strcmp(methodName, "PUT") == 0) {
        method = PUT;
    }
    else if (strcmp(methodName, "PATCH") == 0) {
        method = PATCH;
    }
    else if (strcmp(methodName, "DELETE") == 0) {
        method = DELETE;
    }
    else if (strcmp(methodName, "OPTIONS") == 0) {
        method = OPTIONS;
    } else {
        method = ERROR;
    }
    request requestInfo = {.method = method, .host = "localhost", .path = requestedPath};
    return requestInfo;
}

// It will iterate over the linked list and get all the characters in order to build a char array
request getRequest(charArray *methodArr, charArray *pathArr) {
    char methodArray[methodCount]; // Initializes the char array to accept the letters
    char pathArray[pathCount];
    int methodCounter = 0; // It will be used to add the elements to array
    int pathCounter = 0; // It will be used to add the elements to array
    
    for (charArray *methodElement = methodArr; methodElement!= NULL; methodElement = methodElement->element){
        methodArray[methodCounter] = methodElement->letter; // Assigning the letters to char array
        methodCounter++;
    }
    for (charArray *arrayElement = pathArr; arrayElement != NULL; arrayElement = arrayElement->element){
        pathArray[pathCounter] = arrayElement->letter; // Assigning the letters to char array
        pathCounter++;
    }
    return constructRequest(methodArray, pathArray);
}


// It will give the information about with which method it is requested by peer.
void  methodIdentifier(char *incomningRequest, size_t size){
    int flag = 0;
    methodCount = 0;
    pathCount = 0;
    charArray *method = NULL;
    charArray *path = NULL;
    for (int i = 0; i < size; i++) {
        if (incomningRequest[i] == ' ' && !flag) {
            methodCount = i;
            flag = 1;
            continue;
        }
        if (incomningRequest[i] == ' ' && flag) {
            pathCount = i - methodCount;
            break;
        }
        if (!flag) append(&method, *(incomningRequest + i));
        else append(&path, *(incomningRequest + i));
    }
    request peerRequest = getRequest(method, path);
    printf("[INFO] Method: %s, Host: %s, Path: %s", methodNameStringify(peerRequest.method),
                                                     peerRequest.host, peerRequest.path);
}

