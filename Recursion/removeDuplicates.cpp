#include <bits/stdc++.h>
using namespace std;

int BinarySearch(string arr, int low, int high, char val)
{

    if (high >= low)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == val)
            return mid;
        if (val > arr[mid])
        {
            return BinarySearch(arr, mid + 1, high, val);
        }
        else
        {
            return BinarySearch(arr, low, mid - 1, val);
        }
    }

    return -1;
}

void removeDuplicates(string ans, string main)
{
    if (main == "\0")
    {
        cout << ans << endl;
        return;
    }
    char ch = main.at(0);
    if (BinarySearch(ans, 0, ans.size(), ch) == -1)
    {
        removeDuplicates(ans + ch, main.substr(1));
    }
    else
    {
        removeDuplicates(ans, main.substr(1));
    }
}

void removeDuplicatesgfg(char *S)
{
    if (S[0] == '\0')
    {
        return;
    }
    if (S[0] == S[1])
    {
        int i = 0;
        while (S[i] != '\0')
        {
            S[i] = S[i + 1];
            i++;
        }
        removeDuplicatesgfg(S);
    }
    removeDuplicatesgfg(S + 1);
}

int main()
{
    string s = "geeksforgeeks";
    removeDuplicatesgfg(&s[0]);
    cout << s;
    return 0;
}