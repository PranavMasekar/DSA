#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int low, int high, int val)
{
    if (high >= low)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == val)
            return mid;
        if (val > arr[mid])
        {
            return BinarySearch(arr, mid + 1, high, val);
        }
        else 
        {
            return BinarySearch(arr, low, mid - 1, val);
        }
    }
    
    return -1;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << BinarySearch(arr, 0, 4, 6);
    return 0;
}