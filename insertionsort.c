#include "node.h"
#include <stdio.h>

struct Node *sortedInsert(struct Node *head, struct Node *insertionNode, int ascending) //parameters: the current head of the list, the node to be inserted, and a boolean indicating whether the list should be sorted in ascending or descending order
{
    if (head == NULL || (ascending ? head->data >= insertionNode->data : head->data <= insertionNode->data)) {
        // if the list is empty or the node should be inserted at the beginning of the new list
        insertionNode->next = head; // set the next element of the node to be inserted to the current head of the list
        head = insertionNode; // set the head of the list to the node to be inserted
    } 
    else  // if the node should be inserted somewhere else in the list
    {
         struct Node *current = head; // set the current element to the head of the list
        while (current->next != NULL && (ascending ? current->next->data < insertionNode->data : current->next->data > insertionNode->data)) // iterate through the list until the next element is larger than the node to be inserted
        {
            current = current->next; // set the current element to the next element
        }
        insertionNode->next = current->next; // set the next element of the node to be inserted to the next element of the current element
        current->next = insertionNode; // set the next element of the current element to the node to be inserted
    }
    return head; // return the head of the list
}

struct Node *insertionSortLinkedList(struct Node *head, int ascending) 
{
    struct Node *result = NULL; // the result list is initially empty.
    struct Node *current = head; // the current element is the first element in the original list. 
    struct Node *next; // the next element is used to save the next element in the original list
    while (current != NULL)  // go over every element in the list
    {
        next = current->next; // save the next element
        result = sortedInsert(result, current, ascending); // insert the current element at the correct position. result is the new head of the new list.
        current = next; // set the current element to the next element
    }
    return result;
}


void insertionSortArray(int *array, int length, int ascending)
{
    int i, j, temp; // declare variables. i and j are used for iteration, temp is used for swapping.
    for (i = 1; i < length; i++)
    {                    // iterate through the array
        temp = array[i]; // set the temp variable to the current element
        if (ascending)
        { // if the array should be sorted in ascending order
            for (j = i - 1; j >= 0 && array[j] > temp; j--)
            {                            // iterate through the array again in reverse order until the current element is smaller than the previous element
                array[j + 1] = array[j]; // swap the elements
            }
        }
        else
            for (j = i - 1; j >= 0 && array[j] < temp; j--) 
            {
                array[j + 1] = array[j];
            }
        array[j + 1] = temp;
    }
}