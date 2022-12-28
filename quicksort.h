#ifndef QUICKSORT_H
#define QUICKSORT_H
void quick_sort_key(struct key_value_pair * array, int length);
void quick_sort_value(struct key_value_pair * array, int length);
void quick_sort_array(int *array, int length, int ascending);
#endif