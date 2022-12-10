#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
int validateSortedArray(int *input_array, int length, int ascending);
void printArray(int *input_array, int length);
void randomizeArray(signed int *array, int length);
void fillArrayAscening(signed int *array, int length);
void fillArrayDescending(signed int *array, int length);
void copyArray(int *source_array, int *destination_array, int length);
#endif