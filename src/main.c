#include <stdio.h>

#include "tree.h"

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