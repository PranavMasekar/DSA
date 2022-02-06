#include <bits/stdc++.h>
using namespace std;

int PeakIndexInMountainArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            // Currently present in decreasing part of the array This can be our ans but there can be possible ans at left side.
            end = mid;
        }
        else
        {
            // Currently in ascending part of the array
            start = mid + 1;
        }
    }
    // In the end start , end , mid will point to same position in the array i.e will be the max element in array
    return arr[start];
}

int binarysearch(int arr[], int element, int low, int high)
{
    bool isAscending = arr[low] < arr[high];
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (isAscending)
        {
            if (element < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (element > arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return -1;
}

int searchInMountain(int arr[], int element, int size)
{
    int peak = PeakIndexInMountainArray(arr, size);
    int leftSearch = binarysearch(arr, element, 0, peak);
    if (leftSearch != -1)
    {
        return leftSearch;
    }
    return binarysearch(arr, element, peak + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 10, 8, 6, 2, 0};
    int size = 10;
    cout << searchInMountain(arr, 0, size) << endl;
    return 0;
}