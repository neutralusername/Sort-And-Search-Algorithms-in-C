#ifndef LINKEDLIST_FUNCTIONS_H
#define LINKEDLIST_FUNCTIONS_H
struct Node *linkedListFromArray(int *array, int length);
void printLinkedList(struct Node *head);
void freeLinkedList(struct Node *head);
#endif