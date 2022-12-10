#include "node.h"
#include <stdio.h>

struct Node *insertionSortLinkedList(struct Node *head, int ascending) {
    struct Node *sorted = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while(current != NULL) {
        next = current->next;
        if(sorted == NULL || (ascending && current->data <= sorted->data) || (!ascending && current->data >= sorted->data)) {
            current->next = sorted;
            sorted = current;
        }
        else {
            struct Node *temp = sorted;
            while((ascending && temp->next != NULL && temp->next->data < current->data) || (!ascending && temp->next != NULL && temp->next->data > current->data)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void insertionSortArray(int *input_array, int length, int ascending) {
    int i, j, temp; //declare variables. i and j are used for iteration, temp is used for swapping.
    for (i = 1; i < length; i++) { //iterate through the array
        temp = input_array[i]; //set the temp variable to the current element
        if(ascending) { //if the array should be sorted in ascending order
            for (j = i - 1; j >= 0 && input_array[j] > temp; j--) { //iterate through the array again in reverse order until the current element is smaller than the previous element
                input_array[j + 1] = input_array[j]; //swap the elements
            }
        }
        else for(j = i - 1; j >= 0 && input_array[j] < temp; j--) { 
            input_array[j + 1] = input_array[j];
        }
        input_array[j + 1] = temp;
    }
}