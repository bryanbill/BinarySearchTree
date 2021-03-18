#include "bst.h"
Node *findItem(Node *root, const int data, comparer compare)
{
    if (root == NULL)
        return NULL;

    int r;
    Node *cursor = root;
    while (cursor != NULL)
    {
        r = compare(data, cursor->data);
        if (r < 0)
            cursor = cursor->left;
        else if (r > 0)
            cursor = cursor->right;
        else
            return cursor;
    }
    return cursor;
}