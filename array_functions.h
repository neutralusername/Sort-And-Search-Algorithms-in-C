#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
int validateSortedArray(int *array, int length, int ascending);
void printArray(int *array, int length);
int *randomizedArray(int size);
void fillArrayAscening(signed int *array, int length);
void fillArrayDescending(signed int *array, int length);
int *copyArray(int *source_array, int length);
void copyArrayIntoArray(int *source_array, int *destination_array, int length);
int testSortArray(int *pArray, int size, int asc, int print, char type);
void randomizeArray(signed int *array, int length);
#endif