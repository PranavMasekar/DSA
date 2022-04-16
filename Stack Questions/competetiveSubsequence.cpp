#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        int remaining = n - k;
        for (int i = 0; i < n; i++)
        {
            while (!ans.empty() && nums[i]< ans.back() && remaining > 0)
            {
                ans.pop_back();
                remaining--;
            }
            ans.push_back(nums[i]);
        }
        return vector<int>(ans.begin(), ans.begin() + k);
    }
};

int main()
{

    return 0;
}