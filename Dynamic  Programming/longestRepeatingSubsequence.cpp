#include<bits/stdc++.h>
using namespace std;

int t[100][100];
int LongestRepeatingSubsequenceMemo(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    if (t[n][m] != -1) return t[n][m];
    if(x[n-1]==y[m-1] && n!=m) {
        return t[n][m] =  1 + LongestRepeatingSubsequenceMemo(x,y,n-1,m-1);
    }
    else{
        return t[n][m] =  max(LongestRepeatingSubsequenceMemo(x,y,n,m-1),LongestRepeatingSubsequenceMemo(x,y,n-1,m));
    }
}

int LongestRepeatingSubsequenceRecursive(string x,string y,int n,int m){
    if(n==0 || m==0) return 0;
    
    if(x[n-1]==y[m-1] && n!=m) {
        return 1 + LongestRepeatingSubsequenceRecursive(x,y,n-1,m-1);
    }
    else{
        return max(LongestRepeatingSubsequenceRecursive(x,y,n,m-1),LongestRepeatingSubsequenceRecursive(x,y,n-1,m));
    }
} 

int LongestRepeatingSubsequenceDP(string x,string y,int n,int m){
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
            if(x[i-1]==y[j-1] && i!=j){
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
    string x = "aabebcdd";
    int n = 8;
    memset(t,-1,sizeof(t));
    cout<<LongestRepeatingSubsequenceMemo(x,x,n,n)<<endl;
    cout<<LongestRepeatingSubsequenceRecursive(x,x,n,n)<<endl;
    cout<<LongestRepeatingSubsequenceDP(x,x,n,n)<<endl;
    return 0;
}