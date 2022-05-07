#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int c = ptr->top - i + 1;
    if (c < 0)
    {
        printf("Invalid position");
        return -1;
    }
    else
    {
        return ptr->arr[c];
    }
}

int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack *ptr)
{
    return ptr->arr[0];
}
int main()
{
    //Creating a structure instance in heap memory and assigning a pointer to it.
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 57);
    push(s, 22);
    push(s, 54);
    push(s, 89);
    // printf("%d \n",isEmpty(s));
    // printf("%d \n",isFull(s));

    // printf("The value poped from the stack is %d \n",pop(s));
    // printf("The value poped from the stack is %d \n",pop(s));

    // for (int j = 1; j <= s->top + 1; j++)
    // {
    //     printf("The value at position %d is %d \n", j, peek(s, j));
    // }

    printf("The element at top is %d and element at bottom is %d", stacktop(s), stackbottom(s));
    return 0;
}