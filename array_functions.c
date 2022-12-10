#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int validateSortedArray(int *input_array, int length, int ascending)
{
    if (ascending) // if the array should be sorted in ascending order
        for (int i = 0; i < length - 1; i++)
        {
            if (input_array[i] > input_array[i + 1])
            {             // if the next element is smaller than the current element
                return 0; // the array is not sorted in ascending order and the function returns 0
            }
        }
    else
        for (int i = 0; i < length - 1; i++)
        { // if the array should be sorted in descending order
            if (input_array[i] < input_array[i + 1])
            {             // if the next element is bigger than the current element
                return 0; // the array is not sorted in descending order and the function returns 0
            }
        }
    return 1;
}

void printArray(int *input_array, int length)
{
    int lineBreak = 0; // counter for linebreaks
    for (int i = 0; i < length; i++)
    {
        printf("%d ", input_array[i]);
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

void copyArray(int *source_array, int *destination_array, int length)
{
    for (int i = 0; i < length; i++)
    {
        *(destination_array + i) = *(source_array + i);
    }
}