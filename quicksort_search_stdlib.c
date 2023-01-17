#include "key_value_pair.h"
#include "array_functions.h"
#include "node.h"
#include "linkedlist_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bsearch_function(char *search_input, struct key_value_pair *arr, int length, int std_int_comp()){
    char *endptr_string;
    long search_long = strtol(search_input, &endptr_string, 10);

    if (search_input == endptr_string) {
        printf(" number : %ld  invalid  (no digits found, 0 returned)\n", search_long);
    }

    if (search_long >= 32767 || search_long <= -32768) {
        printf("Sorry, but your input exceeds the range of keys\n");
    } else if (search_input != endptr_string) {

        qsort(arr, length, sizeof(struct key_value_pair), std_int_comp);
        struct key_value_pair *result = bsearch(&search_long, &arr[0], length, sizeof(struct key_value_pair),
                                                std_int_comp);
        if (result != NULL) {
            printf("Success! Your requested key %d has been found! The corresponding string value is: %s\n\n",
                   result->key, result->value);
        }

        else if(result == NULL) {
            printf("Your requested Key has not been found\n\n");
        }



    }



}


int std_string_comp(const void *left_s, const void *right_s) {
    const struct key_value_pair *left = (struct key_value_pair *) left_s;
    const struct key_value_pair *right = (struct key_value_pair *) right_s;
    return strcmp(left->value, right->value);
}


int std_int_comp(const void *left_i, const void *right_i) {
    const struct key_value_pair * left  = (struct key_value_pair *) left_i;
    const struct key_value_pair * right = (struct key_value_pair *) right_i;
    if( left->key < right->key ) return -1;
    if( left->key > right->key ) return 1;

    return 0;
}