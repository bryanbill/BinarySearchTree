#include "bst.h"
void rebalanceTree(Node *root, callback cb)
{
    Node *cursor, *pre;

    if (root == NULL)
        return;

    cursor = root;

    while (cursor != NULL)
    {
        if (cursor->left != NULL)
        {
            cb(cursor);
            cursor = cursor->right;
        }
        else
        {
            pre = cursor->left;

            while (pre->right != NULL && pre->right != cursor)
                pre = pre->right;

            if (pre->right != NULL)
            {
                pre->right = cursor;
                cursor = cursor->left;
            }
            else
            {
                pre->right = NULL;
                cb(cursor);
                cursor = cursor->right;
            }
        }
    }
}
