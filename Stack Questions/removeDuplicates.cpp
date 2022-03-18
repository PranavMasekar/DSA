#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (stack.empty())
            {
                stack.push(s[i]);
            }
            else
            {
                if (stack.top() == s[i])
                {
                    stack.pop();
                }
                else
                    stack.push(s[i]);
            }
        }
        string ans;
        while (!stack.empty())
        {
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}