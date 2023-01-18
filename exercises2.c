#include "key_value_pair.h"
#include "array_functions.h"
#include "linkedlist_functions.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree_node.h"
#include "search.h"	
#include <string.h>	
#include "quicksort_search_stdlib.h"
#include "exercises2.h"


void execute_2_1(){
    int length = 400;
    struct key_value_pair *arr = generate_array_of_rand_key_value_pairs(length);
    char *userInput;
    do {
        printf("sort by key or value? (k/v) (q to quit): ");
        userInput = read_user_input();
        if(strcmp(userInput, "k") == 0) {
            quick_sort_key(arr, length);
            break;
        }
        else if(strcmp(userInput, "v") == 0) {
            quick_sort_value(arr, length);
            break;
        }   
        else if(strcmp(userInput, "q") == 0) {
            free(userInput);
            for (int i = 0; i < length; i++) {
                free(arr[i].value);
            }
            free(arr);
            exit(0);
        }
        free(userInput);
    } while(1);
    print_array_of_key_value_pairs(arr, length);
    printf ("\n");
    struct tree_node *root = generate_BST(arr, length);
    char *userInput2;
    do {
        printf("enter %s to search for (q to quit): ", strcmp(userInput, "k") ? "value" : "key");
        userInput2 = read_user_input();
        if(strcmp(userInput2, "q") == 0) {
            free(userInput);
            free(userInput2);
            for (int i = 0; i < length; i++) {
                free(arr[i].value);
            }
            free(arr);
            free_tree(root);
            exit(0);
        }
        else if(strcmp(userInput, "k") == 0) {
            printf("%s\n", tree_search_key(root, strtod(userInput2, NULL)) ? "found" : "not found");
        }
        else {
            printf("%s\n", tree_search_value(root, userInput2) ? "found" : "not found");
        }
        free(userInput2);
    } while(1);
}

void execute_2_2(){
    int length = 400;
    struct key_value_pair *arr = generate_array_of_rand_key_value_pairs(length);
    arr[20].key= 4000;
    char *input;
    int search_mode=0;
    while (1) {
        if (search_mode == 0){
            print_array_of_key_value_pairs(arr, length);
            printf("\n\tSort By Key, enter [k/K]\n\tSort by value, enter [v/V]\n\tsearch for a key, enter [s/S]\n\tto quit, enter [q/Q]\n\nPress Enter to confirm ");
        }
        else {
           printf("\n\tSearch for Key, enter Integer\n\tend search, enter [s/S]\n\tto quit, enter [q/Q]\n\nPress Enter to confirm ");
        }
        input = read_user_input();
        if(input[0] == 'q' || input[0] == 'Q') {
            free(input);
            for (int i = 0; i < length; i++) {
                free(arr[i].value);
            }
            free(arr);
            exit(0);
        }
        if(input[0] == 's' || input[0] == 'S') {
            search_mode = !search_mode;
            free(input);
            continue;
        }
        if(search_mode == 0) {
            if (input[0] == 'k' || input[0] == 'K') {
                qsort(arr, length, sizeof(struct key_value_pair), std_int_comp);
                free(input);
                continue;
            }
            else if (input[0] == 'v' || input[0] == 'V') {
                qsort(arr, length, sizeof(struct key_value_pair), std_string_comp);
                free(input);
                continue;
            }
            else {
                printf("Invalid input, please try again\n");
                free(input);
                continue;
            }
        }
        else {
            bsearch_function(input, arr, length, std_int_comp);
            free(input);
            continue;
        }
    }
}

int cmp_key_value_pairs(const void *a, const void *b) {
    struct key_value_pair *kva = (struct key_value_pair*)a;
    struct key_value_pair *kvb = (struct key_value_pair*)b;

    return kva < kvb ? -1 : kva > kvb ? 1 : 0;
}
void execute_2_3(){
    int array_len = 30000;
    int searches = 500;

    int *search_keys = randomized_array(searches);
    struct key_value_pair *arr0 = generate_array_of_rand_key_value_pairs(array_len);
    struct key_value_pair *arr1 = copy_array_of_key_value_pairs(arr0, array_len);

    // timing our implementations
    clock_t begin0 = clock();   // starting timer
    quick_sort_key(arr0, array_len);
    struct tree_node *bst = generate_BST(arr0, array_len);
    for(int i = 0; i < searches; i++)
        tree_search_key(bst, search_keys[i]);
    long time0 = (clock() - begin0) * 1000 / CLOCKS_PER_SEC;    // saving time in ms
    
    // timing stdlib implementations
    clock_t begin1 = clock();   // starting timer
    qsort(arr1, (size_t)array_len, sizeof(struct key_value_pair), *cmp_key_value_pairs);
    for(int i = 0; i < searches; i++)
        bsearch(&search_keys[i], arr1, (size_t)array_len, sizeof(struct key_value_pair), *cmp_key_value_pairs);
    long time1 = (clock() - begin1) * 1000 / CLOCKS_PER_SEC;    // saving time in ms

    
    // freeing memory
    for(int i = 0; i < array_len; i++)
        free(arr1[i].value);
    free(arr0);
    free(arr1);
    free_tree(bst);
    free(search_keys);

    // printing results
    printf("Time of our impementations:    %ld ms\n", time0);
    printf("Time of stdlib impementations: %ld ms\n", time1);
}