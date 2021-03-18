# BinarySearchTree
Binary Search Tree implemented in C language. The algorithms contain some common functions such as insert, delete, rebalance, search e.t.c
## Methods Implemented
1. Initialize the Nodes
<pre>
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
</pre>

2. Insert New Nodes
<pre>
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
</pre>