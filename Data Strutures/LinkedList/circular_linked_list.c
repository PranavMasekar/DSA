#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};
//Traversal in circular linked list
void Traversal(struct Node * head)
{
    struct Node *ptr = head;
   do{
       printf("Element is %d\n",ptr->data);
       ptr=ptr->next;
   }
   while(ptr!=head);
}
//Insertion at head node
struct Node * atfirst(struct Node * head , int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    //Moving the pointer p to last node
    while(ptr->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *Third;

    //Creating memory in heap using malloc for Node.
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 10;
    second->next = Third;

    Third->data = 56;
    Third->next = head;

    Traversal(head);
    head = atfirst(head,80);
    printf("After the insertion \n");
    Traversal(head);
    return 0;
}