#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>mystack;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(mystack.size()>0)
                    ans+='(';
                mystack.push('(');
            }else
            {
                if(mystack.size()>1)
                    ans+=')';
                mystack.pop();
            }
            
        }
        return ans;
    }
};

int main(){
    
    return 0;
}