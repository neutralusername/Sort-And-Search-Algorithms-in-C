#pragma once
#include "linked_list.c"

node *linked_list_from_array(int *arr, int len);

void print_linked_list(node *head);

void free_linked_list(node *head);