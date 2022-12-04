#include <stdio.h>
#include "node.c"
int main()
{
    printf("Hello World");
    return 0;
}

int validateSortedArray(int *pArray, int size, int asc) {
    if(asc)  //if the array should be sorted in ascending order
        for(int i = 0; i < size - 1; i++) {
            if(pArray[i] > pArray[i + 1]) { //if the next element is smaller than the current element
                return 0; //the array is not sorted in ascending order and the function returns 0
            }
        }
    else for(int i = 0; i < size - 1; i++) { //if the array should be sorted in descending order
        if(pArray[i] < pArray[i + 1]) { //if the next element is bigger than the current element
            return 0; //the array is not sorted in descending order and the function returns 0
        }
    }
    return 1;
}

void printIntArray(int *pArray, int size) {
    int lineBreak = 0; //counter for linebreaks
    for(int i = 0; i < size; i++) {
        printf("%d ", pArray[i]);
        if(++lineBreak > 14) { //print 15 numbers per line
            printf("\n");
            lineBreak = 0; //reset the counter
        }
    }
    printf("\n");
}

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

void bubbleSortArray(int *input, int size, int asc) {
    //simple bubble sort implementation
    int i, j, temp; //declare variables. i and j are used for iteration, temp is used for swapping.
    for(i = 0; i < size; i++) { //iterate through the array
        for(j = 0; j < size - 1; j++) { //iterate through the array again(O(n^2))
            if(asc) { //if the array should be sorted in ascending order
                if(input[j] > input[j + 1]) { //if the current element is bigger than the next element
                    temp = input[j]; //swap the elements
                    input[j] = input[j + 1]; 
                    input[j + 1] = temp;
                }
            }
            else {
                if(input[j] < input[j + 1]) {
                    temp = input[j];
                    input[j] = input[j + 1];
                    input[j + 1] = temp;
                }
            }
        }
    }
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