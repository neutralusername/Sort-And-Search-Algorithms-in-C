#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
} node;

node *linked_list_from_array(int *arr, int len)
{
    node *head = malloc(sizeof(node));
    head->next = NULL;
    head->data = arr[0];

    node *tail = head;

    for (int i = 1; i < len; i++)
    {
        tail->next = malloc(sizeof(node));
        tail = tail->next;
        tail->next = NULL;
        tail->data = arr[i];
    }

    return head;
}

void print_linked_list(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void free_linked_list(node *head)
{
    node *next;
    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
}