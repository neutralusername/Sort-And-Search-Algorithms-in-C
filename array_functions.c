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
        int randomint = rand(); // generate a random number
        if (rand() % 2) //with 50% chance
        {
            randomint = randomint * -1; // make the number negative 
            randomint -= 1; 
        }
        *(array + i) = randomint; // assign the random number to the array element
    }
}

void fillArrayAscening(signed int *array, int length) 
{
    for (int i = 0; i < length; i++)
        *(array + i) = -32768 + i; // fill the array with ascending numbers
}

void fillArrayDescending(signed int *array, int length)
{
    for (int i = 0; i < length; i++)
        *(array + i) = 32767 - i; // fill the array with descending numbers
}

int *copyArray(int *source_array, int length)
{
    int *copy = malloc(sizeof(int) * length); // allocate memory for the array
    for (int i = 0; i < length; i++) // iterate through the array
    {
        *(copy + i) = *(source_array + i); // copy the array element
    }
    return copy;   // return the copy
} 

void copyArrayIntoArray(int *source_array, int *destination_array, int length) 
{
    for (int i = 0; i < length; i++)
    {
        destination_array[i] = source_array[i]; // copy the array element into the destination array
    }
}

int *randomizedArray(int size)
{
    int *arr = malloc(sizeof(int) * size); // allocate memory for the array
    for (int i = 0; i < size; i++)
    {                             // fill the array with random integer between -32768 and 32767
        int rnd = rand();         // generate a random number max 32767
        if (rand() % 2 == 0)      // if random number is even
            rnd = -1 * (rnd + 1); // make rnd negative and add+1 to allow -32768
        arr[i] = rnd;
    }
    return arr;
}

int testSortArray(int *pArray, int size, int asc, int print, char type)
{
    int *arrCopy = copyArray(pArray, size); // copy the array
    if (print)
    {
        printf("%cSort%i:\n", type, size);
        printArray(arrCopy, size); // print the array before sorting
    }
    switch (type) // sort the array with the given sorting algorithm
    {
    case 'b':
        bubbleSortArray(arrCopy, size, asc);
        break;
    case 'i':
        insertionSortArray(arrCopy, size, asc);
        break;
    case 'm':
        mergeSortArray(arrCopy, size, asc);
        break;
    case 'q':
        quickSortArray(arrCopy, size, asc);
    }
    int success = validateSortedArray(arrCopy, size, asc); // check if the array is sorted
    if (print)
    {
        printf("V\n");
        printArray(arrCopy, size); // print the array after sorting
        if (success)               // if the array is sorted
            printf("%cSort%i succeeded %s\n", type, size, asc ? "asc" : "desc");
        else
            printf("%cSort%i failed %s\n", type, size, asc ? "asc" : "desc");
    }
    free(arrCopy); // free the memory
    return success;
}