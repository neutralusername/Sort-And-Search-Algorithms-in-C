#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
struct Node * insertion_sort_linked_list(struct Node * head, int ascending);
struct Node * sorted_insert(struct Node * head, struct Node * insertion_node, int ascending);
void insertion_sort_array(int * array, int length, int ascending);
#endif