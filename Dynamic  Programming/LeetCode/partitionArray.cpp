#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, k;
    int rec(int i, vector<int> &arr, vector<int> &memo)
    {
        if (i == n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int length = 0, maximum = 0;

        for (int j = i; j < min(i + k, n); ++j)
        {
            ++length;
            maximum = max(arr[j], maximum);
            int sum = maximum * length + rec(j + 1, arr, memo);
            memo[i] = max(memo[i], sum);
        }
        return memo[i];
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int K)
    {
        n = arr.size(), k = K;
        vector<int> memo(n + 1, -1);
        return rec(0, arr, memo);
    }
};

int main()
{

    return 0;
}