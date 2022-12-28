#ifndef TREE_NODE_H
#define TREE_NODE_H
struct tree_node {
    int key;
    char *value;
    struct tree_node* left;
    struct tree_node* right;
};
#endif