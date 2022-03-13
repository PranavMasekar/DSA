#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int match(char a, char b)
    {
        if (a == '{' && b == '}')
        {
            return 1;
        }
        if (a == '[' && b == ']')
        {
            return 1;
        }
        if (a == '(' && b == ')')
        {
            return 1;
        }
        return 0;
    }

    bool isValid(string s)
    {
        stack<char> mystack;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                mystack.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (mystack.empty())
                {
                    return false;
                }
                char popped = mystack.top();
                mystack.pop();
                if (!match(popped, s[i]))
                {
                    return false;
                }
            }
        }
        if(mystack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{

    return 0;
}