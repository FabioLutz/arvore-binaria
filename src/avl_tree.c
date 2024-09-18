#include <stdio.h>
#include <stdlib.h>

#include "avl_tree.h"

void createAvlTree(AvlTree **node, int value)
{
    *node = (struct AvlTree *)malloc(sizeof(struct AvlTree));
    (*node)->data = value;
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->height = 0;
}
