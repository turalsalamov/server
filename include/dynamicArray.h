#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


typedef struct charArray {
    char letter;
    struct charArray *element;
} charArray;


#endif