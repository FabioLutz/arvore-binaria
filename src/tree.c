#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node *createNode(int value)
{
    struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *node, int value)
{
    if (node == NULL)
    {
        return createNode(value);
    }

    if (value < node->data)
    {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insertNode(node->right, value);
    }

    return node;
}

void inOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    if (node->left != NULL)
    {
        inOrderTraversal(node->left);
    }

    printf("%d\n", node->data);

    if (node->right != NULL)
    {
        inOrderTraversal(node->right);
    }
}

void preOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    printf("%d\n", node->data);

    if (node->left != NULL)
    {
        preOrderTraversal(node->left);
    }

    if (node->right != NULL)
    {
        preOrderTraversal(node->right);
    }
}

void postOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    if (node->left != NULL)
    {
        postOrderTraversal(node->left);
    }

    if (node->right != NULL)
    {
        postOrderTraversal(node->right);
    }

    printf("%d\n", node->data);
}
