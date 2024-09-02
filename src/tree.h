#ifndef TREE_H
#define TREE_H

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} Node;

Node *create(int value);
Node *insert(Node *node, int value);

#endif // TREE_H