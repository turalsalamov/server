#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "webMethods.h"
#include "../include/dynamicArray.h"
#include "../include/dynamicArray.c"



// Initializing global variables for use
int count = 0; // It is the size of the request typw
char *requestPointer = NULL; // It handles the incoming peer request


void test(const char *methodName) {
    if (strcmp(methodName, "GET") == 0) {
        printf("The method name is %s\n", methodName);
    }else if (strcmp(methodName, "POST") == 0) {
        printf("The method name is %s\n", methodName);
    }else if (strcmp(methodName, "PUT") == 0) {
        printf("The method name is %s\n", methodName);
    }else if (strcmp(methodName, "PATCH") == 0) {
        printf("The method name is %s\n", methodName);
    }else if (strcmp(methodName, "DELETE") == 0) {
        printf("The method name is %s\n", methodName);
    }else if (strcmp(methodName, "OPTIONS") == 0) {
        printf("The method name is %s\n", methodName);
    }
}


// It will iterate over the linked list and get all the characters in order to build a char array
void theRequest(charArray *arr) {
    char array[count]; // Initializes the char array to accept the letters
    int counter = 0; // It will be used to add the elements to array
    charArray *arrayElement = NULL;
    for (arrayElement = arr; arrayElement != NULL; arrayElement = arrayElement->element){
        array[counter] = arrayElement->letter; // Assigning the letters to char array
        counter++;
    }
    
    test(array);
    
}


// It will give the information about with which method it is requested by peer.
int  methodIdentifier(char *request, size_t size){
    count = 0;
    requestPointer = request;
    charArray *arr = NULL;
    for (int i = 0; i < size; i++) {
        if (request[i] == ' ') {
            break;
        }
        append(&arr, *(request + i));
        count++;
    }
    theRequest(arr);
    return count;
}