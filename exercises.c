#include "exercises.h"
#include "array_functions.h"
#include "linkedlist_functions.h"
#include "insertionsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void execute_11() {
    printf("implementation 1");
}
void execute_12() {
    printf("implementation 2");
}
void execute_13() {
    printf("implementation 3");
}
void execute_14() {
    clock_t begin = clock(); //start timer
    int *rndArr2048 = malloc(2048 * sizeof(int)); //create array
    rand_array(rndArr2048,2048); 
    clock_t end = clock(); //stop timer
    clock_t begin2 = clock(); //start timer
    struct Node *rndHead2048 = linked_list_from_array(rndArr2048, 2048); //create linked list
    clock_t end2 = clock(); //stop timer

    printf("array sort:\n");
    printIntArray(rndArr2048, 2048); //print the array
    clock_t begin3 = clock(); //start timer
    insertionSortArray(rndArr2048, 2048, 1);
    clock_t end3 = clock(); //stop timer
    printf("V\n");
    printIntArray(rndArr2048, 2048); //print the linked list

    printf("linked list sort:\n");
    print_linked_list(rndHead2048); //print the linked list
    clock_t begin4 = clock(); //start timer
    rndHead2048 = insertionSortLinkedList(rndHead2048, 1); //sort the linked list
    clock_t end4 = clock(); //stop timer
    printf("\nV\n");
    print_linked_list(rndHead2048); //print the linked list

    printf("\ntime to generate array:\t\t%fms\n", (double)(end - begin)/ CLOCKS_PER_SEC*1000); //print the time it took to generate the array
    printf("time to create linked list:\t%fms\n", (double)(end2 - begin2)/ CLOCKS_PER_SEC*1000); //print the time it took to create the linked list
    printf("time to sort array:\t\t%fms\n", (double)(end3 - begin3)/ CLOCKS_PER_SEC*1000); //print the time it took to sort the array
    printf("time to sort linked list:\t%fms\n", (double)(end4 - begin4)/ CLOCKS_PER_SEC*1000); //print the time it took to sort the linked list

    free_linked_list(rndHead2048); //free the linked list
}