#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int isBST(struct Node *root)
{
    static struct Node *pre = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (pre != NULL && root->data <= pre->data)
        {
            return 0;
        }
        pre = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *Search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        Search(root->left, key);
    }
    else
    {
        Search(root->right, key);
    }
}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct Node *n = Search(p, 5);
    if (n != NULL)
        printf("%d", n->data);
    else
        printf("Element Not Found");
    return 0;
}