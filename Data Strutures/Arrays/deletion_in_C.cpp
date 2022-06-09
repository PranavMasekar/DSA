#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void DeletiontionSorted(int arr[], int size, int index)
{
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[10] = {1, 2, 5, 8};
    int size = 4;
    int index = 1;
    display(arr, size);
    DeletiontionSorted(arr, size, index);
    size--;
    display(arr, size);
    return 0;
}