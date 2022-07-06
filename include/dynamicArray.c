#include <stdio.h>
#include "dynamicArray.h"


void append(charArray *array, char letterOfWord) {
    if (array != NULL) {
        append(array->element, letterOfWord);  
        return;
    }
    
    charArray *new = NULL;
    new = malloc(sizeof(charArray));
    new->letter = letterOfWord;
    new->element = NULL;
    array = new;
}