#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requests.h"
#include "../include/dynamicArray.h"
#include "../include/dynamicArray.c"



// Initializing global variables for use
int count = 0; // It is the size of the request typw
char *requestPointer = NULL; // It handles the incoming peer request

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

request constructRequest(const char *methodName) {
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

    request requestInfo = {.method = method, .host = "localhost", .path = "/alma"};
    return requestInfo;
}

// It will iterate over the linked list and get all the characters in order to build a char array
request getRequest(charArray *arr) {
    char array[count]; // Initializes the char array to accept the letters
    int counter = 0; // It will be used to add the elements to array
    charArray *arrayElement = NULL;
    for (arrayElement = arr; arrayElement != NULL; arrayElement = arrayElement->element){
        array[counter] = arrayElement->letter; // Assigning the letters to char array
        counter++;
    }
    
    return constructRequest(array);
}


// It will give the information about with which method it is requested by peer.
void  methodIdentifier(char *incomningRequest, size_t size){
    count = 0;
    requestPointer = incomningRequest;
    charArray *arr = NULL;
    for (int i = 0; i < size; i++) {
        if (incomningRequest[i] == ' ') {
            count = i;
            break;
        }
        append(&arr, *(incomningRequest + i));
    }
    request peerRequest = getRequest(arr);
    printf("[INFO] Method: %s, Host: %s, Path: %s", methodNameStringify(peerRequest.method),
                                                     peerRequest.host, peerRequest.path);
}

