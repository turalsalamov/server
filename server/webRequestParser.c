#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logs.c"
#include "requests.h"
#include "../include/dynamicArray.h"
#include "../include/dynamicArray.c"



// Initializing global variables for use
int methodCount = 0; // It is the size of the request method
int pathCount = 0; // It is the size of the request method

// It is used in order to print the method enum as string
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

// Contructing the request object
enum methods getMethod(charArray *methodArr) {
    enum methods method;
    char methodArray[methodCount]; // Initializes the char array to accept the letters
    int methodCounter = 0; // It will be used to add the elements to array
    // It is for getting the method from linkedlist (charArray)
    for (charArray *methodElement = methodArr; methodElement!= NULL; methodElement = methodElement->element){
        methodArray[methodCounter] = methodElement->letter; // Assigning the letters to char array
        methodCounter++;
    }
    
    if (strcmp(methodArray, "GET") == 0) {
        method = GET;
    }
    else if (strcmp(methodArray, "POST") == 0) {
        method = POST;
    }
    else if (strcmp(methodArray, "PUT") == 0) {
        method = PUT;
    }
    else if (strcmp(methodArray, "PATCH") == 0) {
        method = PATCH;
    }
    else if (strcmp(methodArray, "DELETE") == 0) {
        method = DELETE;
    }
    else if (strcmp(methodArray, "OPTIONS") == 0) {
        method = OPTIONS;
    } else {
        method = ERROR;
    }
    // Constructing a request
    return method;
}

// It will iterate over the linked list and get all the characters in order to build a char array
const char *getPath(charArray *pathArr) {

    char pathArray[pathCount];    
    int pathCounter = 0; // It will be used to add the elements to array
    
    // It is for getting the path from linkedlist (charArray)
    for (charArray *arrayElement = pathArr; arrayElement != NULL; arrayElement = arrayElement->element){
        pathArray[pathCounter] = arrayElement->letter; // Assigning the letters to char array
        pathCounter++;
    }
    const char *path = pathArray;

    // Retrieving the path
    return path;
}

// It will give the information about with which method it is requested by peer.
void  requestHandler(char *incomningRequest, char *peerAddress, size_t size) {
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
            pathCount = i - methodCount - 1;
            break;
        }
        
        if (!flag)
            append(&method, *(incomningRequest + i));
        else 
            append(&path, *(incomningRequest + i));
    }
    enum methods methodName = getMethod(method);
    const char *pathName = getPath(path);

    request peerRequest = {.method = methodName, .host = peerAddress, .path = pathName};

    // Printing the logs in terminal
    requestLogging(methodNameStringify(peerRequest.method), peerRequest.path, peerRequest.host);
}