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
void inOrder(Node *node);
void preOrder(Node *node);
void postOrder(Node *node);

#endif // TREE_H