#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubstringDP(string x,string y,int n,int m){
    int t[n + 1][m + 1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0) t[i][j] = 0;
        }
    }
    int ans = 0;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i-1]==y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = 0;
            }
            ans = max(ans,t[i][j]);
        }
    }
    return ans;
}

int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    int n = 6;
    int m = 7;
    cout<<LongestCommonSubstringDP(x,y,n,m)<<endl;
    return 0;
}