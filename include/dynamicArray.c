#include <stdio.h>
// This data structure is written in order to store string and the size will not be decleared beforehand


typedef struct charArray {
    char letter;
    struct charArray *element;
} charArray;



int append(charArray *array, char letterOfWord) {
    if (array != NULL) {
        printf("letters %c\n", array->letter);
        append(array->element, letterOfWord);
    }
    charArray *new = NULL;
    new = malloc(sizeof(charArray));
    new->letter = letterOfWord;
    new->element = NULL;
    array = new;
    return 1;
}

void printTheArray(charArray *array) {
    printf("The method is \n");
    if (array != NULL) {
        printf("%c\n", array->letter);
        printTheArray(array->element);
    }
    printf("\n");
}