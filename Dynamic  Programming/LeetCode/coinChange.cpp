#include<bits/stdc++.h>
using namespace std;

class Solution {
    int CoinChangeIIDP(vector<int> Coin, int sum, int n)
    {
        int t[n + 5][sum + 5];
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= sum + 1; j++)
            {
                if (j == 0)
                    t[i][j] = 0;
                if (i == 0)
                    t[i][j] = INT_MAX-1;
            }
        };

        // Second Row Initialization
        for(int j=1;j<sum+1;j++){
            if(j%Coin[0]==0) t[1][j] = j / Coin[0];
            else t[1][j] = INT_MAX - 1;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (Coin[i - 1] <= j)
                {
                    t[i][j] = min(t[i][j - Coin[i - 1]] + 1 , t[i - 1][j]);
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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size()-1;
        int res = CoinChangeIIDP(coins,amount,n);
        if(res==INT_MAX-1) return -1;
        else return res;
    }
};

int main(){
    
    return 0;
}