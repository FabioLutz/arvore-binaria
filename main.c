#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} Node;

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

int main()
{
    int option;
    int value;

    Node *root = NULL;

    do
    {
        printf("\n1 - Adicionar valor\n(-1) - sair\n");
        printf("\nDigite a opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nDigite o valor a ser adicionado: ");
            scanf("%d", &value);

            root = insert(root, value);
            break;

        case -1:
            printf("\nEncerrando...\n\n");
            return 0;

        default:
            printf("\nValor inválido\n");
            break;
        }

    } while (option >= 0);

    printf("\n\n\tErro!\n\n");
    return 0;
}