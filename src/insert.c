#include "bst.h"
Node *insertItem(Node *root, comparer compare, int data)
{

    if (root == NULL)
    {
        root = initBinaryTree(data);
    }
    else
    {
        int is_left = 0;
        int r = 0;
        Node *cursor = root;
        Node *prev = NULL;

        while (cursor != NULL)
        {
            r = compare(data, cursor->data);
            prev = cursor;
            if (r < 0)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if (r > 0)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if (is_left)
            prev->left = initBinaryTree(data);
        else
            prev->right = initBinaryTree(data);
    }
    return root;
}
