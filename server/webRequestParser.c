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
    printf("The string is %s", methodName);
    if (strcmp(methodName, "GET") == 0) {
        printf("The method name is %s\n", methodName);
        printf("It is GET method\n");
    }else if (strcmp(methodName, "POST") == 0) {
        printf("The method name is %s\n", methodName);
        printf("It is POST method\n");
    }else if (strcmp(methodName, "PUT") == 0) {
        printf("The method name is %s\n", methodName);
        printf("It is PUT method\n");
    }else if (strcmp(methodName, "UPDATE") == 0) {
        printf("The method name is %s\n", methodName);
        printf("It is UPDATE method\n");
    }else if (strcmp(methodName, "DELETE") == 0) {
        printf("The method name is %s\n", methodName);
        printf("It is DELETE method\n");
    }else if (strcmp(methodName, "OPTION") == 0) {
        printf("The method name is %s\n", methodName);
        printf("It is OPTION method\n");
    }

    



}


// It will iterate over the linked list and get all the characters in order to build a char array
void theRequest(charArray *arr) {
    char array[count]; // Initializes the char array to accept the letters
    int counter = 0; // It will be used to add the elements to array
    charArray *element = NULL;
    element = malloc(sizeof(charArray));
    for (element = arr; element != NULL; element = element->element){
        array[counter] = element->letter; // Assigning the letters to char array
        counter++;
    }
    
    test(array);
    
}



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
    printf("The size is %d\n", count);
    theRequest(arr);
    return count;
}





// This will be written after creating the custom data to have dynamically resizable data structure

// request constructingTheRequestObject() {


//     // Here is the method struct creation with enum based on the extracted method name
//     if (strcmp(method, "GET") == 0) {
        
//     }else {
//         if (strcmp(method, "POST") == 0) {
            
//         } else {
//             if (strcmp(method, "PUT") == 0) {
                
//             } else {
//                 if (strcmp(method, "DELETE") == 0) {
                    
//                 } else {
//                     if (strcmp(method, "UPDATE") == 0) {
                        
//                     }else {
//                         if (strcmp(method, "OPTION") == 0) {
                            
//                         } 
//                     }
//                 }
//             }
//         }
//     }


//     request peerRequest = {};

//     return peerRequest;
// }
