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

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFUll(struct Node *ptr)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *ptr, int x)
{
    if (isFUll(ptr))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = x;
        p->next = ptr;
        ptr = p;
        return ptr;
    }
}
int pop(struct Node** ptr){
    if(isEmpty(*ptr)){
        printf("Stack Underflow");
    }
    else{
        struct Node * p = * ptr;
        *ptr = (* ptr)->next;
        int x = p->data;
        free(p);
        return x;

    }
}

int peek(struct Node *top,int pos){
    struct Node * ptr = top;
    for(int i=0 ; (i<pos-1 && ptr!=NULL);i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else{
        return 0;
    }
}
int main()
{
    struct Node *top;
    struct Node *second;
    struct Node *Third;

    //Creating memory in heap using malloc for Node.
    top = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));

    top->data = 7;
    top->next = second;

    second->data = 10;
    second->next = Third;

    Third->data = 56;
    Third->next = NULL;

    top = push(top, 99);
    // display(top);

    // int element = pop(&top);
    // printf("The element pop out from the stack is %d \n",element);
    // display(top);

    printf("The value at position 1 is %d",peek(top , 1));
    return 0;
}