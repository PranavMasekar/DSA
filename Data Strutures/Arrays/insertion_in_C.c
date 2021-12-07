#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    } 
    printf("\n");
}

int InsertionSorted(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int arr[10] = {1, 2, 5, 8};
    int size = 4;
    int element = 45, index = 3;
    display(arr, size);
    int x = InsertionSorted(arr, size, element, 10, index);
    size++;
    if (x == -1)
    {
        printf("Insertion Not possible");
    }
    else
    {
        display(arr, size);
    }

    return 0;
}