#include <stdio.h>
#include "dynamicArray.h"



/* 


The incoming array is the head of the linkedlist.
We check if it is NULL. If yes, we will use recursion in order to access other nodes.
In both situations, we will link a new created node to the last item.

*/

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