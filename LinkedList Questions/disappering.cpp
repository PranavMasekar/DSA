#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Not submitted (TLE)
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int maximum;
        vector<int> res;
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            int temp = nums[i];
            maximum = max(maximum, temp);
        }
        sort(nums.begin(),nums.end());
        maximum = max(maximum,length);
        int index = 0;
        for (int i = 1; i <=maximum; i++)
        {
            if(nums[index]==i){
                index++;
            }else{
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};

int main()
{

    return 0;
}