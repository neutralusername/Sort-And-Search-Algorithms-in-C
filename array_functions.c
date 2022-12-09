#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int validateSortedArray(int *pArray, int size, int asc) {
    if(asc)  //if the array should be sorted in ascending order
        for(int i = 0; i < size - 1; i++) {
            if(pArray[i] > pArray[i + 1]) { //if the next element is smaller than the current element
                return 0; //the array is not sorted in ascending order and the function returns 0
            }
        }
    else for(int i = 0; i < size - 1; i++) { //if the array should be sorted in descending order
        if(pArray[i] < pArray[i + 1]) { //if the next element is bigger than the current element
            return 0; //the array is not sorted in descending order and the function returns 0
        }
    }
    return 1;
}

void printIntArray(int *pArray, int size) {
    int lineBreak = 0; //counter for linebreaks
    for(int i = 0; i < size; i++) {
        printf("%d ", pArray[i]);
        if(++lineBreak > 14) { //print 15 numbers per line
            printf("\n");
            lineBreak = 0; //reset the counter
        }
    }
    printf("\n");
}

int rand_array(signed int *array, int arraysize) { 
    time_t t;
    srand(time(0));
    for (int i = 0; i < arraysize; i++) {
        int randomint = rand();
        if(rand() % 2) {
            randomint = randomint * -1;
            randomint -= 1;
        }
        *(array + i) = randomint;
    }
    return 0;
}

int asc_array(signed int *array, int arraysize) {
    for(int i =0; i<arraysize; i++)
        *(array+i) = -32768+i;
    return 0;
}

int desc_array(signed int *array, int arraysize) {
    for(int i =0; i<arraysize; i++)
        *(array+i) = 32767-i;
    return 0;
}

int copyArray(int *source_ar, int source_size, int *dest_ar) {
    for(int i=0; i < source_size; i++) {
        *(dest_ar + i) = *(source_ar + i);
    }
    return 0;
}