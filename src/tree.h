#ifndef TREE_H
#define TREE_H

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} Node;

Node *createNode(int value);
Node *insertNode(Node *node, int value);
void inOrderTraversal(Node *node);
void preOrderTraversal(Node *node);
void postOrderTraversal(Node *node);

#endif // TREE_H