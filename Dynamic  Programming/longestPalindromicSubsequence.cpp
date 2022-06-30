#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int LongestPalindromicSubsequenceRecursive(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    
    if(x[n-1]==y[m-1]) {
        return 1 + LongestPalindromicSubsequenceRecursive(x,y,n-1,m-1);
    }
    else{
        return max(LongestPalindromicSubsequenceRecursive(x,y,n,m-1),LongestPalindromicSubsequenceRecursive(x,y,n-1,m));
    }
} 
int LongestPalindromicSubsequenceMemo(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    if (t[n][m] != -1) return t[n][m];
    if(x[n-1]==y[m-1]) {
        return t[n][m] =  1 + LongestPalindromicSubsequenceMemo(x,y,n-1,m-1);
    }
    else{
        return t[n][m] =  max(LongestPalindromicSubsequenceMemo(x,y,n,m-1),LongestPalindromicSubsequenceMemo(x,y,n-1,m));
    }
}
int LongestPalindromicSubsequenceDP(string x,string y,int n,int m){
    int t[n + 1][m + 1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0) t[i][j] = 0;
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i-1]==y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    return t[n][m];
}

int main(){
    string x = "agbcba";
    string y = x;
    reverse(y.begin(),y.end());
    int n = 6;
    memset(t,-1,sizeof(t));
    cout<<LongestPalindromicSubsequenceMemo(x,y,n,n)<<endl;
    cout<<LongestPalindromicSubsequenceRecursive(x,y,n,n)<<endl;
    cout<<LongestPalindromicSubsequenceDP(x,y,n,n)<<endl;
    return 0;
}