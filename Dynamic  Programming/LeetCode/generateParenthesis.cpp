#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;
    void solve(int openingCount,int closingCount,int n,string currString){
        if(openingCount ==n && closingCount == n){
            ans.push_back(currString);
            return;
        }
        if(openingCount<n) solve(openingCount+1,closingCount,n,currString+'(');
        if(closingCount<openingCount) solve(openingCount,closingCount+1,n,currString+')');
    }
public:
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return ans;
    }
};

int main(){
    
    return 0;
}