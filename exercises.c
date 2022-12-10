#include "array_functions.h"
#include "node.h"
#include "linkedlist_functions.h"

#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void execute_1_1()
{
    printf("implementation 1.1\n");
}

void execute_1_2()
{
    void (*init_funs[3])(int *array, int length) = {
        &randomizeArray,
        &fillArrayAscening,
        &fillArrayDescending};

    void (*sort_funs[4])(int *array, int length, int ascending) = {
        &bubbleSortArray,
        &insertionSortArray,
        &mergeSortArray,
        &quickSortArray};

    char *init_names[3] = {"rnd", "asc", "des"};
    char *sort_names[4] = {"bubblesort", "insertionsort", "mergesort", "quicksort"};
    int arr_sizes[7] = {8, 32, 128, 512, 2084, 8192, 32768};
    long times[4][21];

    printf("executing 1.2\n");

    for (int sort = 0; sort < 4; sort++)
    {
        printf("- %s\t", sort_names[sort]); // logging progress
        for (int f_init = 0; f_init < 3; f_init++)
        {
            printf(" ."); // logging progress
            for (int size = 0; size < 7; size++)
            {
                int len = arr_sizes[size];
                int *arr = malloc(sizeof(int) * len);
                init_funs[f_init](arr, len);

                clock_t begin = clock();
                sort_funs[sort](arr, len, 1);
                clock_t end = clock();

                times[sort][3 * size + f_init] = (end - begin) * 1000 / CLOCKS_PER_SEC;

                free(arr);
            }
        }
        printf(" done\n"); // logging progress
    }

    // printing results
    printf("\n\narray size\t");
    for (int size = 0; size < 7; size++)
        printf("%d\t\t\t", arr_sizes[size]);

    printf("\narray init\t");
    for (int init = 0; init < 3 * 7; init++)
        printf("%s\t", init_names[init % 3]);

    printf("\n");
    for (int i = 0; i < 23; i++)
        printf("--------");

    printf("\n");
    for (int sort = 0; sort < 4; sort++)
    {
        printf("%s\t", sort_names[sort]);
        for (int arr_conf = 0; arr_conf < 3 * 7; arr_conf++)
        {
            printf("%ldms\t", times[sort][arr_conf]);
        }
        printf("\n");
    }
}

void execute_1_3()
{
    long times[20];

    int ref_arr[2000];
    randomizeArray(ref_arr, 2000);

    for (int i = 0; i < 20; i++)
    {
        int arr[2000];
        copyArray(ref_arr, arr, 2000);

        clock_t begin = clock();
        bubbleSortArray(arr, 2000, 1);
        clock_t end = clock();

        times[i] = (end - begin) * 1000 / CLOCKS_PER_SEC;
    }

    // printing results
    for (int i = 0; i < 20; i++)
        printf("[%d]\t%ldms\n", i, times[i]);
}

void execute_1_4()
{
    clock_t begin1 = clock();                     // start timer
    int *rndArr2048 = malloc(2048 * sizeof(int)); // create array
    randomizeArray(rndArr2048, 2048);
    clock_t end1 = clock();                                           // stop timer
    clock_t begin2 = clock();                                         // start timer
    struct Node *rndHead2048 = linkedListFromArray(rndArr2048, 2048); // create linked list
    clock_t end2 = clock();                                           // stop timer

    printf("array sort:\n");
    printArray(rndArr2048, 2048); // print the array
    clock_t begin3 = clock();     // start timer
    insertionSortArray(rndArr2048, 2048, 1);
    clock_t end3 = clock(); // stop timer
    printf("V\n");
    printArray(rndArr2048, 2048); // print the linked list

    printf("linked list sort:\n");
    printLinkedList(rndHead2048);                          // print the linked list
    clock_t begin4 = clock();                              // start timer
    rndHead2048 = insertionSortLinkedList(rndHead2048, 1); // sort the linked list
    clock_t end4 = clock();                                // stop timer
    printf("\nV\n");
    printLinkedList(rndHead2048); // print the linked list

    printf("\n\ntime to generate array:\t\t%f ms\n", (double)(end1 - begin1) / CLOCKS_PER_SEC * 1000); // print the time it took to generate the array
    printf("time to create linked list:\t%f ms\n", (double)(end2 - begin2) / CLOCKS_PER_SEC * 1000);   // print the time it took to create the linked list
    printf("time to sort array:\t\t%f ms\n", (double)(end3 - begin3) / CLOCKS_PER_SEC * 1000);         // print the time it took to sort the array
    printf("time to sort linked list:\t%f ms\n", (double)(end4 - begin4) / CLOCKS_PER_SEC * 1000);     // print the time it took to sort the linked list

    freeLinkedList(rndHead2048); // free the linked list
    free(rndArr2048);            // free the array
}