#include <bits/stdc++.h>
using namespace std;

bool t[100][100];
bool EqualSumPartitionMemo(vector<int> &arr, int sum, int n)
{
    if (sum == 0)
        return true;
    if(n==0) return false;
    if (sum < 0)
        return false;
    if (t[n-1][sum] != false)
        return t[n][sum];
    else
    {
        if (arr[n - 1] <= sum)
        {
            return t[n][sum] = EqualSumPartitionMemo(arr, sum - arr[n - 1], n - 1) || EqualSumPartitionMemo(arr, sum, n - 1);
        }
        else
        {
            return t[n][sum] = EqualSumPartitionMemo(arr, sum, n - 1);
        }
    }
}

bool EqualSumPartitionDP(vector<int> &arr, int sum, int n)
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
    return t[n][sum];
}

int main()
{
    vector<int> arr = {1,5,5,1};
    int sum = 0;
    int n = 4;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }  
    if(sum%2!=0){
        cout<<"Eqaul Sum Partition is not possible";
    }
    else{
    // DP approach
    cout<<EqualSumPartitionDP(arr,sum,n)<<endl;
    // Memoization approach
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            t[i][j] = false;
        }
    }
    cout << EqualSumPartitionMemo(arr, sum, n);
    }
    
    return 0;
}