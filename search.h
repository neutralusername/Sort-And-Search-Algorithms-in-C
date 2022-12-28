#ifndef SEARCH_H
#define SEARCH_H
struct tree_node *generate_BST(struct key_value_pair *array, int length);
int tree_search_key(struct tree_node *root, int key);
int tree_search_value(struct tree_node *root, char *value);
void free_tree(struct tree_node *root);
#endif
