#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int CountSubSetWithDifferenceRecursive(vector<int> arr, int sum, int n)
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
        return CountSubSetWithDifferenceRecursive(arr, sum - arr[n - 1], n - 1) + CountSubSetWithDifferenceRecursive(arr, sum, n - 1);
    }
    else
    {
        return CountSubSetWithDifferenceRecursive(arr, sum, n - 1);
    }
}
// Memoization solution
int t[100][100];
int CountSubSetWithDifferenceMemo(vector<int> arr, int sum, int n)
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
            return CountSubSetWithDifferenceRecursive(arr, sum - arr[n - 1], n - 1) + CountSubSetWithDifferenceRecursive(arr, sum, n - 1);
        }
        else
        {
            return CountSubSetWithDifferenceRecursive(arr, sum, n - 1);
        }
    }
}

// DP solution
int CountSubSetWithDifferenceDP(vector<int> arr, int sum, int n)
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
    vector<int> arr = {1,1,2,3};
    int n = 4;
    int sum = 7;
    int difference = 1;
    int val = (difference + sum) / 2;
    cout << CountSubSetWithDifferenceRecursive(arr, val, n) << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < val + 1; j++)
        {
            t[i][j] = -1;
        }
    }
    cout << CountSubSetWithDifferenceMemo(arr, val, n) << endl;
    cout << CountSubSetWithDifferenceDP(arr, val, n) << endl;
    return 0;
}