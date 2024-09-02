#include <stdio.h>

#include "tree.h"

int main()
{
    int option;
    int value;

    Node *root = NULL;

    do
    {
        printf("\n1 - Adicionar valor\n2 - Imprimir árvore\n-1 - Sair\n");
        printf("\nDigite a opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nDigite o valor a ser adicionado: ");
            scanf("%d", &value);

            root = insertNode(root, value);
            break;
            
        case 2:
            printf("\n1 - In order\n2 - Pre-Order\n3 - Post-Order\n");
            printf("\nDigite a opção: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                inOrderTraversal(root);
                break;

            case 2:
                preOrderTraversal(root);
                break;

            case 3:
                postOrderTraversal(root);
                break;

            default:
                printf("\nValor inválido\n");
                break;
            }
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