#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct AvlTree
{
    int data;
    struct AvlTree *left;
    struct AvlTree *right;
    short height;
} AvlTree;

void createAvlTree(AvlTree **node, int value);

#endif