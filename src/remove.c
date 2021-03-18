#include "bst.h"

Node *removeItem(Node *root, int data, comparer compare)
{
    if (root == NULL)
        return NULL;

    Node *cursor;
    int r = compare(data, root->data);
    if (r < 0)
        root->left = removeItem(root->left, data, compare);
    else if (r > 0)
        root->right = removeItem(root->right, data, compare);
    else
    {
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        else //2 children
        {
            cursor = root->right;
            Node *parent = NULL;

            while (cursor->left != NULL)
            {
                parent = cursor;
                cursor = cursor->left;
            }
            root->data = cursor->data;
            if (parent != NULL)
                parent->left = removeItem(parent->left, parent->left->data, compare);
            else
                root->right = removeItem(root->right, root->right->data, compare);
        }
    }
    return root;
}