#include <stdio.h>
#include "webMethods.h"
#include <string.h>

int count = 0;
char *requestPointer = "";

int  methodIdentifier(char *request, size_t size){
    requestPointer = request;
    for (int i = 0; i < size; i++) {
        if (request[i] == ' ') {
            break;
        }
        count++;
    }
    return count;

    // printf("[+] We identified the method!");

    // Here is the method struct creation with enum based on the extracted method name
    // if (strcmp(method, "GET") == 0) {
    //     return "It GET request";
    // }else {
    //     if (strcmp(method, "POST") == 0) {
    //         return "It POST request";
    //     } else {
    //         if (strcmp(method, "PUT") == 0) {
    //             return "It PUT request";
    //         } else {
    //             if (strcmp(method, "DELETE") == 0) {
    //                 return "It DELETE request";
    //             } else {
    //                 if (strcmp(method, "UPDATE") == 0) {
    //                     return "It UPDATE request";
    //                 }else {
    //                     if (strcmp(method, "OPTION") == 0) {
    //                         return "It OPTION request";
    //                     } 
    //                 }
    //             }
    //         }
    //     }
    // }

    // return "It is not a web request";
}
