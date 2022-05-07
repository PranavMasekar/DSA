#include <stdio.h>

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void bubblesort(int *arr, int n)
{
    int sorted = 0;

    for (int i = 0; i < n ; i++) //For number of passes
    {
        sorted = 1;
        for (int j = 0; j < n - 1 - i; j++) //For number of comparison
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                sorted = 0;
            }
        }
        if (sorted)
        { //Making bubble sort adaptive
            return;
        }
    }
}
int main()
{
    int arr[] = {12, 4, 84, 2, 10};
    int n = 5;
    display(arr, n);
    bubblesort(arr, n);
    display(arr, n);
    return 0;
}