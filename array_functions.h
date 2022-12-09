#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
int validateSortedArray(int *pArray, int size, int asc);
void printIntArray(int *pArray, int size);
int rand_array(signed int *array, int arraysize);
int asc_array(signed int *array, int arraysize);
int desc_array(signed int *array, int arraysize);
int copyArray(int *source_ar, int source_size, int *dest_ar);
#endif