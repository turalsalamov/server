#include <stdio.h>
#include <stdlib.h>
#include "webMethods.h"
#include "../include/dynamicArray.h"
#include "../include/dynamicArray.c"


// There is a memory issue in heap

void theRequest(charArray *arr);

int count = 0;
char *requestPointer = NULL;

int  methodIdentifier(char *request, size_t size){
    count = 0;
    requestPointer = request;
    charArray *arr = NULL;
    arr = malloc(sizeof(charArray));
    printf("Request 0 is %c\n", request[0]);
    for (int i = 0; i < size; i++) {
        if (request[i] == ' ') {
            break;
        }
        append(arr, *(request + i));
        count++;
    }
    theRequest(arr);
    return count;
}


void theRequest(charArray *arr) {
    char array[count];
    int counter = 0;
    charArray *element = NULL;
    element = malloc(sizeof(charArray));
    for (element = arr; element != NULL; element = element->element){
        array[counter] = element->letter;
        printf("struct %c\n", element->letter);
        // printf("char %c", array[counter]);
        counter++;
    }
    printf("char %c", array[1]);
    printf("The method is %ld\n", sizeof(array));
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
