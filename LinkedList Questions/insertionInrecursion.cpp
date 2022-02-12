#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *ptr)
{
    //Traversal of Linked List
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
}

void InsertionByRecursion(Node * node , int i , int val , Node * pre){

    if(i==0){
        struct Node  * temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = val;
        pre->next = temp;
        temp->next = node;
        return;
    }
    return InsertionByRecursion(node->next,--i,val,node);
}   

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    display(head);
    InsertionByRecursion(head,2,88,NULL);
    display(head);
    return 0;
}