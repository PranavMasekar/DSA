#include<bits/stdc++.h>
using namespace std;

int t[100][100];
int LongestCommonSubsequenceMemo(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    if (t[n][m] != -1) return t[n][m];
    if(x[n]==y[m]) {
        return t[n][m] =  1 + LongestCommonSubsequenceMemo(x,y,n-1,m-1);
    }
    else{
        return t[n][m] =  max(LongestCommonSubsequenceMemo(x,y,n,m-1),LongestCommonSubsequenceMemo(x,y,n-1,m));
    }
}

int LongestCommonSubsequenceRecursive(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    
    if(x[n]==y[m]) {
        return 1 + LongestCommonSubsequenceRecursive(x,y,n-1,m-1);
    }
    else{
        return max(LongestCommonSubsequenceRecursive(x,y,n,m-1),LongestCommonSubsequenceRecursive(x,y,n-1,m));
    }
} 

int LongestCommonSubsequenceDP(string x,string y,int n,int m){
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
            if(x[i]==y[j]){
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
    string x = "abcdgh";
    string y = "abedfhr";
    int n = 6;
    int m = 7;
    memset(t,-1,sizeof(t));
    cout<<LongestCommonSubsequenceMemo(x,y,n,m)<<endl;
    cout<<LongestCommonSubsequenceRecursive(x,y,n,m)<<endl;
    cout<<LongestCommonSubsequenceDP(x,y,n,m)<<endl;
    return 0;
}