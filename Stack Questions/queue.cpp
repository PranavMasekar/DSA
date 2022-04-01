#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} STACK;
class MyQueue
{
public:
    STACK *top = NULL;
    MyQueue()
    {
    }

    void push(int x)
    {
        STACK *newNode = (STACK *)malloc(sizeof(STACK));
        newNode->data = x;
        if (empty())
        {
            newNode->next = NULL;
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop()
    {
        if (top->next == NULL)
        {
            int val = top->data;
            top = NULL;
            return val;
        }
        STACK *temp = top;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        int val = temp->next->data;
        temp->next = NULL;
        free(temp->next);
        return val;
    }

    int peek()
    {
        STACK *temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
};

int main()
{

    return 0;
}