#include <bits/stdc++.h>
using namespace std;

void subset(string ans, string main)
{
    if (main == "\0")
    {
        cout << ans << endl;
        return;
    }
    char ch = main.at(0);
    subset(ans + ch, main.substr(1));
    subset(ans, main.substr(1));
}

vector<string> returnsubset(string ans, string main)
{
    //when find subset add to list and return
    if (main == "\0")
    {
        vector<string> s;
        s.push_back(ans);
        return s;
    }
    char ch = main.at(0);
    // Find same thing in left half of stirng
    vector<string> left = returnsubset(ans + ch, main.substr(1));
    //Find same thing in right half of string
    vector<string> right = returnsubset(ans, main.substr(1));
    // Combine the both vectors and return them
    left.insert(left.begin(), right.begin(), right.end());
    return left;
}

int main()
{
    string s = "abc";
    // subset("",s);
    vector<string> ans = returnsubset("", s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}