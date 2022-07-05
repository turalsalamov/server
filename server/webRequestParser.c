#include <stdio.h>
#include <stdlib.h>
#include "webMethods.h"
#include "../include/dynamicArray.c" 

int count = 0;
char *requestPointer = "";

int  methodIdentifier(char *request, size_t size){
    count = 0;
    requestPointer = request;
    charArray *arr;
    arr = malloc(sizeof(charArray));
    for (int i = 0; i < size; i++) {
        if (request[i] == ' ') {
            break;
        }
        int success = append(arr, *(request + i));
        // printf("The first letter is %c\n", arr->letter);
        count++;
    }
    
    // printTheArray(arr);

    // constructingTheRequestObject();
    return count;
}


// This will be written after creating the custom data to have dynamically resizable data structure

// request constructingTheRequestObject() {

//     // Here is the method struct creation with enum based on the extracted method name
//     if (strcmp(method, "GET") == 0) {
//         return "It GET request";
//     }else {
//         if (strcmp(method, "POST") == 0) {
//             return "It POST request";
//         } else {
//             if (strcmp(method, "PUT") == 0) {
//                 return "It PUT request";
//             } else {
//                 if (strcmp(method, "DELETE") == 0) {
//                     return "It DELETE request";
//                 } else {
//                     if (strcmp(method, "UPDATE") == 0) {
//                         return "It UPDATE request";
//                     }else {
//                         if (strcmp(method, "OPTION") == 0) {
//                             return "It OPTION request";
//                         } 
//                     }
//                 }
//             }
//         }
//     }


//     request peerRequest = {};

//     return peerRequest;
// }
