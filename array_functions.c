#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"

int validateSortedArray(int *array, int length, int ascending)
{
    if (ascending) // if the array should be sorted in ascending order
        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i + 1])
            {             // if the next element is smaller than the current element
                return 0; // the array is not sorted in ascending order and the function returns 0
            }
        }
    else
        for (int i = 0; i < length - 1; i++)
        { // if the array should be sorted in descending order
            if (array[i] < array[i + 1])
            {             // if the next element is bigger than the current element
                return 0; // the array is not sorted in descending order and the function returns 0
            }
        }
    return 1;
}

void printArray(int *array, int length)
{
    int lineBreak = 0; // counter for linebreaks
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
        if (++lineBreak > 14)
        { // print 15 numbers per line
            printf("\n");
            lineBreak = 0; // reset the counter
        }
    }
    printf("\n");
}

void randomizeArray(signed int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        int randomint = rand();
        if (rand() % 2)
        {
            randomint = randomint * -1;
            randomint -= 1;
        }
        *(array + i) = randomint;
    }
}

void fillArrayAscening(signed int *array, int length)
{
    for (int i = 0; i < length; i++)
        *(array + i) = -32768 + i;
}

void fillArrayDescending(signed int *array, int length)
{
    for (int i = 0; i < length; i++)
        *(array + i) = 32767 - i;
}

int *copyArray(int *source_array, int length)
{
    int *copy = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        *(copy + i) = *(source_array + i);
    }
    return copy;
}

int *randomizedArray(int size) {
    int *arr = malloc(sizeof(int) * size); //allocate memory for the array
    for(int i = 0; i < size; i++) { //fill the array with random integer between -32768 and 32767
        int rnd = rand(); //generate a random number max 32767
        if(rand() % 2 == 0) //if random number is even
            rnd = -1 * (rnd +1); //make rnd negative and add+1 to allow -32768
        arr[i] = rnd;  
    }
    return arr;
}

void applySortArray(int *pArray, int size, int asc, int print, char type) {
    int *arrCopy = copyArray(pArray, size); //copy the array
    if(print) {
        printf("%cSort%i:\n",type, size);
        printArray(arrCopy, size); //print the array before sorting
    }
    if(type == 'b')
        bubbleSortArray(arrCopy, size, asc);
    else if(type =='i')
        insertionSortArray(arrCopy, size, asc);
    else if(type == 'm')
        mergeSortArray(arrCopy, size, asc);
    else if(type == 'q')
        quickSortArray(arrCopy, size, asc);
    if(print) {
        printf("V\n");
        printArray(arrCopy, size); //print the array after sorting
        if(validateSortedArray(arrCopy, size, asc)) //check if the array is sorted
            printf("%cSort%i succeeded %s\n",type, size, asc?"asc":"desc");
        else printf("%cSort%i failed %s\n",type, size, asc?"asc":"desc");
    }
    free(arrCopy); //free the memory
}