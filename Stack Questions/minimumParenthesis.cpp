#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') stack.push(s[i]);
            else if(s[i]==')'){
                if(stack.empty()) stack.push(s[i]);
                else if(stack.top()=='(') stack.pop();
                else stack.push(s[i]);
            }
        }
        return stack.size();
    }
};

int main(){
    
    return 0;
}