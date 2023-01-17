#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist_functions.h"

struct Node * linked_list_from_array(int * array, int length) {
    struct Node * head = malloc(sizeof(struct Node));
    head -> next = NULL;
    head -> data = array[0];

    struct Node * tail = head;

    for (int i = 1; i < length; i++) {
        tail -> next = malloc(sizeof(struct Node));
        tail = tail -> next;
        tail -> next = NULL;
        tail -> data = array[i];
    }

    return head;
}

void print_linked_list(struct Node * head) {
    int lineBreak = 0; // counter for linebreaks
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;

        if (++lineBreak > 14) { // print 15 numbers per line
            printf("\n");
            lineBreak = 0; // reset the counter
        }
    }
    printf("\n");
}

void free_linked_list(struct Node * head) {
    struct Node * next;
    while (head != NULL) {
        next = head -> next;
        free(head);
        head = next;
    }
}