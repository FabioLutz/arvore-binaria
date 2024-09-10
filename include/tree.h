#ifndef TREE_H
#define TREE_H

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} Node;

void createNode(Node **node, int value);
void insertNode(Node **node, int value);

void inOrderTraversal(Node **node);
void preOrderTraversal(Node **node);
void postOrderTraversal(Node **node);

void inOrderSuccessor(Node **node);
void removeNode(Node **node, int value);

#endif // TREE_H