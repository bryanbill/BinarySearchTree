#include <stdio.h>
#include <stdlib.h>
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BST
{
    Node tree_root;
    int depth;
    int item_size;
} BST;

typedef int (*comparer)(int, int);
typedef void (*callback)(Node *);

Node *initBinaryTree(int data);
Node *insertItem(Node *root, comparer compare, int data);
Node *findItem(Node *root, const int data, comparer compare);
Node *removeItem(Node *root, int data, comparer compare);
void rebalanceTree(Node *root, callback cb);
void printTree(Node *nd);
void freeNodes(Node *root);

#endif