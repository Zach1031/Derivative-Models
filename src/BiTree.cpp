#include <stdio.h>

#include "BiTree.h"


void BiTree::printTree(BiTree *root, int space)
{
    if (root == NULL)
        return;
 
    space += 10;
 
    printTree(root->up, space);
 
    // print proper spacing
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%.2f\n", root->val);
 
    printTree(root->down, space);
}