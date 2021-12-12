#include <bits/stdc++.h>
using namespace std;

char reverse(char ch){
    if(ch =='(') return ')';
    else if(ch=='[') return ']';
    else return '}';
}

bool isMatch(string s , int n){
    if(n==0) return true;
    if(n==1) return false;
    if(s[0]==')' || s[0]==']' ||s[0]=='}' ) return false;
    char ch = reverse(s[0]);
    int count=0;
    int i;
    for(i=1;i<n;i++){
        if(s[i]==s[0]) count++;
        if(s[i]==ch){
            if(count==0) break;
        }
        count--;
    }
    if(i==n) return false;
    if(i==1) return isMatch(s.substr(2),n-2);
    // Incomplete recursion call 
 }

int main(){
    string s = "[()]{}{[()()]()}";
    cout<<isMatch(s,s.size()-1);

    return 0;
}