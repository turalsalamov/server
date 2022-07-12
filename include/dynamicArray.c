#include <stdio.h>
#include "dynamicArray.h"

void append(charArray **array, char letterOfWord) {
    if (*array) {
        charArray *tmp = NULL;
        if((*array)->element) {
            tmp = (*array)->element;
            append(&tmp, letterOfWord);
            return;
        } else {
            tmp = (*array);
        }
        charArray *new = malloc(sizeof(charArray));
        new->letter = letterOfWord;
        new->element = NULL;
        tmp->element = new;
    } else {
        charArray *new = malloc(sizeof(charArray));
        new->letter = letterOfWord;
        new->element = NULL;
        *array = new;
    }
}