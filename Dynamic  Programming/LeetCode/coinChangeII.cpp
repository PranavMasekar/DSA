#include<bits/stdc++.h>
using namespace std;

class Solution {
int CoinChangeIDP(vector<int> Coin, int sum, int n)
{
    int t[n + 5][sum + 5];
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
            if (Coin[i - 1] <= j)
            {
                t[i][j] = t[i][j - Coin[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}
public:
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
        int res = CoinChangeIDP(coins,amount,n);
        return res;
    }
};

int main(){
    
    return 0;
}