#pragma once

struct Node;

struct Node *linked_list_from_array(int *arr, int len);

void print_linked_list(struct Node *head);

void free_linked_list(struct Node *head);