#include<bits/stdc++.h>
using namespace std;

class Solution {
    string LCP(string x,string y,int n,int m){
        int t[n + 1][m + 1];
        int ans = 0;
        string final_res = "";
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
                    // Checkging current common substring's length
                    if(t[i][j]>ans){
                        // if greater find the substring beglonging and check is it palindrome
                        string temp = x.substr(i-t[i][j],t[i][j]);
                        string rev = temp;
                        reverse(rev.begin(),rev.end());
                        if(temp==rev){
                            ans = t[i][j];
                            final_res = temp;
                        }
                    }
                }
                else{
                    t[i][j] = 0;
                }
            }
        }
        return final_res;
}
public:
    string longestPalindrome(string s) {
        string y = s;
        reverse(s.begin(),s.end());
        int n,m;
        n = m = s.size();
        return LCP(y,s,n,m);
    }
};

int main(){
    
    return 0;
}