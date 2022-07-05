#include <stdio.h>
// This data structure is written in order to store string and the size will not be decleared beforehand


typedef struct charArray {
    char letter;
    struct charArray *element;
} charArray;


int append(charArray *array, char letterOfWord) {

    charArray checker = {.letter = '_', .element = NULL};
    if (array -> element -> letter != checker.letter && array -> element -> element != checker.element) {
        array = array -> element;
        append(array -> element, letterOfWord);
    }

    *(array -> element) = (charArray){.letter = letterOfWord, .element = NULL};

    return 1; 
}

void printTheArray(charArray *array) {
    
    charArray checker = {.letter = '_', .element = NULL};

    if (array -> element -> letter != checker.letter && array -> element -> element != checker.element) {
        printf("%c", array -> letter);
        printTheArray(array -> element);
    }

}