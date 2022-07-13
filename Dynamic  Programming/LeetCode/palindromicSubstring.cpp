#include<bits/stdc++.h>
using namespace std;

class Solution {
    int t[1001][1001];
    int solve(int i,int j,string s){
        if(i>j) return 1;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i]==s[j]) return t[i][j] = solve(i+1,j-1,s);
        return t[i][j] = 0;
    }
public:
    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
        int count = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                count += solve(i,j,s);
            }
        }
        return count;
    }
};

int main(){
    
    return 0;
}