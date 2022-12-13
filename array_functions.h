#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
int validate_sorted_array(int * array, int length, int ascending);
void print_array(int * array, int length);
int * randomized_array(int size);
void fill_array_ascening(signed int * array, int length);
void fill_array_descending(signed int * array, int length);
int * copy_array(int * source_array, int length);
void copy_array_into_array(int * source_array, int * destination_array, int length);
int test_sort_array(int * pArray, int size, int asc, int print, char type);
void randomize_array(signed int * array, int length);
#endif