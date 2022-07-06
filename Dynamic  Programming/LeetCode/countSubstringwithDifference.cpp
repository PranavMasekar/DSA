#include <bits/stdc++.h>
using namespace std;


//! Not Complete
class Solution
{
    void getSubstrings(string s, vector<string> &ans, int n) {
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                string temp = "";
                for (int k = i; k <= j; k++)
                    temp += s[k];
                ans.push_back(temp);
            }
        }
    }
    int countFreq(string &pat, string &txt) {
        int M = pat.length();
        int N = txt.length();
        int res = 0;
        for (int i = 0; i <= N - M; i++)
        {
            int j;
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;
            if (j == M)
            {
                res++;
            }
        }
        return res;
    }
    int solve(vector<string> &substrings, string t, string substring, set<char> &alphabets) {
        if (t.find(substring) != string::npos)
            return countFreq(substring,t);
        int ans = 0;
        for (int i = 0; i < substring.size(); i++)
        {
            string temp = substring;
            for (char x : alphabets)
            {
                if(x==substring[i]) continue;
                substring[i] = x;
                ans += solve(substrings, t, substring, alphabets);
                substring = temp;   
            }
        }
        return ans;
    }

public:
    int countSubstrings(string s, string t)
    {
        vector<string> substrings;
        set<char> alphabets;
        for (auto x : t)
        {
            alphabets.insert(x);
        }
        getSubstrings(s, substrings, s.size());
        int ans = 0;
        for (int i = 0; i < substrings.size(); i++)
        {
            ans += solve(substrings, t, substrings[i], alphabets);
        }
        return ans;
    }
};

int main()
{

    return 0;
}