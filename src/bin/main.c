#include <bst.h>

#define SIZE 9

void display(Node *nd)
{
    if (nd != NULL)
        printf("%d ", nd->data);
}
int compare(int left, int right)
{
    if (left > right)
        return 1;
    if (left < right)
        return -1;
    return 0;
}

int main()
{
    Node *root = NULL;
    comparer int_comp = compare;
    callback f = display;

    /* insert data into the tree */
    int a[SIZE] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int i;

    printf("Insert: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
        root = insertItem(root, int_comp, a[i]);
    }
    printf(" into the tree.\n\n");

    /* display the tree */
    printTree(root);

    /* remove element */
    int r;
    do
    {
        printf("Enter data to remove, (-1 to exit):");
        scanf("%d", &r);
        if (r == -1)
            break;
        root = removeItem(root, r, int_comp);
        /* display the tree */
        if (root != NULL)
            printTree(root);
        else
            break;
    } while (root != NULL);

    /* search for a Node */
    int key = 0;
    Node *s;
    while (key != -1)
    {
        printf("Enter data to search (-1 to exit):");
        scanf("%d", &key);

        s = findItem(root, key, int_comp);
        if (s != NULL)
        {
            printf("Found it %d", s->data);
            if (s->left != NULL)
                printf("(L: %d)", s->left->data);
            if (s->right != NULL)
                printf("(R: %d)", s->right->data);
            printf("\n");
        }
        else
        {
            printf("Node %d not found\n", key);
        }
    }

    return 0;
}
