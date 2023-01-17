#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "key_value_pair.h"
#include "quicksort.h"
#include "array_functions.h"

int validate_sorted_array(int * array, int length, int ascending) {
    if (ascending) // if the array should be sorted in ascending order
        for (int i = 0; i < length - 1; i++) {
            if (array[i] > array[i + 1]) { // if the next element is smaller than the current element
                return 0; // the array is not sorted in ascending order and the function returns 0
            }
        }
    else
        for (int i = 0; i < length - 1; i++) { // if the array should be sorted in descending order
            if (array[i] < array[i + 1]) { // if the next element is bigger than the current element
                return 0; // the array is not sorted in descending order and the function returns 0
            }
        }
    return 1;
}

void print_array(int * array, int length) {
    int lineBreak = 0; // counter for linebreaks
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
        if (++lineBreak > 14) { // print 15 numbers per line
            printf("\n");
            lineBreak = 0; // reset the counter
        }
    }
    printf("\n");
}

void randomize_array(signed int * array, int length) {
    for (int i = 0; i < length; i++) {
        int randomint = rand()%32768; // generate a random number
        if (rand() % 2) //with 50% chance
        {
            randomint = randomint * -1; // make the number negative 
            randomint -= 1;
        }
        *(array + i) = randomint; // assign the random number to the array element
    }
}

void fill_array_ascening(signed int * array, int length) {
    for (int i = 0; i < length; i++)
        *
        (array + i) = -32768 + i; // fill the array with ascending numbers
}

void fill_array_descending(signed int * array, int length) {
    for (int i = 0; i < length; i++)
        *
        (array + i) = 32767 - i; // fill the array with descending numbers
}

int * copy_array(int * source_array, int length) {
    int * copy = malloc(sizeof(int) * length); // allocate memory for the array
    for (int i = 0; i < length; i++) // iterate through the array
    {
        *(copy + i) = * (source_array + i); // copy the array element
    }
    return copy; // return the copy
}

void copy_array_into_array(int * source_array, int * destination_array, int length) {
    for (int i = 0; i < length; i++) {
        destination_array[i] = source_array[i]; // copy the array element into the destination array
    }
}

int * randomized_array(int size) {
    int * arr = malloc(sizeof(int) * size); // allocate memory for the array
    for (int i = 0; i < size; i++) { // fill the array with random integer between -32768 and 32767
        int rnd = rand()%32768; // generate a random number max 32767
        if (rand() % 2 == 0) // if random number is even
            rnd = -1 * (rnd + 1); // make rnd negative and add+1 to allow -32768
        arr[i] = rnd;
    }
    return arr;
}

int test_sort_array(int * pArray, int size, int asc, int print, char type) {
    int * arrCopy = copy_array(pArray, size); // copy the array
    if (print) {
        printf("%cSort%i:\n", type, size);
        print_array(arrCopy, size); // print the array before sorting
    }
    switch (type) // sort the array with the given sorting algorithm
    {
    case 'b':
        bubble_sort_array(arrCopy, size, asc);
        break;
    case 'i':
        insertion_sort_array(arrCopy, size, asc);
        break;
    case 'm':
        merge_sort_array(arrCopy, size, asc);
        break;
    case 'q':
        quick_sort_array(arrCopy, size, asc);
    }
    int success = validate_sorted_array(arrCopy, size, asc); // check if the array is sorted
    if (print) {
        printf("V\n");
        print_array(arrCopy, size); // print the array after sorting
        if (success) // if the array is sorted
            printf("%cSort%i succeeded %s\n", type, size, asc ? "asc" : "desc");
        else
            printf("%cSort%i failed %s\n", type, size, asc ? "asc" : "desc");
    }
    free(arrCopy); // free the memory
    return success;
}

char *generate_random_string(int length) {
    char * str = malloc(sizeof(char) * (length + 1)); // allocate memory for the string
    for (int i = 0; i < length; i++) {
        int rnd = rand() % 62; // generate a random number between 0 and 61
        if (rnd < 10) // if the random number is between 0 and 9
            str[i] = rnd + 48; // add 48 to get the ASCII value for 0-9
        else if (rnd < 36) // if the random number is between 10 and 35
            str[i] = rnd + 55; // add 55 to get the ASCII value for A-Z
        else // if the random number is between 36 and 61
            str[i] = rnd + 61; // add 61 to get the ASCII value for a-z
    }
    str[length] = '\0'; // add the null terminator
    return str;
}

struct key_value_pair *generate_array_of_rand_key_value_pairs(int size) {
    int *rand_arr = randomized_array(size);
    struct key_value_pair *array = malloc(sizeof(struct key_value_pair) * size);
    for (int i = 0; i < size; i++) {
        array[i].key = rand_arr[i];
        array[i].value = generate_random_string(10);
    }
    free(rand_arr);
    return array;
}

struct key_value_pair *copy_array_of_key_value_pairs(struct key_value_pair *source_array, int length) {
    struct key_value_pair *arr = malloc(sizeof(struct key_value_pair) * length);
    for(int i = 0; i < length; i++)
        arr[i] = source_array[i];
    return arr;
}

void print_array_of_key_value_pairs(struct key_value_pair *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%i: %s\n", array[i].key, array[i].value);
    }
}

char *read_user_input() {
    char *input = malloc(sizeof(char) * 100); // allocate memory for the input
    int i = 0;
    char c;
    while ((c = getchar()) != '\n') // read the input until the user presses enter
    {
        input[i] = c;
        i++;
    }
    input[i] = '\0'; // add the null terminator
    return input;
}