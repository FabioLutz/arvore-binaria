#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void createNode(Node **node, int value)
{
    *node = (struct Tree *) malloc (sizeof (struct Tree));
    (*node)->data = value;
    (*node)->left = NULL;
    (*node)->right = NULL;
}

void insertNode(Node **node, int value)
{
    if (*node == NULL)
    {
        createNode(&(*node), value);
        return;
    }

    if (value < (*node)->data)
    {
        insertNode(&((*node)->left), value);
    }
    else if (value > (*node)->data)
    {
        insertNode(&((*node)->right), value);
    }
}

void inOrderTraversal(Node **node)
{
    if (*node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    if ((*node)->left != NULL)
    {
        inOrderTraversal(&((*node)->left));
    }

    printf("%d\n", (*node)->data);

    if ((*node)->right != NULL)
    {
        inOrderTraversal(&((*node)->right));
    }
}

void preOrderTraversal(Node **node)
{
    if (*node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    printf("%d\n", (*node)->data);

    if ((*node)->left != NULL)
    {
        preOrderTraversal(&((*node)->left));
    }

    if ((*node)->right != NULL)
    {
        preOrderTraversal(&((*node)->right));
    }
}

void postOrderTraversal(Node **node)
{
    if (*node == NULL)
    {
        printf("\nNão há valores\n");
        return;
    }

    if ((*node)->left != NULL)
    {
        postOrderTraversal(&((*node)->left));
    }

    if ((*node)->right != NULL)
    {
        postOrderTraversal(&((*node)->right));
    }

    printf("%d\n", (*node)->data);
}

void inOrderSuccessor(Node **node)
{
    struct Tree *temp = (*node)->right;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    removeNode(&((*node)->right), temp->data);
    (*node)->data = temp->data;
}

void removeNode(Node **node, int value)
{
    if (*node == NULL)
    {
        printf("\nValor não encontrado\n");
        return;
    }

    if (value < (*node)->data)
    {
        removeNode(&((*node)->left), value);
        return;
    }

    if (value > (*node)->data)
    {
        removeNode(&((*node)->right), value);
        return;
    }

    // Não é nulo, nem maior, nem menor, então é o valor
    if ((*node)->left == NULL)
    {
        // Esquerda é nulo
        if ((*node)->right == NULL)
        {
            // Ambos são nulos
            *node = NULL;
        }
        // Direita tem valor
        else
        {
            (*node)->data = (*node)->right->data;
            (*node)->right = NULL;
        }
    }
    // Esquerda tem valor
    else
    {
        if ((*node)->right == NULL)
        {
            // Direita é nulo
            (*node)->data = (*node)->left->data;
            (*node)->left = NULL;
        }
        else
        {
            // Ambos tem valor
            inOrderSuccessor(&(*node));
        }
    }
}