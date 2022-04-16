#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       stack<pair<int,int>> s;
       for(int i=0;i<n;i++){
           int days = 1;
           while(!s.empty() && s.top().first <= price[i]){
               days += s.top().second;
               s.pop();
           }
           s.push(make_pair(price[i],days));
           ans.push_back(days);
       }
       return ans;
    }
};



int main(){
    
    return 0;
}