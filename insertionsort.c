#include "node.h"
#include <stdio.h>

struct Node *insertionSortLinkedList(struct Node *head, int asc) {
    struct Node *sorted = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while(current != NULL) {
        next = current->next;
        if(sorted == NULL || (asc && current->data <= sorted->data) || (!asc && current->data >= sorted->data)) {
            current->next = sorted;
            sorted = current;
        }
        else {
            struct Node *temp = sorted;
            while((asc && temp->next != NULL && temp->next->data < current->data) || (!asc && temp->next != NULL && temp->next->data > current->data)) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void insertionSortArray(int *input, int size, int asc) {
    int i, j, temp; //declare variables. i and j are used for iteration, temp is used for swapping.
    for (i = 1; i < size; i++) { //iterate through the array
        temp = input[i]; //set the temp variable to the current element
        if(asc) { //if the array should be sorted in ascending order
            for (j = i - 1; j >= 0 && input[j] > temp; j--) { //iterate through the array again in reverse order until the current element is smaller than the previous element
                input[j + 1] = input[j]; //swap the elements
            }
        }
        else for(j = i - 1; j >= 0 && input[j] < temp; j--) { 
            input[j + 1] = input[j];
        }
        input[j + 1] = temp;
    }
}