#include <bits/stdc++.h>
using namespace std;

int mymin(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    return min(arr[n - 1], mymin(arr, n - 1));
}

int mymax(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    return max(arr[n - 1], mymax(arr, n - 1));
}

int main()
{
    int arr[7] = {1, 4, 3, -5, -4, 8, 6};
    cout << mymax(arr, 7) << endl;
    return 0;
}