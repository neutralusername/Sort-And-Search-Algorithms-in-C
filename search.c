#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree_node.h"
#include "key_value_pair.h"

struct tree_node *balanced_BST(struct key_value_pair *array, int length) {
    if (length == 0) {
        return NULL;
    }
    struct tree_node *root = malloc(sizeof(struct tree_node));
    root->key = array[length / 2].key;
    root->value = array[length / 2].value;
    root->left = balanced_BST(array, length / 2);
    root->right = balanced_BST(array + length / 2 + 1, length - length / 2 - 1);
    return root;
}

int search_key(struct tree_node *root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->key == key) {
        return 1;
    }
    if (root->key > key) {
        return search_key(root->left, key);
    }
    return search_key(root->right, key);
}

int search_value(struct tree_node *root, char *value) {
    if (root == NULL) {
        return 0;
    }
    if (strcmp(root->value, value) == 0) {
        return 1;
    }
    return search_value(root->left, value) || search_value(root->right, value);
}

void free_tree(struct tree_node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}