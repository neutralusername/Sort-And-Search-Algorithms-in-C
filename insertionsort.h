#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
struct Node *insertionSortLinkedList(struct Node *head, int ascending);
struct Node *sortedInsert(struct Node *head, struct Node *insertionNode, int ascending);
void insertionSortArray(int *array, int length, int ascending);
#endif