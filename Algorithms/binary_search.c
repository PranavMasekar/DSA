// For Binary Search the array must be sorted.
#include<stdio.h>

int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;

    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 4, 8, 45, 78, 95};
    int size = sizeof(arr) / sizeof(int);
    int element = 5;
    int searchindex = binarysearch(arr, size, element);
    if (searchindex == -1)
    {
        printf("The searched element is not present in given array");
    }
    else
    {
        printf("The given element is present at %d", searchindex);
    }

    return 0;
}