#include <bits/stdc++.h>
using namespace std;
int T[100][100];

int knapsackRecursive(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsackRecursive(wt, val, W - wt[n - 1], n - 1), knapsackRecursive(wt, val, W, n - 1));
    }
    else
    {
        return knapsackRecursive(wt, val, W, n - 1);
    }
}

int knapsackMemoization(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (T[n][W] != -1)
        return T[n][W];
    else
    {
        if (wt[n - 1] <= W)
        {
            return T[n][W] = max(val[n - 1] + knapsackMemoization(wt, val, W - wt[n - 1], n - 1), knapsackMemoization(wt, val, W, n - 1));
        }
        else
        {
            return T[n][W] = knapsackMemoization(wt, val, W, n - 1);
        }
    }
}

int knapsackDP(int wt[], int val[], int W, int n){
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < W+1; j++)
        {
            // Initialization of matrix
            if(i==0 || j==0) T[i][j] = 0;
        }
    };
    // i represent length of the array and j represents the weitght of the knapsack.
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if (wt[i - 1] <= j){
                T[i][j] = max(val[i-1]+T[i-1][j-wt[i-1]],T[i-1][j]);
            }
            else{
                T[i][j] = T[i-1][j];
            }
        }
    }
    return T[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    // cout<<knapsackRecursive(wt,val,W,n);
    // for (int i = 0; i < n+1; i++)
    // {
    //     for (int j = 0; j < W+1; j++)
    //     {
    //         T[i][j] = -1;
    //     }
    // }
    // cout<<knapsackMemoization(wt,val,W,n);
    cout << knapsackDP(wt, val, W, n);
    return 0;
}