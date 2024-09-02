#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node *create(int value)
{
    struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *node, int value)
{
    if (node == NULL)
    {
        return create(value);
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }

    return node;
}

void inOrder(Node *node)
{
    if (node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    if (node->left != NULL)
    {
        inOrder(node->left);
    }

    printf("%d\n", node->data);

    if (node->right != NULL)
    {
        inOrder(node->right);
    }
}

void preOrder(Node *node)
{
    if (node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    printf("%d\n", node->data);

    if (node->left != NULL)
    {
        preOrder(node->left);
    }

    if (node->right != NULL)
    {
        preOrder(node->right);
    }
}

void postOrder(Node *node)
{
    if (node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }
    
    if (node->left != NULL)
    {
        postOrder(node->left);
    }

    if (node->right != NULL)
    {
        postOrder(node->right);
    }

    printf("%d\n", node->data);
}
