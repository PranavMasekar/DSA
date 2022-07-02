#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        ans[0].push_back(1);
        for(int i=1;i<=rowIndex;i++){
            ans[i].push_back(1);
            for(int j=1;j<i;j++){
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans[i].push_back(1);
        }
        return ans[rowIndex];
    }
};

int main(){
    
    return 0;
}