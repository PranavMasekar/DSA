
#include <stdio.h>
#include <stdlib.h>

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
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}
//Deleting first node from the linked list
struct Node *deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
//Deleting a node at particular index
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    //The q pointer should be present at the node which has to be deleted
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
//Deleting a node at last
struct Node *deletelast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
//Deleting a node having a given value
struct Node *deletenode(struct Node *head , int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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
    Third->next = NULL;

    display(head);

    printf("Linked list after deletion \n");
    // head = deletefirst(head);
    // display(head);

    // head  = deleteAtIndex(head , 2);
    // display(head);

    // head = deletelast(head);
    // display(head);

    head = deletenode(head , 5);
    display(head);

    return 0;
}