#include <bits/stdc++.h>
using namespace std;

int getUnique(vector<int> arr)
{
    int ans = 0;
    for (int n : arr)
    {
        ans ^= n;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,1,3,3,4,5,5,2};
    // a XOR a will give 0
    // So the duplicate elements will be remove ans only the unique elements will be remaining
    cout<<getUnique(arr)<<endl;
    return 0;
}