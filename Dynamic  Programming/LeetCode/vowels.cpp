#include<bits/stdc++.h>
using namespace std;

class Solution {
    map<pair<int,char>,int> t;
    int solve(int n,int lastChar){
        if(n==0) return 1;
        if(t[{n,lastChar}]) return t[{n,lastChar}];
        int ans = 0;
        if(lastChar=='a'||lastChar=='p') ans += solve(n-1,'a') + solve(n-1,'e') + solve(n-1,'i') + solve(n-1,'o') + solve(n-1,'u'); 
        if(lastChar=='e') ans += solve(n-1,'e') + solve(n-1,'i') + solve(n-1,'o') + solve(n-1,'u'); 
        if(lastChar=='i') ans += solve(n-1,'i') + solve(n-1,'o') + solve(n-1,'u'); 
        if(lastChar=='o') ans += solve(n-1,'o') + solve(n-1,'u'); 
        if(lastChar=='u') ans += solve(n-1,'u'); 
        return t[{n,lastChar}] = ans;
    }
public:
    int countVowelStrings(int n) {
        return solve(n,'p');
    }
};

int main(){
    
    return 0;
}