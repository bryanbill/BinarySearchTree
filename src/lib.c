#include "bst.h"

Node *initBinaryTree(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void printTree(Node *nd)
{
    if (nd == NULL)
        return;
    /* display Node data */
    printf("%d", nd->data);
    if (nd->left != NULL)
        printf("(L:%d)", nd->left->data);
    if (nd->right != NULL)
        printf("(R:%d)", nd->right->data);
    printf("\n");

    printTree(nd->left);
    printTree(nd->right);
}

void freeNodes(Node *root)
{
    if (root != NULL)
    {
        free(root);
    }
}