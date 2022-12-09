#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct Node *linked_list_from_array(int *arr, int len)
{
    struct Node *head = malloc(sizeof(struct Node));
    head->next = NULL;
    head->data = arr[0];

    struct Node *tail = head;

    for (int i = 1; i < len; i++)
    {
        tail->next = malloc(sizeof(struct Node));
        tail = tail->next;
        tail->next = NULL;
        tail->data = arr[i];
    }

    return head;
}

void print_linked_list(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void free_linked_list(struct Node *head)
{
    struct Node *next;
    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
}