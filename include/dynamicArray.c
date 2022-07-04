#include <stdio.h>
// This data structure is written in order to store string and the size will not be decleared beforehand


typedef struct {
    char letter;
    charArray element;
} charArray;


int append(charArray array, char letter) {
    charArray *last = reachToTheEnd(&array);
    last->letter = letter;
    charArray new = {.letter = "", .element = NULL};
    last->element = new;
}


charArray *reachToTheEnd(charArray *array) {
    charArray checker = {.letter = "", .element = NULL};
    if (array->element != checker) {
        reachToTheEnd(*array->element);
    }else {
        return &array->element;
    }
    return &checker;
}

void printTheArray(charArray array) {
    
}