#include <stdio.h>
#include "dynamicArray.h"
/* 

The incoming array is the head of the linkedlist.
We check if it is NULL. If yes, we will use recursion in order to access other nodes.
In both situations, we will link a new created node to the last item.

*/


// There is a problem in our code because it only works with three letters...
// If the word consists of 5 letters first two letters will be ok, third one will be overwritten by next letters.
// By correcting the implementation it will work properly

void append(charArray **array, char letterOfWord) {
    if(*array) {
        charArray* tmp;
        if((*array)->element) {
            tmp = (*array)->element;
        } else {
            tmp = (*array);
        }
        charArray *new = malloc(sizeof(charArray));
        new->letter = letterOfWord;
        new->element = NULL;
        (tmp)->element = new;
    } else {
        charArray *new = malloc(sizeof(charArray));
        new->letter = letterOfWord;
        new->element = NULL;
        *array = new;        
    }    
}