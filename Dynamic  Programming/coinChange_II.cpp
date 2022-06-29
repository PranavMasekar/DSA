#include<bits/stdc++.h>
using namespace std;
int t[100][100];
int CoinChangeIIMemo(vector<int> Coin, int sum, int n)
{
    if (sum == 0) return 0;
    if (n == 0 && sum != 0) return INT_MAX - 1;
    if (t[n][sum] != -1) return t[n][sum];
    else
    {
        if (Coin[n - 1] <= sum) t[n][sum] = min((CoinChangeIIMemo(Coin, sum - Coin[n - 1], n) + 1 ), (CoinChangeIIMemo(Coin, sum, n - 1)));
        else t[n][sum] = CoinChangeIIMemo(Coin, sum, n - 1);
        return t[n][sum];
    }
}
int CoinChangeIIDP(vector<int> Coin, int sum, int n)
{
    int t[n + 1][sum + 1];
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
    // for(int j=1;j<sum+1;j++){
    //     if(j%Coin[0]==0) t[1][j] = j / Coin[0];
    //     else t[1][j] = INT_MAX - 1;
    // }

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

int main(){
    vector<int> Coin = {9,6,1,5};
    int n = 4;
    int sum = 11;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            t[i][j] = -1;
        }
    }
    cout<<CoinChangeIIMemo(Coin,sum,n)<<endl;
    cout<<CoinChangeIIDP(Coin, sum, n)<< endl;
    return 0;
}