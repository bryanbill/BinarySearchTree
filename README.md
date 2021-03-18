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

3. Delete a Node
<pre>
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
</pre>

4. Search for a key in the Nodes
<pre>

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

</pre>

5. Free Nodes
<pre>
void freeNodes(Node *root)
{
    if (root != NULL)
    {
        free(root);
    }
}
</pre>

## Makefile

### all: Build the app and install
<code>
    make all
</code>
 
 ### clean:clean the build directory and remove all generated objects and libraries
<code>
    make clean
</code>

## The Makefile
<pre>
CC_VERBOSE = $(CC)
CC_NO_VERBOSE = @echo "Building $@..."; $(CC)
DESTDIR?=/usr/lib

ifeq ($(VERBOSE),YES)
  V_CC = $(CC_VERBOSE)
  AT := 
else
  V_CC = $(CC_NO_VERBOSE)
  AT := @
endif

C_FILES = $(wildcard *.c bin/*.c)
O_FILES = $(C_FILES:src/%.c=build/objects/%.o)

.PHONY: all clean
.DEFAULT: all

all: main

main: $(O_FILES)
	$(V_CC) -I../include/ -o $@ $^

build:
	$(AT)mkdir -p ../build/objects
	$(AT)mkdir -p ../build/lib

build/%.o: src/%.c | build
	$(V_CC) -c $< -o $@
bin:
	gcc bin/main.c -o main
install: 
	mv ../build/lib ${DESTDIR}
clean:
	@echo Removing build directory
	$(AT)-rm -rf build
</pre>





