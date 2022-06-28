#include <bits/stdc++.h>
using namespace std;

// Recursive
int MinSubSetDifferenceRecursive(vector<int> arr, int n, int s1, int sum){
    if (n == 0)
        return abs(sum - (2 * s1));
    return min(MinSubSetDifferenceRecursive(arr, n-1, s1 + arr[n - 1], sum), MinSubSetDifferenceRecursive(arr, n-1, s1, sum));
}

// Memoization
int t[100][100];
int MinSubSetDifferenceMemo(vector<int> arr, int n, int s1, int sum)
{
    if (n == 0)
        return abs(sum - (2 * s1));
    if (t[n][s1] != -1)
        return t[n][s1];
    else
    {
        return t[n][s1] = min(MinSubSetDifferenceMemo(arr, n-1, s1 + arr[n - 1], sum), MinSubSetDifferenceMemo(arr, n-1, s1, sum));
    }
}
// DP
int MinSubSetDifferenceDP(vector<int> &arr, int sum, int n)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= sum + 1; j++)
        {
            // Initialization of matrix
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    };
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < (sum + 1) / 2; i++)
    {
        if (t[n][i] == true)
            ans.push_back(i);
    }
    int minimum = INT_MAX;
    for (int i = 0; i < ans.size(); i++)
    {
        int temp = sum - (2 * ans[i]);
        minimum = min(minimum, temp);
    }
    return minimum;
}

int main()
{
    vector<int> arr = {1, 6, 11, 5};
    int sum = 23;
    int n = 4;
    // DP approach
    cout << MinSubSetDifferenceDP(arr, sum, n) << endl;
    // Memo approach
    memset(t, -1, sizeof(t));
    cout << MinSubSetDifferenceMemo(arr, n, 0, sum)<<endl;
    // Recursive approach
    cout << MinSubSetDifferenceRecursive(arr, n, 0, sum)<<endl;
    return 0;
}