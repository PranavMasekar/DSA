#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * p;
    p = (struct Node * ) malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;

}
int main(){
    // struct Node * p;
    // p = (struct Node * ) malloc(sizeof(struct Node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;

    // struct Node * p1;
    // p1 = (struct Node * ) malloc(sizeof(struct Node));
    // p1->data = 5;
    // p1->left = NULL;
    // p1->right = NULL;

    // struct Node * p2;
    // p2 = (struct Node * ) malloc(sizeof(struct Node));
    // p2->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;

    // p->left = p1;
    // p->right = p2;

    //WE ARE REPEATING THE SAME PROCESS AGAIN AND AGAIN


    struct Node * p = createNode(4);
    struct Node * p1 = createNode(8);
    struct Node * p2 = createNode(3);

    p->left = p1;
    p->right = p2;

    struct Node * q = createNode(12);
    struct Node * r = createNode(1);

    p1->right = q;
    p1->left = r;
    return 0;
}