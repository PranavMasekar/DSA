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
void selectionsort(int *arr, int n)
{
    printf("Running selection sort.......\n");
    int indexofmin;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexofmin])
            {
                indexofmin = j;
            }
        }
        swap(&arr[i], &arr[indexofmin]);
    }
}

int main()
{
    int arr[] = {12, 4, 84, 2, 10};
    int n = 5;
    display(arr, n);
    selectionsort(arr, n);
    display(arr, n);
    return 0;
}