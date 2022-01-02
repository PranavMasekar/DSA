#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int CountSubSetRecursive(vector<int> arr, int sum, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
        return 0;
    if (sum < 0)
        return 0;

    if (arr[n - 1] <= sum)
    {
        return CountSubSetRecursive(arr, sum - arr[n - 1], n - 1) + CountSubSetRecursive(arr, sum, n - 1);
    }
    else
    {
        return CountSubSetRecursive(arr, sum, n - 1);
    }
}
// Memoization solution
int t[100][100];
int CountSubSetMemo(vector<int> arr, int sum, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
        return 0;
    if (sum < 0)
        return 0;
    if (t[n - 1][sum] != -1)
        return t[n][sum];
    else
    {
        if (arr[n - 1] <= sum)
        {
            return CountSubSetRecursive(arr, sum - arr[n - 1], n - 1) + CountSubSetRecursive(arr, sum, n - 1);
        }
        else
        {
            return CountSubSetRecursive(arr, sum, n - 1);
        }
    }
}

// DP solution
int CountSubSetDP(vector<int> arr, int sum, int n)
{
    int t[n + 1][sum + 1];
    // Initialization
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= sum + 1; j++)
        {
            // Initialization of matrix
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    };
    // Approach
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int n = 6;
    int sum = 10;
    cout << CountSubSetRecursive(arr, sum, n) << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            t[i][j] = -1;
        }
    }
    cout << CountSubSetMemo(arr, sum, n) << endl;
    cout << CountSubSetDP(arr, sum, n) << endl;
    return 0;
}