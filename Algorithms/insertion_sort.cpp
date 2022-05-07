#include <stdio.h>

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    { //Loop for passes
        int key = arr[i];
        int j;
        j = i - 1;
        //Loop for each pass
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {12, 4, 84, 2, 10};
    int n = 5;
    display(arr, n);
    insertionsort(arr, n);
    display(arr, n);
    return 0;
}