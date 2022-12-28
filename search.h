#ifndef SEARCH_H
#define SEARCH_H
struct tree_node *balanced_BST(struct key_value_pair *array, int length);
int search_key(struct tree_node *root, int key);
int search_value(struct tree_node *root, char *value);
void free_tree(struct tree_node *root);
#endif
