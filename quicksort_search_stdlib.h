#ifndef TIPROJEKT_QUICKSORT_SEARCH_STDLIB_H
#define TIPROJEKT_QUICKSORT_SEARCH_STDLIB_H
int std_string_comp(const void *left_s, const void *right_s);
int std_int_comp(const void *left_i, const void *right_i);
void bsearch_function(char *search_input, struct key_value_pair *arr, int length, int std_int_comp());
#endif //TIPROJEKT_QUICKSORT_SEARCH_STDLIB_H