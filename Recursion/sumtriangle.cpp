#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    if (n < 1)
    {
        return;
    }
    int temp[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        int p = arr[i] + arr[i + 1];
        temp[i] = p;
    }
    print(temp, n - 1);
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    print(arr, 5);
    return 0;
}