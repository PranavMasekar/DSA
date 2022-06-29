#include <bits/stdc++.h>
using namespace std;
int T[100][100];

int RodCuttingRecursive(int length[], int prices[], int MaxLength, int n)
{
    if (n == 0 || MaxLength == 0)
        return 0;
    if (length[n - 1] <= MaxLength)
    {
        return max(prices[n - 1] + RodCuttingRecursive(length, prices, MaxLength - length[n - 1], n), RodCuttingRecursive(length, prices, MaxLength, n - 1));
    }
    else
    {
        return RodCuttingRecursive(length, prices, MaxLength, n - 1);
    }
}

int RodCuttingMemoization(int length[], int prices[], int MaxLength, int n)
{
    if (n == 0 || MaxLength == 0)
        return 0;
    if (T[n][MaxLength] != -1)
        return T[n][MaxLength];
    else
    {
        if (length[n - 1] <= MaxLength)
        {
            return T[n][MaxLength] = max(prices[n - 1] + RodCuttingMemoization(length, prices, MaxLength - length[n - 1], n), RodCuttingMemoization(length, prices, MaxLength, n - 1));
        }
        else
        {
            return T[n][MaxLength] = RodCuttingMemoization(length, prices, MaxLength, n - 1);
        }
    }
}

int RodCuttingDP(int length[], int prices[], int W, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                T[i][j] = 0;
        }
    };
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                T[i][j] = max(prices[i - 1] + T[i][j - length[i - 1]], T[i - 1][j]);
            }
            else
            {
                T[i][j] = T[i - 1][j];
            }
        }
    }
    return T[n][W];
}

int main()
{
    // Exactly Same as Unboundex Knapsack
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20 };
    int length[] = {1,2,3,4,5,6,7,8};
    int W = 8;
    int n = 8;
    cout << RodCuttingRecursive(length, prices, W, n) << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            T[i][j] = -1;
        }
    }
    cout << RodCuttingMemoization(length, prices, W, n) << endl;
    cout << RodCuttingDP(length, prices, W, n) << endl;
    return 0;
}